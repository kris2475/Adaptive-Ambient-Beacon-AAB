# The Adaptive Contextual Biometric Beacon (ACBB)
## 📖 Overview
The **Adaptive Contextual Biometric Beacon (ACBB)** is an **ambient intelligence system** designed to enhance safety and quality of life for **ageing populations** and individuals with **cognitive or sensory decline**. Unlike traditional smart home technologies, the ACBB **repurposes the analogue FM radio** into an unobtrusive, tangible environmental monitor, providing **auditory and kinesthetic cues** without digital complexity. Recent real-world testing demonstrated that a **local FM transmitter can override a nearby radio reception**: tuning a software-defined radio (SDR) to 97.1 MHz and switching a transmitter from 97.2 MHz to 97.1 MHz immediately blocked the station, creating static—confirming the ACBB principle works in practice (see SDR.png).

The ACBB monitors environmental conditions using a **predictive algorithm** tracking Indoor Air Quality (**IAQ**), Volatile Organic Compounds (**VOCs**), and micro-climate variations. It communicates via subtle, physical feedback channels: **frequency drift** (slow static for chronic IAQ degradation) and **tone modulation** (erratic sound for acute fume spikes). The **Tangible User Interface (TUI)** requires interacting with the radio tuning dial, providing a **low-cognitive-load procedural cue**, **non-visual feedback**, and **safer ageing in place**.

## ⚡ Executive Summary
The ACBB is designed to bridge the digital divide for elderly and cognitively impaired users by providing environmental feedback through **physical and auditory channels** rather than screens or apps. It leverages **muscle memory and procedural cognition**, making it intuitive even for those with memory impairment. Layered feedback is structured as follows:

| Layer | Type | Mechanism & User Action | Benefit |
|-------|------|------------------------|---------|
| 1: Frequency Drift | Chronic IAQ | Slow drift toward radio frequency → static noise; user tunes dial slightly | Tangible awareness of poor air quality |
| 2: Tone Modulation | Acute Fumes | Erratic tone overlays station → noticeable interference | Immediate alert for sudden hazards |
| 3: Adaptive Baseline | Contextual Prediction | Personalized IAQ baseline; signals only when deviations occur | Reduces alert fatigue |
| 4: User Agency | Comfort Calibration | User may press a button to reset baseline | Preserves autonomy |

### Benefits for Dementia Care
- **Procedural Memory Activation:** Uses familiar dial-turning instead of cognitive reasoning.  
- **Mitigates Executive Dysfunction:** Simple physical action replaces complex decision-making.  
- **Reduces Anxiety:** Subtle static is less startling than loud alarms.  
- **Simplifies Crisis Response:** Hazard translated into *“Sound is unpleasant → I must adjust dial.”*

## 🎓 Academic Context
The ACBB aligns with **HCI and Ambient Assisted Living** principles:
- **Tangible User Interfaces (TUI):** Converts invisible environmental data into a **physical artefact** (radio + dial).  
- **Ambient Displays:** Provides predictive environmental data unobtrusively.  
- **Novelty:** Subverts FM technology; carrier drift becomes an intuitive environmental index, and **physical interaction ensures feedback is memorable**.

## ⚙️ Technical System
| Component | Role | Mechanism |
|-----------|------|-----------|
| Sensor Suite | Data acquisition & prediction | Multi-gas sensor (e.g., BME680) monitors IAQ, VOCs, temperature, humidity, and feeds adaptive baseline algorithm. |
| Microcontroller (ESP32) | Logic & signal generation | Processes sensor data, calculates deviations, runs predictive baseline algorithm, generates frequency/tone commands. |
| FM Transmitter (SI4713) | Output actuator | Low-power transmission of frequency drift or tone modulation to nearby radios. |
| Analogue FM Radio | Tangible User Interface | Receives broadcast; static/interference prompts dial-turning. Turning the dial slightly moves the receiver out of the interference zone, restoring partial or full clarity and confirming user attention. |

> **Important:** Turning the dial does **not override the broadcast**; it moves the receiver out of the strongest local interference, restoring clarity and creating a **procedural cue**.

## 🏠 Practical Operation Scenario
1. **Normal Operation:** Radio tuned to 97.1 MHz, ACBB transmitter inactive or slightly off-frequency.  
2. **Environmental Change:** Sensors detect IAQ deviation; ESP32 calculates severity.  
3. **Frequency Drift / Interference:** Chronic deviations → slow drift with static; acute deviations → low-power interference or erratic tone.  
4. **User Response:** Turning the dial moves radio out of interference → clarity partially restored, confirming attention.  
5. **Feedback Loop:** ACBB logs interaction, adjusts future drift thresholds for optimal sensitivity.

**Conceptual Flow Diagram:**
[IAQ / VOC Sensors]
↓
[ESP32 MCU] — calculates deviation & severity
↓
[FM Transmitter] — frequency drift / modulation
↓
[User’s Analogue FM Radio] ← static/interference cue
↓
[User Action: Turns Dial] — partial clarity restored → procedural feedback confirmed


## ✅ Key Points
- Local, low-power transmission affects **only nearby radios**.  
- Turning the dial **restores clarity by moving the receiver out of interference zone**.  
- Feedback is **auditory, tangible, low-cognitive-load**, leveraging **procedural memory**.  
- Frequency drift and tone modulation differentiate **chronic vs. acute events**.  
- **SDR Testing:** Real-world experiments confirm FM transmitter can override reception as designed (see SDR.png).

## 🗂 Table of Contents
- Overview  
- Executive Summary  
- Benefits for Dementia Care  
- Academic Context  
- Technical System  
- Practical Operation Scenario  
- Key Points

