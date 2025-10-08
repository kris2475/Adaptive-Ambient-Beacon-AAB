# The Adaptive Contextual Biometric Beacon (ACBB)

## 📖 Overview
The **Adaptive Contextual Biometric Beacon (ACBB)** is a novel **ambient intelligence system** designed to enhance quality of life and safety for **ageing populations** and individuals experiencing **cognitive or sensory decline**.  

Unlike traditional smart home technologies (which often rely on screens, complex menus, or smartphones), the ACBB **repurposes the analogue FM radio** into an unobtrusive, tangible environmental monitor.  

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

## 🗂 Table of Contents
- [Overview](#-overview)  
- [Executive Summary](#-executive-summary-bridging-the-digital-divide-in-elder-care)  
- [Application for Ageing Populations](#-application-for-ageing-populations-and-cognitive-accessibility)  
  - [Sensory & Cognitive Decline](#21-addressing-sensory-and-cognitive-decline)  
  - [Multi-Layered Feedback](#22-multi-layered-feedback-for-intuitive-safety)  
  - [Dementia Care](#23-specific-benefits-for-dementia-care)  
- [Academic Context](#-academic-context-and-technical-alignment)  
  - [HCI Foundations](#31-alignment-with-hci-foundations)  
  - [Feedback Mechanism Novelty](#32-novelty-in-the-feedback-mechanism)  
- [Technical System](#-technical-system-outline)  

---
