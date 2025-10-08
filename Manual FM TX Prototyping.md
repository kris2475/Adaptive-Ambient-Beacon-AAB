# Adaptive Contextual Biometric Beacon (ACBB) – Manual FM TX Prototyping

## Phase: Preliminary Manual FM Transmission Testing

This document outlines the **manual, preliminary testing procedure** for the ACBB system using the Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module (ASIN: B0762JM715) and the NESDR Smart SDR receiver, prior to integrating the ESP32 and full sensor-driven automation. The goal is to validate the hypothesis that **subtle FM interference can trigger procedural dial-turning interactions** in ageing and dementia-friendly contexts.

---

## Objective

- Test whether subtle FM interference can act as a **low-cognitive-load, procedural cue** for a user.
- Ensure the interaction is **intuitive, perceivable, and non-startling**.
- Gather insights for subsequent **sensor-driven automation with the ESP32 and Si4713 FM module**.
- Use SDR tools to **observe, measure, and quantify FM interference effects** for more precise testing.

---

## Equipment Needed

1. **FM Transmitter Module**: Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module (ASIN: B0762JM715)  
   - Frequency Range: 87.0MHz to 108.0MHz  
   - Power Supply: 3V to 5V DC  
   - Audio Input: LINE/USB (stereo), MIC (single channel)  
   - Emission Distance: Up to 100 meters (with 75cm antenna on open ground)  
   - Modulation Mode: Standard FM  
   - Frequency Adjustment: 0.1MHz per short press, 1.0MHz per long press  
   - Equivalent Noise: ≥30dB  
   - Current Consumption: 35mA  

2. **Analog FM Radio**: Preferably with a tuning dial for manual frequency adjustment.  

3. **NESDR Smart SDR Receiver**  
   - Connects to PC via USB.  
   - Allows spectrum visualization and recording of FM signals.  
   - Supports precise observation of interference and frequency drift.  

4. **Audio Source**  
   - LINE Input: Phone, MP3 player, or computer LINE-out.  
   - USB Input: Connect to computer for audio playback.

5. **Power Supply**: Battery or linear regulated 3–5V DC (avoid switch-mode power supplies to prevent interference).

---

## Setup

1. **Select a Test Frequency**  
   - Choose an unused FM frequency (e.g., 87.9 MHz).  
   - Ensure the radio can tune to this frequency.

2. **Connect Audio Source to TX Module**  
   - Use LINE-IN or USB input depending on module configuration.  
   - Adjust volume to produce subtle, perceivable interference.

3. **Set Up the Radio**  
   - Tune to the ACBB test frequency.  
   - Place in the intended listening location for the user.

4. **Set Up NESDR Smart SDR Receiver**  
   - Connect to PC and open SDR software (e.g., SDR#).  
   - Tune to the same test frequency.  
   - Verify baseline spectrum with TX module silent.

---

## Procedure

### Manual FM Test

1. **Normal IAQ Simulation**  
   - Keep TX audio silent → radio receives no interference.  
   - Observe that no action is required on the tuning dial.

2. **Simulated IAQ Deviation**  
   - Start subtle static/hiss/tone via TX module.  
   - Listen for **audible interference** on the radio.

3. **User Procedural Response**  
   - Turn the tuning dial slightly.  
   - Observe if interference is reduced → feedback loop confirmed.

4. **Acute Event Simulation**  
   - Increase modulation or volume of TX signal.  
   - Confirm whether the user reacts more quickly or decisively.

5. **Iterative Testing**  
   - Adjust distance, orientation, and volume to find optimal signal intensity.  
   - Record observations for later integration into automated ACBB system.

### SDR-Assisted Observation

1. **Baseline Observation**  
   - With TX module silent, observe flat baseline spectrum on SDR software.

2. **IAQ Deviation Simulation**  
   - Play subtle static / tone → watch SDR spectrum for signal presence and amplitude.  

3. **Frequency Drift Analysis**  
   - Adjust TX frequency slightly → observe signal shift in SDR.  
   - Determine perceptibility thresholds for interference.  

4. **Acute Event Simulation**  
   - Increase modulation / volume → confirm stronger interference pattern on SDR.  

5. **Data Logging**  
   - Record spectrum and amplitude data for analysis of **signal detectability and user perceptibility**.

---

## Observations to Record

- Perceptibility of interference on analog radio.  
- Intuitiveness of dial-turning action.  
- Effectiveness of subtle vs. stronger signals.  
- Response time and confidence in procedural action.  
- SDR spectrum amplitude, frequency drift, and modulation effects.

---

## Notes

- This is a **preliminary manual test phase**; no ESP32 automation is used.  
- The mini FM module **cannot override licensed FM stations** (e.g., BBC Radio 4).  
- NESDR Smart allows **quantitative analysis** to refine modulation patterns and static levels.  
- Purpose: validate **the procedural feedback concept** before full ACBB integration.

- For more information, you can visit the product page on Amazon UK: [Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module](https://www.amazon.co.uk/dp/B0762JM715?ref=ppx_yo2ov_dt_b_fed_asin_title).

---



