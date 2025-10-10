# Adaptive Ambient Beacon (AAB)

## 📖 Overview
The **Adaptive Ambient Beacon (AAB)** is an **ambient intelligence system** designed to enhance safety and quality of life for **ageing populations** and individuals with **cognitive or sensory decline**. Unlike traditional smart home technologies (which often rely on screens, complex menus, or smartphones), the AAB **repurposes analogue FM radio as a tangible environmental monitor**, providing subtle, intuitive feedback through familiar devices.

Imagine Mrs Jones, who enjoys listening to a **legally licensed FM station**, such as a public “talking book” broadcast. She uses a simple, traditional radio and is accustomed to tuning the dial. The AAB introduces feedback by **slightly modulating a separate, low-power FM signal** on a legal frequency near the station. When environmental changes occur—such as increases in indoor pollutants, VOCs, or other hazards detected by the **sensor suite** (e.g., BME680)—the system calculates deviations relative to an **adaptive baseline**.

Instead of interfering with the licensed station, the AAB **synchronises subtle audio cues with the broadcast content**, producing a gentle overlay or additional tones that are **perceptible but non-startling**. The radio station continues normally, but the cues provide a tangible signal for the user.

The **crucial interaction** comes from the user: Mrs Jones responds to these cues by **turning the radio’s tuning dial or adjusting the attached knob**, which is mapped to the signal modulation. This physical interaction provides a **low-cognitive-load, procedural confirmation** that she has noticed the environmental event. By leveraging **procedural memory and familiar radio interactions**, the AAB offers an intuitive, non-digital alert mechanism suitable for older adults or users with cognitive or sensory decline.

---

### FM Cue Resolution and Procedural Feedback
The AAB relies on a **low-power FM transmitter** that operates on a **legal broadcast frequency** (e.g., a public audio channel) to generate subtle cues corresponding to environmental changes. Using a **PLL-based transmitter like the SI4713**, the system can produce **fine-grained audio modulation** (steps as small as 0.01 MHz / 10 kHz) to deliver gentle, perceptible cues rather than abrupt interference.  

This allows **gradual onset of audio signals** that the user can respond to by turning the dial slightly, confirming awareness of the event without causing alarm. Controlled modulation produces a **tangible, low-cognitive-load interaction**, leveraging procedural memory in familiar radio behaviour.

---

## ⚡ Executive Summary: Ambient Awareness for Gerontology Research
The AAB integrates a predictive model to monitor:

- Indoor Air Quality (**IAQ**)  
- Volatile Organic Compounds (**VOCs**)  
- Micro-climate shifts  

Environmental changes are communicated via **subtle audio cues**:

- **Frequency modulation / overlay tones** → indicate chronic IAQ changes  
- **Tone texture modulation** → signals acute fume spikes  

The **Tangible User Interface (TUI)** requires the user to **interact physically** with the radio or a dedicated dial to resolve the cue, providing:

- **Low-cognitive-load feedback** for environmental awareness  
- **Non-visual cues** suitable for cognitive or sensory decline  
- **Safe ambient monitoring** without digital fatigue  

> **Note:** This system is intended as a **proof-of-principle** and a research tool for gerontologists studying interaction patterns and cognitive responses in older adults, not for broadcasting commercial content.

---

## 🧓 Application for Ageing Populations and Cognitive Accessibility

### 2.1 Addressing Sensory and Cognitive Decline
The AAB is **non-visual** and leverages **familiar interaction patterns**:

- **Non-Visual Cue:** Audio overlay or tone changes signal environmental events.  
- **Familiarity:** Interaction uses radio tuning or dial adjustments, familiar to older generations.  
- **Low Cognitive Load:** Single, simple action—adjusting the dial—confirms awareness.  

---

### 2.2 Multi-Layered Feedback for Intuitive Safety
The system conveys **chronic and acute environmental states**:

| Layer | Information Type | Mechanism & User Action | Benefit for Seniors |
|-------|-----------------|-----------------------|-------------------|
| **Layer 1: Frequency Modulation** | Macro-State IAQ | Slow overlay or subtle tone change; user restores clarity via dial | Tangible reinforcement of environmental status |
| **Layer 2: Tone Texture** | Micro-State Fumes | Erratic tone indicates acute fume spikes | Subtle but urgent safety warning |
| **Layer 3: Adaptive Baseline** | Predictive Context | System learns personalised baseline; cues only on deviation | Reduces alert fatigue; maintains trust |
| **Layer 4: User Agency** | Comfort Calibration | User presses a button to reset baseline | Preserves autonomy |

---

### 2.3 Benefits for Dementia Care
- **Harnessing Procedural Memory:** Turning the dial bypasses impaired declarative memory.  
- **Reducing Executive Load:** Simple, visceral audio cues avoid decision-making stress.  
- **Minimising Anxiety:** Subtle modulation is less alarming than alarms.  
- **Binary Feedback:** “Audio is noticeable → I adjust dial” simplifies response.

---

## 🎓 Academic Context and Technical Alignment

### 3.1 Alignment with HCI Principles
- **Tangible User Interfaces (TUI):** Converts invisible environmental data into physical interaction.  
- **Ambient Assisted Living (AAL):** Unobtrusive display of predictive environmental data.

### 3.2 Novelty in Feedback
- **Subversion of FM Use:** Instead of broadcasting interference, FM audio is **modulated to create perceptible cues**, repurposing existing licensed channels.  
- **Actionable Kinesthetic Feedback:** Requires **physical interaction**, enhancing memory and attention.

---

## ⚙️ Technical System Outline
| Component | Role | Mechanism |
|-----------|------|-----------|
| **Sensor Suite** | Data Acquisition & Prediction | Multi-gas sensor measures IAQ, VOCs, temperature, humidity; generates adaptive baseline. |
| **ESP32 MCU** | Logic & Signal Generation | Processes sensor data, predicts deviations, generates modulated audio cues. |
| **Legal FM Broadcast / Transmitter** | Output Actuator | Fine-grained, low-power modulation of legally licensed audio signal. |
| **Analogue Radio / Tuning Dial** | TUI | Receives FM broadcast; user adjusts dial to resolve cues. |

Design focuses on:

- **Simplicity**  
- **Robustness**  
- **Safe, low-power operation**  

---

## 🏠 Practical Operation Scenario
1. **Normal Operation:** Radio tuned to licensed FM broadcast, AAB modulation minimal.  
2. **Environmental Change:** Sensors detect IAQ deviation; MCU calculates severity.  
3. **Cue Activation:** Chronic events → slow audio overlay; acute events → tone modulation.  
4. **User Response:** Adjusts dial → audio overlay diminishes, confirming attention.  
5. **Feedback Loop:** MCU logs interaction, adapts baseline for optimal sensitivity.

---

✅ Key Points

Uses legal FM broadcast channels; avoids interference with commercial stations.
Physical dial adjustments provide low-cognitive-load feedback.
Audio modulation differentiates chronic vs. acute events.
Intended as a proof-of-principle and research tool for gerontology studies.
Demonstrates tangible HCI interaction for cognitive accessibility.

🗂 Table of Contents
Overview
Executive Summary
Benefits for Dementia Care
Academic Context
Technical System
Practical Operation Scenario
Key Points

### Flow Diagram

```text
[IAQ / VOC Sensors]
       ↓
[ESP32 MCU] — calculates deviation & severity
       ↓
[FM Audio Modulation] — subtle overlay / tone cues
       ↓
[User’s Analogue FM Radio] ← receives audio cues
       ↓
[User Action: Adjust Dial] — partial clarity restored
       ↓
[ESP32 MCU] — logs interaction & adjusts baseline





