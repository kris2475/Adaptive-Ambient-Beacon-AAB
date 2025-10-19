
# Adaptive Ambient Beacon (AAB) 🎓📖

## Overview: Repurposing Procedural Memory for Objective Data

The **Adaptive Ambient Beacon (AAB)** is a dedicated research platform that employs **Tangible User Interface (TUI)** principles to objectively measure cognitive responses in ageing populations and individuals with sensory or cognitive decline. Unlike traditional smart home technologies—which often rely on screens, complex menus, or smartphones—this system leverages the robust, **low-cognitive-load pathway of procedural memory** via a highly familiar interaction method.

The AAB integrates a **high-fidelity sensor suite** (measuring Indoor Air Quality (IAQ), Volatile Organic Compounds (VOCs), and Micro-climate shifts) with a **Tangible Feedback Unit (TFU)**—a custom device designed to look and function exactly like a traditional analogue radio. This decouples the research mechanism from the obsolescence of commercial broadcast standards (FM/DAB).

Environmental deviations detected by the sensor suite (e.g., **BME680**) trigger **Subtle Audio Modulation** on a self-contained, low-power FM frequency broadcast internally within the TFU. Users perform a familiar physical action—**adjusting the tuning dial**—to resolve the audio cue and restore clarity. This provides **objective, non-verbal confirmation of awareness**, suitable for users who struggle with complex digital interfaces or declarative memory tasks.

---

## ⚙️ Technical System Outline & Obsolescence Mitigation

The design emphasizes **Simplicity, Robustness, and Safe, Low-Power Operation**, ensuring reliable long-term use.

### 1. Decoupling Mechanism (The Tangible Feedback Unit - TFU)

- **Analogue Radio / Tuning Dial → TFU**: Custom unit containing both low-power FM transmitter and tuned FM receiver/speaker. Operates as a closed, micro-broadcast loop.
- **The "Station" is the Beacon**: Internal transmitter uses a reserved, low-power, non-interfering frequency, only receivable by the TFU.
- **Benefit**: No reliance on user-owned radios or high-power FM broadcasts, ensuring long-term robustness.

---

### 2. Core Components and Mechanism

| Component | Role | Mechanism & Detail |
|-----------|------|------------------|
| **Sensor Suite (BME680)** | Data Acquisition & Prediction | Measures IAQ, VOCs, temperature, humidity; generates adaptive baseline to reduce alert fatigue |
| **ESP32 MCU** | Logic & Signal Generation | Processes sensor data, calculates deviations, generates modulated audio cues, logs dial interaction |
| **Legal FM Broadcast / Transmitter (SI4713)** | Output Actuator | Low-power modulation of dedicated audio signal, step resolution 0.01 MHz / 10 kHz |
| **Analogue Radio / Tuning Dial (TUI)** | Tangible User Interface | Receives internal FM broadcast; user adjusts dial to restore clarity; dial position sensed and fed back to MCU |

---

### 3. FM Cue Resolution and Procedural Feedback

- **Subtle Modulation**: Gentle onset of audio signals rather than abrupt alarms.
- **Layered Feedback**:
  - **Layer 1**: Frequency modulation indicates chronic IAQ changes (macro-state)
  - **Layer 2**: Tone texture modulation signals acute fume spikes (micro-state)
- **Procedural Confirmation**: Turning the dial provides low-cognitive-load confirmation of awareness, logging **kinesthetic feedback** essential for research.

---

## 🧓 Application for Gerontology Research

### 1. Addressing Sensory and Cognitive Decline

- **Non-Visual Cue**: Audio-based, suitable for visual impairment.
- **Familiarity**: Leverages radio-tuning interactions familiar to older generations.
- **Low Cognitive Load**: Single action confirms awareness, minimizing executive load.
- **Minimising Anxiety**: Subtle modulation reduces stress compared to loud alarms.

### 2. Benefits for Dementia Care

- **Harnessing Procedural Memory**: Physical tuning bypasses impaired declarative memory.
- **Binary Feedback**: Simple interaction: `Audio noticeable → Adjust dial → Audio clear`.
- **User Agency**: Optional **Comfort Calibration** button allows baseline reset.

### 3. Predictive Context (Adaptive Baseline)

- ESP32 integrates a predictive model for a personalised home environment baseline.
- **Reduces Alert Fatigue**: Ignores normal fluctuations (e.g., routine cooking).
- **Maintains Trust**: Cues only trigger on genuine environmental changes.

---

### Flow Diagram

```
[IAQ / VOC Sensors (BME680)]
          ↓
      [ESP32 MCU] — calculates deviation, severity, logs interaction
          ↓
[FM Audio Modulation (SI4713)] — subtle overlay / tone cues (0.01 MHz)
          ↓
[User’s Tangible Feedback Unit (TFU)] ← receives internal audio
          ↓
[User Action: Adjust Dial] — partial clarity restored, logs kinesthetic feedback
          ↑
      [ESP32 MCU] — adjusts baseline, records response latency
```

---

This system represents a **novel, non-intrusive research instrument** combining **environmental sensing, adaptive feedback, and procedural memory-based interactions** for gerontology and TUI studies.





