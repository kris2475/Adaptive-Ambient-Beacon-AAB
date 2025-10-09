# Adaptive Ambient Beacon (AAB) – Manual FM TX Prototyping

## Phase: Preliminary Manual FM Transmission Testing

This document outlines the **manual, preliminary testing procedure** for the ACBB system using the Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module (ASIN: B0762JM715) and the NESDR Smart SDR receiver with **CubicSDR**, prior to integrating the ESP32 and full sensor-driven automation. The goal is to validate the hypothesis that **subtle FM interference can trigger procedural dial-turning interactions** in ageing and dementia-friendly contexts.

Recent real-world testing confirmed that **a local FM transmitter can effectively override a nearby FM receiver**, providing immediate, perceivable interference. See **SDR.png** for a screenshot from CubicSDR showing the FM transmitter frequency stepping away from 97.1 MHz (station can be heard), then to 97.1 MHz, where it swamps the radio station reception. This serves as a strong validation of the ACBB physical-layer concept.

---

## Objective

- Test whether subtle FM interference can act as a **low-cognitive-load, procedural cue** for a user.  
- Validate that **manual frequency overrides** can immediately block or degrade reception from existing FM stations.  
- Ensure the interaction is **intuitive, perceivable, and non-startling**.  
- Gather insights for subsequent **sensor-driven automation with the ESP32 and Si4713 FM module**.  
- Use **CubicSDR and NESDR Smart** to **observe, measure, and quantify FM interference effects** for precise testing.  

---

## Equipment Needed

1. **FM Transmitter Module**: Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module (ASIN: B0762JM715)  
   - Frequency Range: 87.0 MHz to 108.0 MHz  
   - Power Supply: 3 V to 5 V DC  
   - Audio Input: LINE/USB (stereo), MIC (single channel)  
   - Emission Distance: Up to 100 metres (with 75 cm antenna on open ground)  
   - Modulation Mode: Standard FM  
   - Frequency Adjustment: 0.1 MHz per short press, 1.0 MHz per long press  
   - Equivalent Noise: ≥30 dB  
   - Current Consumption: 35 mA  

2. **Analogue FM Radio**: Preferably with a tuning dial for manual frequency adjustment.  

3. **NESDR Smart SDR Receiver**  
   - Connects to PC via USB.  
   - Supports spectrum visualisation and recording of FM signals.  

4. **CubicSDR Software**  
   - Multi-platform SDR software for real-time spectrum display.  
   - Enables precise observation of **frequency drift, modulation, and interference amplitude**.  

5. **Audio Source**  
   - LINE Input: Phone, MP3 player, or computer LINE-out.  
   - USB Input: Connect to computer for audio playback.

6. **Power Supply**: Battery or linear regulated 3–5 V DC (avoid switch-mode power supplies to prevent interference).

---

## Setup

1. **Select a Test Frequency**  
   - Choose an unused FM frequency (e.g., 97.1 MHz).  
   - Ensure the radio can tune to this frequency.

2. **Connect Audio Source to TX Module**  
   - Use LINE-IN or USB input depending on module configuration.  
   - Adjust volume to produce subtle, perceivable interference.

3. **Set Up the Analogue Radio / SDR Receiver**  
   - Tune the analogue radio or CubicSDR to the ACBB test frequency.  
   - Place in the intended listening location for the user.

4. **Initial Observation**  
   - With the TX module **silent or tuned to a slightly different frequency** (e.g., 97.2 MHz while SDR is at 97.1 MHz), observe normal reception.  
   - Document baseline audio clarity and spectrum.

---

## Procedure

### Manual FM Test

1. **Normal IAQ Simulation**  
   - Keep TX audio silent → radio receives no interference.  
   - Observe that no action is required on the tuning dial.

2. **Frequency Override Test (Real-World Validation)**  
   - Tune the FM transmitter to a nearby frequency (e.g., 97.2 MHz).  
   - Confirm SDR/analogue radio continues receiving the station normally at 97.1 MHz.  
   - Switch the transmitter frequency to **exactly match the radio (97.1 MHz)**.  
   - Observe immediate blocking of the broadcast music by interference/static.  
   - Refer to **SDR.png** for a visual representation of this effect.  
   - Document user-perceptible effect and confirm feedback loop concept.

3. **Simulated IAQ Deviation**  
   - Introduce subtle static/hiss/tone via TX module.  
   - Listen for **audible interference** on the radio.

4. **User Procedural Response**  
   - Turn the tuning dial slightly.  
   - Observe if interference is reduced → feedback loop confirmed.

5. **Acute Event Simulation**  
   - Increase modulation or volume of TX signal.  
   - Confirm whether the user reacts more quickly or decisively.

6. **Iterative Testing**  
   - Adjust distance, orientation, and volume to find optimal signal intensity.  
   - Record observations for later integration into automated ACBB system.

### SDR-Assisted Observation with CubicSDR

1. **Baseline Observation**  
   - With TX module silent, observe flat baseline spectrum on CubicSDR.

2. **Frequency Override Observation**  
   - Switch TX module to match SDR frequency → observe complete spectral takeover on SDR.  
   - Record amplitude, modulation, and interference pattern.  
   - See **SDR.png** for stepwise frequency effect.

3. **IAQ Deviation Simulation**  
   - Play subtle static / tone → watch SDR spectrum for signal presence and amplitude.  

4. **Frequency Drift Analysis**  
   - Adjust TX frequency slightly → observe signal shift in SDR.  
   - Determine perceptibility thresholds for interference.  

5. **Acute Event Simulation**  
   - Increase modulation / volume → confirm stronger interference pattern on SDR.  

6. **Data Logging**  
   - Record spectrum and amplitude data for analysis of **signal detectability and user perceptibility**.

---

## Observations to Record

- Perceptibility of interference on analogue radio.  
- Immediate effect of exact-frequency override on SDR/audio (**see SDR.png**).  
- Intuitiveness of dial-turning action.  
- Effectiveness of subtle vs. stronger signals.  
- Response time and confidence in procedural action.  
- SDR spectrum amplitude, frequency drift, and modulation effects.

---

## Notes

- This is a **preliminary manual test phase**; no ESP32 automation is used.  
- The mini FM module **cannot override licensed FM stations** (e.g., BBC Radio 4) beyond very local distances.  
- CubicSDR + NESDR Smart allows **quantitative analysis** to refine modulation patterns and static levels.  
- Your real-world test confirms that **a local FM transmitter can effectively block nearby reception**, validating the ACBB concept.  
- Purpose: validate **the procedural feedback concept** before full ACBB integration.

- For more information, you can visit the product page on Amazon UK: [Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module](https://www.amazon.co.uk/dp/B0762JM715?ref=ppx_yo2ov_dt_b_fed_asin_title).  



- For more information, you can visit the product page on Amazon UK: [Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module](https://www.amazon.co.uk/dp/B0762JM715?ref=ppx_yo2ov_dt_b_fed_asin_title).

---



