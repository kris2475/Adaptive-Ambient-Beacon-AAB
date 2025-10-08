# The Adaptive Contextual Biometric Beacon (ACBB)

## 📖 Overview
The **Adaptive Contextual Biometric Beacon (ACBB)** is an **ambient intelligence system** designed to enhance safety and quality of life for **ageing populations** and individuals with **cognitive or sensory decline**. At its core, the ACBB builds on something familiar to many elderly users: their **analogue FM radio**.  

Imagine Mrs Jones, who enjoys listening to her favourite FM station. She uses a simple, traditional radio and is accustomed to tuning the dial. The ACBB introduces subtle, intuitive feedback into this familiar environment. When something in her immediate environment changes—such as an increase in indoor pollutants, VOCs, or other hazards—these events are detected by the ACBB’s **sensor suite** (e.g., BME680 or equivalent gas sensors). The system continuously monitors the environment and calculates the severity of deviations relative to an **adaptive baseline**.

Once a deviation is detected, the ACBB responds by transmitting a **low-power FM signal**. This signal interacts with the analogue radio: it creates **audible static or subtle interference**, overlaying the station Mrs Jones is listening to. The interference is intentionally **perceptible but non-startling**, designed to alert her without causing distress. The radio station itself continues to broadcast normally, but the **local ACBB transmission introduces a perceptible cue**.

The **crucial interaction** comes from the user: Mrs Jones responds to the interference by **turning the radio’s tuning dial**. Because analogue radios have finite frequency selectivity, small adjustments move the receiver away from the strongest local interference, **partially or fully restoring clarity** of the station. This physical interaction serves as a **low-cognitive-load, procedural confirmation** that she has noticed the environmental event. By leveraging **procedural memory and familiar physical interaction**, the ACBB provides an intuitive, non-digital alert mechanism suitable for users with cognitive or sensory decline.

From this foundation, the rest of the system operates as described: chronic environmental deviations are signaled via **slow frequency drift**, acute events via **erratic tone modulation**, and all actions are logged by the microcontroller (ESP32) to refine future alerts. The design ensures the ACBB is **tangible, non-visual, low-cognitive-load, and integrates seamlessly into a familiar daily activity**: listening to the radio.

---

## ⚡ Executive Summary
The ACBB bridges the digital divide for elderly and cognitively impaired users by providing environmental feedback through **physical and auditory channels** rather than screens or apps. It leverages **muscle memory and procedural cognition**, making alerts intuitive and easy to respond to.

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

---

## 🎓 Academic Context
The ACBB aligns with **HCI and Ambient Assisted Living** principles:
- **Tangible User Interfaces (TUI):** Converts invisible environmental data into a **physical artefact** (radio + dial).  
- **Ambient Displays:** Presents predictive environmental data unobtrusively.  
- **Novelty:** Subverts FM technology; carrier drift becomes an intuitive environmental index, and **physical interaction ensures feedback is memorable**.

---

## ⚙️ Technical System
| Component | Role | Mechanism |
|-----------|------|-----------|
| Sensor Suite | Data acquisition & prediction | Multi-gas sensor (e.g., BME680) monitors IAQ, VOCs, temperature, humidity, and feeds adaptive baseline algorithm. |
| Microcontroller (ESP32) | Logic & signal generation | Processes sensor data, calculates deviations, runs predictive baseline algorithm, generates frequency/tone commands. |
| FM Transmitter (SI4713) | Output actuator | Low-power transmission of frequency drift or tone modulation to nearby radios. |
| Analogue FM Radio | Tangible User Interface | Receives broadcast; static/interference prompts dial-turning. Turning the dial slightly moves the receiver out of the interference zone, restoring partial or full clarity and confirming user attention. |

> **Important:** Turning the dial does **not override the broadcast**; it moves the receiver out of the strongest local interference, restoring clarity and creating a **procedural cue**.

---

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

