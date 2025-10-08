/*
  ACBB_ESP32_FM_BME680.ino
  ------------------------------------------------------------
  Adaptive Contextual Biometric Beacon (ACBB) on ESP32
  ------------------------------------------------------------
  Concept: K. Seunarine
  Implementation Example

  DESCRIPTION:
  - This sketch implements the Adaptive Contextual Biometric Beacon
    using an ESP32, Adafruit BME680 sensor, and Adafruit Si4713 FM transmitter.
  - The system provides ambient, non-visual feedback for environmental
    monitoring, designed for ageing populations and cognitive accessibility.

  FUNCTIONALITY:
  1. Reads IAQ, VOCs, temperature, humidity from BME680.
  2. Layer 1: Frequency drift of FM transmission indicates chronic IAQ decline.
  3. Layer 2: Tone modulation signals acute spikes in fumes or VOCs.
  4. Layer 3: Predictive baseline adapts slowly to each environment
     using an Exponential Moving Average (EMA).
  5. Layer 4: Manual comfort reset button allows user to redefine their baseline.

  HARDWARE:
  - ESP32 development board
  - Adafruit BME680 air quality sensor (I2C)
  - Adafruit Si4713 FM Transmitter breakout (I2C + RST)
  - Button for manual comfort baseline reset
  - FM radio as user interface (tuning dial interaction)

  PINS (ESP32):
  - SI4713_RESET: GPIO4
  - BUTTON_PIN:   GPIO15 (active LOW)
  - AUDIO_LEFT:   GPIO25 (DAC1)
  - AUDIO_RIGHT:  GPIO26 (DAC2)

  DEPENDENCIES:
  - Adafruit_Si4713 library
  - Adafruit_BME680 library
  - Adafruit_Sensor library
*/

#include <Wire.h>
#include <Adafruit_Si4713.h>   // ✅ Corrected include (was Adafruit_SI4713.h before)
#include <Adafruit_BME680.h>

// ----------------------- Pin Config -----------------------
#define SI4713_RESET 4
#define BUTTON_PIN   15   // comfort baseline reset button

// ----------------------- Objects --------------------------
Adafruit_Si4713 radio = Adafruit_Si4713(SI4713_RESET);
Adafruit_BME680 bme;

// ----------------------- FM Settings ----------------------
float baseFreq = 101.1;   // MHz, center broadcast frequency
float comfortIAQ = 100.0; // adaptive baseline IAQ
float driftScale = 0.05;  // Hz per IAQ deviation unit
uint16_t txPower = 115;   // dBuV output power

// ----------------------- Tone Settings --------------------
#define AUDIO_LEFT  25   // DAC1 on ESP32
#define AUDIO_RIGHT 26   // DAC2 on ESP32
float toneFrequency = 440;  // Hz
float toneAmplitude = 127;  // DAC midpoint amplitude

// ----------------------- State ----------------------------
unsigned long lastToneUpdate = 0;
unsigned long toneInterval = 200; // ms update interval
float alpha = 0.001; // EMA smoothing factor for baseline adaptation

// ----------------------- Setup ----------------------------
void setup() {
  Serial.begin(115200);
  delay(1000);

  // Init button
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Init I2C
  Wire.begin();

  // Init FM transmitter
  if (!radio.begin()) {
    Serial.println("SI4713 not found. Check wiring!");
    while (1);
  }
  Serial.println("SI4713 found.");

  radio.setTXpower(txPower);
  radio.tuneFM(baseFreq * 100); // in 10 kHz units

  // Init BME680
  if (!bme.begin()) {
    Serial.println("Could not find BME680 sensor. Check wiring!");
    while (1);
  }
  Serial.println("BME680 found.");

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // Temp, duration ms
}

// ----------------------- Loop -----------------------------
void loop() {
  // Sensor read
  if (!bme.performReading()) {
    Serial.println("BME680 read failed!");
    return;
  }

  // crude IAQ proxy (gas resistance kΩ)
  float iaq = bme.gas_resistance / 1000.0; 
  float temp = bme.temperature;
  float hum  = bme.humidity;

  Serial.printf("IAQ proxy=%.2f kΩ, Temp=%.2f °C, Hum=%.2f %%\n", iaq, temp, hum);

  // Button press → manual reset of baseline
  if (digitalRead(BUTTON_PIN) == LOW) {
    comfortIAQ = iaq;
    Serial.printf("Comfort baseline manually reset to: %.2f kΩ\n", comfortIAQ);
    delay(500);
  }

  // Layer 3: Adaptive Baseline (EMA filter)
  comfortIAQ = (alpha * iaq) + ((1 - alpha) * comfortIAQ);

  // Layer 1: Frequency Drift (chronic IAQ change)
  float deviation = iaq - comfortIAQ;
  float newFreq = baseFreq + (deviation * driftScale) / 1000.0; // MHz drift
  radio.tuneFM(newFreq * 100);
  Serial.printf("Baseline=%.2f kΩ, Drifted Frequency: %.4f MHz\n", comfortIAQ, newFreq);

  // Layer 2: Tone Modulation (acute fume spikes)
  unsigned long now = millis();
  if (now - lastToneUpdate > toneInterval) {
    lastToneUpdate = now;

    if (iaq > comfortIAQ * 1.5) { 
      // acute warning → erratic modulation
      toneFrequency = random(200, 1000);
      toneAmplitude = random(80, 180);
      toneInterval = 100; 
    } else {
      // stable → calm tone
      toneFrequency = 440;
      toneAmplitude = 127;
      toneInterval = 500;
    }

    generateTone(toneFrequency, toneAmplitude);
  }

  delay(200);
}

// ----------------------- DAC Tone Generator -------------------------
void generateTone(float freq, float amplitude) {
  int period = 1000000 / freq; // microseconds
  int halfPeriod = period / 2;

  for (int i = 0; i < 10; i++) { // generate short bursts
    dacWrite(AUDIO_LEFT, amplitude);
    dacWrite(AUDIO_RIGHT, amplitude);
    delayMicroseconds(halfPeriod);
    dacWrite(AUDIO_LEFT, 0);
    dacWrite(AUDIO_RIGHT, 0);
    delayMicroseconds(halfPeriod);
  }
}

