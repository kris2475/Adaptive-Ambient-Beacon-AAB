# Adaptive Contextual Biometric Beacon (ACBB) – Manual FM TX Prototyping

## Phase: Preliminary Manual FM Transmission Testing

This document outlines the **manual, preliminary testing procedure** for the ACBB system using the Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module (ASIN: B0762JM715), prior to integrating the ESP32 and full sensor-driven automation. The goal is to validate the hypothesis that **subtle FM interference can trigger procedural dial-turning interactions** in ageing and dementia-friendly contexts.

---

## Objective

- Test whether subtle FM interference can act as a **low-cognitive-load, procedural cue** for a user.
- Ensure the interaction is **intuitive, perceivable, and non-startling**.
- Gather insights for subsequent **sensor-driven automation with the ESP32 and Si4713 FM module**.

---

## Equipment Needed

1. **FM Transmitter Module**: Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module (ASIN: B0762JM715)  
   - **Frequency Range**: 87.0MHz to 108.0MHz  
   - **Power Supply**: 3V to 5V DC  
   - **Audio Input**: LINE/USB (stereo), MIC (single channel)  
   - **Emission Distance**: Up to 100 meters (with 75cm antenna on open ground)  
   - **Modulation Mode**: Standard FM  
   - **Frequency Adjustment**: 0.1MHz per short press, 1.0MHz per long press  
   - **Equivalent Noise**: ≥30dB  
   - **Current Consumption**: 35mA  

2. **Analog FM Radio**: Preferably with a tuning dial for manual frequency adjustment.

3. **Audio Source**:  
   - **LINE Input**: Phone, MP3 player, or computer LINE-out.  
   - **USB Input**: Connect to a computer for audio playback.

4. **Power Supply**: Battery or linear regulated 3–5V DC (avoid switch-mode power supplies to prevent interference).

---

## Setup

1. **Select a Test Frequency**  
   - Choose an unused FM frequency (e.g., 87.9MHz).  
   - Ensure the radio can tune to this frequency.

2. **Connect Audio Source to TX Module**  
   - Use LINE-IN or USB input depending on module configuration.  
   - Adjust volume to produce subtle, perceivable interference.

3. **Set Up the Radio**  
   - Tune to the ACBB test frequency.  
   - Place in the intended listening location for the user.

---

## Procedure

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

---

## Observations to Record

- Perceptibility of interference.  
- Intuitiveness of dial-turning action.  
- Effectiveness of subtle vs. stronger signals.  
- Response time and confidence in procedural action.

---

## Notes

- This is a **preliminary manual test phase**; no ESP32 automation is used.  
- The mini FM module **cannot override licensed FM stations** (e.g., BBC Radio 4).  
- Purpose: validate **the procedural feedback concept** before full ACBB integration.

---

## FM Transmitter Module Overview

The Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module (ASIN: B0762JM715) is a compact and versatile FM transmitter suitable for various applications, including testing the ACBB hypothesis. Below are its key specifications:

- **Frequency Range**: 87.0MHz to 108.0MHz  
- **Power Supply**: 3V to 5V DC  
- **Audio Input**: LINE/USB (stereo), MIC (single channel)  
- **Emission Distance**: Up to 100 meters (with 75cm antenna on open ground)  
- **Modulation Mode**: Standard FM  
- **Frequency Adjustment**: 0.1MHz per short press, 1.0MHz per long press  
- **Equivalent Noise**: ≥30dB  
- **Current Consumption**: 35mA  

For more information, you can visit the product page on Amazon UK: [Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module](https://www.amazon.co.uk/dp/B0762JM715?ref=ppx_yo2ov_dt_b_fed_asin_title).


