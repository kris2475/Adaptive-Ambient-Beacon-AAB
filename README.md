# Adaptive Ambient Beacon (AAB)

## 📖 Overview
The **Adaptive Ambient Beacon (AAB)** is an **ambient intelligence system** designed to enhance safety and quality of life for **ageing populations** and individuals with **cognitive or sensory decline**. Unlike traditional smart home technologies (which often rely on screens, complex menus, or smartphones), the ACBB **repurposes the analogue FM radio** into an unobtrusive, tangible environmental monitor.  

Imagine Mrs Jones, who enjoys listening to her favourite FM station. She uses a simple, traditional radio and is accustomed to tuning the dial. The ABB introduces subtle, intuitive feedback into this familiar environment. When something in her immediate environment changes—such as an increase in indoor pollutants, VOCs, or other hazards—these events are detected by the ACBB’s **sensor suite** (e.g., BME680 or equivalent gas sensors). The system continuously monitors the environment and calculates the severity of deviations relative to an **adaptive baseline**.

Once a deviation is detected, the ABB responds by transmitting a **low-power FM signal**. This signal interacts with the analogue radio: it creates **audible static or subtle interference**, overlaying the station Mrs Jones is listening to. The interference is intentionally **perceptible but non-startling**, designed to alert her without causing distress. The radio station itself continues to broadcast normally, but the **local ACBB transmission introduces a perceptible cue**.

The **crucial interaction** comes from the user: Mrs Jones responds to the interference by **turning the radio’s tuning dial**. Because analogue radios have finite frequency selectivity, small adjustments move the receiver out of the strongest local interference, **partially or fully restoring clarity** of the station. This physical interaction serves as a **low-cognitive-load, procedural confirmation** that she has noticed the environmental event. By leveraging **procedural memory and familiar physical interaction**, the ACBB provides an intuitive, non-digital alert mechanism suitable for users with cognitive or sensory decline.

### FM Frequency Resolution and Procedural Cue Control
The ACBB relies on a **low-power FM transmitter** to create perceptible interference on a nearby analogue radio, guiding the user to interact with the tuning dial. The **frequency step resolution** of the transmitter determines how gradually this interference can be introduced.

In initial tests using the **Walfront DSP & PLL Digital Wireless Microphone Stereo FM Transmitter Module (87–108 MHz)**, the minimum frequency step is **0.1 MHz**. This means if Mrs Jones is listening to 97.1 MHz, the transmitter can only jump from 97.3 MHz, 97.2 MHz, etc to 97.1 MHz. While effective, these large jumps can **immediately swamp the station**, producing abrupt static that might startle the listener.

By contrast, using a **PLL-based transmitter like the SI4713**, the minimum step is **0.01 MHz (10 kHz)**. This finer resolution allows the ACBB to **approach Mrs Jones’ station very slowly**, e.g., 97.200 → 97.190 → 97.180 MHz, etc. Gradual frequency drift produces **subtle, perceivable static**, giving a **gentle procedural cue** rather than an abrupt disruption. Mrs Jones can then **turn the dial slightly to reduce noise**, confirming her awareness of the environmental event without frustration or alarm. This capability is critical for the ACBB concept: **small, controlled frequency adjustments create a tangible, low-cognitive-load interaction**, leveraging the user’s procedural memory and familiar radio behaviour.

---

## ⚡ Executive Summary: Bridging the Digital Divide in Elder Care
The ACBB utilises an advanced **predictive model (Layer 3)** to monitor:

- Indoor Air Quality (**IAQ**)  
- Volatile Organic Compounds (**VOCs**)  
- Micro-climate shifts  

It communicates personalised environmental data via two subtle, physical feedback channels:  

- **Frequency drift** → static noise indicates degraded IAQ  
- **Tone texture modulation** → erratic sound warns of fume spikes  

The **Tangible User Interface (TUI)** requires users to **interact with the tuning dial** to resolve static, providing:  

- A **low-cognitive-load** check on environmental health  
- **Non-visual feedback** for inclusivity  
- **Safer ageing in place** with reduced digital fatigue  

---

## 🧓 Application for Ageing Populations and Cognitive Accessibility

### 2.1 Addressing Sensory and Cognitive Decline
The ACBB is **non-visual** and leverages **familiar interactions**, making it suitable for users with impairments:

- **Non-Visual Cue:** Alerts are auditory (static increase).  
- **Familiarity:** Interaction uses FM radio/tuning dial, familiar to older generations.  
- **Low Cognitive Load:** Requires a single action—turning the dial.  

---

### 2.2 Multi-Layered Feedback for Intuitive Safety
The ACBB employs layered communication to convey both **chronic and acute risks**:

| Layer | Information Type        | Physical Mechanism & User Action                                                                 | Benefit for Seniors |
|-------|-------------------------|--------------------------------------------------------------------------------------------------|---------------------|
| **Layer 1: Frequency Drift** | Macro-State IAQ (Chronic) | Slow drift of carrier frequency → static noise. User restores clarity by tuning. | Tangible reinforcement of IAQ decline. |
| **Layer 2: Tone Modulation** | Micro-State Fumes (Acute) | Erratic tone rhythm/texture signals sudden fume spikes. | Subtle but urgent safety warning. |
| **Layer 3: Adaptive Baseline** | Predictive Context | System learns personalised IAQ baseline and signals only when conditions deviate. | Reduces alert fatigue; ensures trusted alerts. |
| **Layer 4: User Agency** | Comfort Calibration | User presses a button to reset baseline comfort state. | Preserves autonomy and independence. |

---

### 2.3 Specific Benefits for Dementia Care
The ACBB design directly supports individuals living with **dementia**:  

- **Harnessing Procedural Memory:** Leverages muscle memory (turning dial), bypassing impaired declarative memory.  
- **Mitigating Executive Dysfunction:** Provides visceral non-verbal prompts instead of requiring decision-making.  
- **Reducing Anxiety and Agitation:** Subtle static buildup is less frightening than loud alarms.  
- **Simplifying Crisis Response:** Translates hazards into a binary state: *“Sound is unpleasant → I must correct it.”*  

---

## 🎓 Academic Context and Technical Alignment

### 3.1 Alignment with HCI Foundations
- **Tangible User Interfaces (TUI):** Converts invisible environmental data (IAQ, VOCs) into a **physical artefact** (radio/dial).  
- **Ambient Displays & Assisted Living (AAL):** Functions as an **ambient display**, presenting predictive data unobtrusively in the user’s environment.  

### 3.2 Novelty in the Feedback Mechanism
- **Subversion of FM Technology:** Instead of high-fidelity transmission, FM carrier drift is repurposed as an **intuitive environmental index**.  
- **Actionable Kinesthetic Feedback:** Requires **physical interaction** (tuning dial), making feedback **memorable** and actionable for users with memory challenges.  

---

## ⚙️ Technical System Outline
The ACBB integrates **four technical components** into a context-aware loop:

| Component | Role in the System | Mechanism and Rationale |
|-----------|--------------------|--------------------------|
| **Sensor Suite** | Data Acquisition & Prediction | Multi-gas sensor (e.g., **BME680**) measures IAQ, VOCs, temperature, humidity. Feeds a predictive baseline algorithm. |
| **Microcontroller Unit (MCU)** | Logic & Signal Generation | MCU (e.g., **ESP32**) processes data, runs adaptive baseline algorithm, and generates DAC-driven beacon tones. |
| **FM Transmitter Module** | Output Actuator | FM transmitter (e.g., **SI4713**) adjusts carrier frequency relative to IAQ deviation. |
| **Analogue FM Radio** | User Interface (TUI) | User’s own FM radio receives broadcast. Drift produces static → prompts physical tuning action. |

The design prioritises:  

- **Simplicity**  
- **Robustness**  
- **Low-power operation**  

This ensures the ACBB functions reliably in **non-technical environments** over extended periods.  

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

