/*
 * ESP32 FM Humidity Interference Beacon (Configurable - DFRobot Library)
 * * FINAL VERSION: Confirmed working address is 0x63.
 * * CRITICAL UPDATE: Switched to the Digital DHT11 and adapted code for the
 * * DFRobot_DHT11 library syntax as requested.
 * * The sensor is connected to GPIO 33.
 * * FIX: The DFRobot_DHT11 library version installed returns 'void' from read().
 * Removed 'int check =' assignment to resolve "void value not ignored" error.
 * * CRITICAL FIX: Explicitly managing SI4713_RESET_PIN (GPIO 27) in setup()
 * to ensure a successful hard reset before fmTransmitter.begin().
 * * FIX: Reduced baseline readings from 10 to 3 for faster startup and stability.
 * * FIX: Increased MEASUREMENT_INTERVAL_MS from 5s to 10s to give the DHT11's 
 * temperature element more time to settle and prevent the stuck 25.0C reading.
 */

#include <Wire.h>
#include <Adafruit_Si4713.h> 
#include <DFRobot_DHT11.h> // *** NEW LIBRARY: Using DFRobot_DHT11.h now ***

// =======================================================================
// ⚙️ USER CONFIGURATION
// =======================================================================

// --- RADIO CONFIGURATION ---
// Target frequency of the station to interfere with (in 10 kHz increments: 9710 = 97.10 MHz)
const unsigned int TARGET_FREQ_KHZ = 9710; 

// Starting frequency when the radio first turns on (must be > TARGET_FREQ_KHZ)
const unsigned int START_FREQ_KHZ = 9750;

// TX Power Level (0 to 115 max). 115 is highest power.
const int RADIO_POWER_LEVEL = 115; 

// Frequency Shift Increment: How much the frequency shifts per humidity step 
const int FREQ_INCREMENT_KHZ = 2; // e.g., 2 = 20 kHz per step

// --- HUMIDITY CONFIGURATION (USING PERCENTAGE 0.0 - 100.0) ---
// Percentage delta (positive) required to turn the radio ON 
const float MIN_DELTA_TO_ACTIVATE = 2.0; 

// Percentage delta (positive) at which the 1000 Hz sine wave tone will start transmitting
const float TONE_ALARM_THRESHOLD = 20.0;

// Defines the number of frequency steps between the START_FREQ and the TARGET_FREQ.
const int NUM_FREQ_STEPS = (START_FREQ_KHZ - TARGET_FREQ_KHZ) / FREQ_INCREMENT_KHZ; 

// =======================================================================
// 📌 HARDWARE CONFIGURATION
// =======================================================================
const int SI4713_SDA = 21; // ESP32 I2C SDA
const int SI4713_SCL = 22; // ESP32 I2C SCL
// DHT11 is digital. It is connected to GPIO 33.
const int DHT_PIN = 33; 
const int SI4713_RESET_PIN = 27; // Reset pin for SI4713
const long MEASUREMENT_INTERVAL_MS = 10000; // Measure humidity every 10 seconds (Increased for DHT11 stability)

// --- State Variables & Objects ---
float baselineHumidity = 0.0;
bool radioIsOn = false;
bool toneIsOn = false;
unsigned long lastMeasureTime = 0;

// Initialize the Si4713 and DHT objects
Adafruit_Si4713 fmTransmitter = Adafruit_Si4713(SI4713_RESET_PIN);
// DFRobot library initialization (no pin needed here, only in read() call)
DFRobot_DHT11 dht; 

// --- Component Enable Values (from Adafruit_Si4713.h) ---
const uint16_t TONE_ON_VALUE = 0x0007; 
const uint16_t TONE_OFF_VALUE = 0x0003; 

// --- Forward Declarations ---
float readHumidity();
void setTransmitterFrequency(unsigned int freq);
void setTone(bool on);

// =======================================================================
// SETUP
// =======================================================================
void setup() {
  // NOTE: Changed Serial.begin(1151) to Serial.begin(115200) - 1151 is not a standard baud rate
  Serial.begin(115200);
  delay(100);
  
  // Set up I2C for SI4713
  Wire.begin(SI4713_SDA, SI4713_SCL);

  // --- EXPLICIT RESET PIN MANAGEMENT ---
  // Ensure the reset pin is an output and held high (inactive)
  pinMode(SI4713_RESET_PIN, OUTPUT);
  digitalWrite(SI4713_RESET_PIN, HIGH);
  delay(10); 
  
  // Perform a manual hard reset: Pull LOW, wait, then pull HIGH
  Serial.println("Performing explicit hard reset on Si4713...");
  digitalWrite(SI4713_RESET_PIN, LOW);
  delay(10); // Hold low for a short time
  digitalWrite(SI4713_RESET_PIN, HIGH);
  delay(100); // Wait for the chip to boot after reset

  // Initialize SI4713 with the confirmed default I2C address 0x63.
  if (!fmTransmitter.begin()) { 
    Serial.println("SI4713 failed to start at 0x63. Check wiring and power (especially the Reset Pin!).");
    while(1); 
  }

  // DFRobot_DHT11 does not require a dht.begin() call in setup!
  Serial.printf("DHT11 sensor initialized (using DFRobot Library) on GPIO %d.\n", DHT_PIN);

  // Debug output
  Serial.println("\n--- FM HUMIDITY BEACON STARTUP ---");
  Serial.println("SI4713 successfully initialized at I2C address 0x63!");
  Serial.printf("Target Freq: %.2f MHz | Start Freq: %.2f MHz\n", (float)TARGET_FREQ_KHZ/100.0, (float)START_FREQ_KHZ/100.0);
  
  // --- Initial Baseline Measurement ---
  // Reduced to 3 readings. ***IMPORTANT: DO NOT breathe on the sensor during this time!***
  Serial.print("Establishing baseline humidity (waiting for 3 stable readings)...");
  int readings = 0;
  const int NUM_BASELINE_READINGS = 3;
  while (readings < NUM_BASELINE_READINGS) {
    float h = readHumidity();
    // Check if reading is valid (DHT returns NaN for bad readings)
    if (!isnan(h)) {
      baselineHumidity += h;
      readings++;
    }
    delay(1000); // Wait 1 second between readings
  }
  baselineHumidity /= (float)NUM_BASELINE_READINGS; // Use float cast for accurate division
  Serial.printf(" Baseline established: %.1f%%\n", baselineHumidity);

  // Initial state setup 
  fmTransmitter.setTXpower(0); // Ensure low power initially
  fmTransmitter.tuneFM(START_FREQ_KHZ); 
  
  // Ensure tone is off at startup
  setTone(false);

  radioIsOn = false;
  toneIsOn = false;
  lastMeasureTime = millis();
}

// =======================================================================
// LOOP - Main Control Logic
// =======================================================================
void loop() {
  if (millis() - lastMeasureTime >= MEASUREMENT_INTERVAL_MS) {
    lastMeasureTime = millis();
    
    // Read the current humidity (0.0 - 100.0)
    float currentHumidity = readHumidity();

    // Skip update if the reading is invalid (DHT error)
    if (isnan(currentHumidity)) {
        Serial.println("DHT11 reading failed. Retrying next interval.");
        return;
    }

    float deltaHumidity = currentHumidity - baselineHumidity;
    float absDeltaHumidity = abs(deltaHumidity);
    
    Serial.printf("Current H: %.1f%% | Baseline H: %.1f%% | Delta: %.1f%%\n", currentHumidity, baselineHumidity, deltaHumidity);

    // --- DECISION POINT 1: Radio ON/OFF ---
    if (absDeltaHumidity < MIN_DELTA_TO_ACTIVATE) {
      // Deviation is low: Turn radio OFF
      if (radioIsOn) {
        setTone(false); 
        fmTransmitter.setTXpower(0); 
        radioIsOn = false;
        Serial.println("Delta is LOW. Radio TX OFF.");
      }
      return; 
    }
    
    // Deviation is significant: Radio TX must be ON
    if (!radioIsOn) {
      fmTransmitter.setTXpower(RADIO_POWER_LEVEL); 
      radioIsOn = true;
      Serial.println("Significant Delta detected. Radio TX ON.");
    }
    
    // --- DECISION POINT 2: Frequency and Tone Logic ---
    unsigned int newFreq = START_FREQ_KHZ;
    
    if (deltaHumidity > 0) {
      // --- POSITIVE DELTA (Interference shifts TOWARDS target) ---
      
      // Calculate steps based on the PERCENTAGE delta
      int stepsTowardsTarget = (int)(deltaHumidity / MIN_DELTA_TO_ACTIVATE);
      if (stepsTowardsTarget > NUM_FREQ_STEPS) {
          stepsTowardsTarget = NUM_FREQ_STEPS;
      }
      
      newFreq = START_FREQ_KHZ - (stepsTowardsTarget * FREQ_INCREMENT_KHZ);
      
      if (newFreq < TARGET_FREQ_KHZ) newFreq = TARGET_FREQ_KHZ;

      setTransmitterFrequency(newFreq);
      
      // --- TONE ALARM TRIGGER ---
      if (deltaHumidity > TONE_ALARM_THRESHOLD) {
        Serial.println("!!! HIGH HUMIDITY ALARM: Transmitting 1000 Hz Tone !!!");
        setTone(true);
      } else {
        setTone(false);
      }
      
    } else {
      // --- NEGATIVE DELTA (Interference shifts AWAY from target) ---
      newFreq = START_FREQ_KHZ; 
      
      setTransmitterFrequency(newFreq);
      setTone(false); // Ensure tone is off
    }
  }
}

// =======================================================================
// UTILITY FUNCTIONS
// =======================================================================

// Function to read the humidity from the DHT11 sensor
float readHumidity() {
  // DFRobot library uses read(pin) to get data, but the installed version
  // appears to return 'void'. We must call it without assignment.
  dht.read(DHT_PIN); 

  // Data is stored in the dht object's public members:
  float h = dht.humidity;
  float t = dht.temperature;

  // Since we cannot check a status code, we use a basic sanity check:
  // DHT11 should never return 0.0 unless it failed completely.
  if (h == 0.0) {
    // Print an error message since a status code is unavailable
    Serial.println("[DEBUG H] DHT Read Failed. Humidity reported 0.0 or failed to update.");
    return NAN; 
  }
  
  // Ensure the reading is within sensible bounds
  if (h < 0.0) h = 0.0;
  if (h > 100.0) h = 100.0;

  Serial.printf("[DEBUG H] DHT Read: Humidity=%.1f%%, Temp=%.1fC\n", h, t);
  
  return h;
}

// Function to set the transmitter frequency
void setTransmitterFrequency(unsigned int freq) {
  fmTransmitter.tuneFM(freq); 
  Serial.printf("Tuned to: %.2f MHz\n", (float)freq / 100.0);
}

// Function to turn the 1000 Hz sine tone ON or OFF
void setTone(bool on) {
  if (on && !toneIsOn) {
    // Enable RDS, Stereo, and Tone using the low-level property
    fmTransmitter.setProperty(SI4713_PROP_TX_COMPONENT_ENABLE, TONE_ON_VALUE); 
    toneIsOn = true;
    Serial.println("Tone ON: 1000 Hz (via setProperty)");
  } else if (!on && toneIsOn) {
    // Disable Tone (revert to Pilot and L-R enabled)
    fmTransmitter.setProperty(SI4713_PROP_TX_COMPONENT_ENABLE, TONE_OFF_VALUE); 
    toneIsOn = false;
    Serial.println("Tone OFF (via setProperty)");
  }
}














