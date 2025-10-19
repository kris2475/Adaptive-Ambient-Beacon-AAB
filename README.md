# Adaptive Ambient Beacon (AAB) 🎓📖

## Overview: Repurposing Procedural Memory for Objective Data
The **Adaptive Ambient Beacon (AAB)** is a dedicated research platform that employs **Tangible User Interface (TUI)** principles to objectively measure cognitive responses in ageing populations and individuals with sensory or cognitive decline. Unlike traditional smart home technologies—which often rely on screens, complex menus, or smartphones—this system leverages the robust, low-cognitive-load pathway of **procedural memory** via a highly familiar interaction method.

The AAB integrates a high-fidelity **sensor suite** (measuring Indoor Air Quality (IAQ), Volatile Organic Compounds (VOCs), and micro-climate shifts) with a **Tangible Feedback Unit (TFU)**—a custom device designed to look and function exactly like a traditional analogue radio. This decouples the research mechanism from the obsolescence of commercial broadcast standards (FM/DAB).

Environmental deviations detected by the sensor suite (e.g., BME680) trigger **Subtle Audio Modulation** on a self-contained, low-power FM frequency broadcast internally within the TFU. Users perform a familiar physical action—adjusting the tuning dial—to resolve the audio cue and restore clarity. This provides objective, non-verbal confirmation of awareness, suitable for users who struggle with complex digital interfaces or declarative memory tasks.

---

## ⚙️ Technical System Outline & FM-based Tangible Feedback

The design emphasizes **Simplicity, Robustness, and Safe, Low-Power Operation**, ensuring reliable long-term use.

### 1. Decoupling Mechanism & FM-based Tangible Feedback (The TFU)
The **Tangible Feedback Unit (TFU)** contains a low-power FM transmitter and receiver loop internally. This preserves familiar interaction patterns for older adults: tuning a physical radio dial genuinely affects a signal.

**Key Features:**
- **Dynamic Layered Modulation:** FM transmission allows subtle frequency shifts and overlay tones to indicate different environmental deviations:
  - **Macro-State:** Gradual changes in IAQ (chronic trends)
  - **Micro-State:** Acute spikes in VOCs or fumes
- **Accurate Kinesthetic Feedback:** Dial movements are logged for objective research measurements.
- **Future Scalability:** Multiple TFUs in one space can receive the same signal.
- **Safety & Compliance:** Internal FM broadcast operates at low, legally safe power, fully contained within the TFU chassis.

**Benefit:** The FM loop transforms a simple environmental cue into a tangible, procedural task that is measurable, familiar, and low-stress for participants.

---

### 2. Core Components and Mechanism

| Component | Role | Mechanism & Detail |
|-----------|------|------------------|
| Sensor Suite (BME680) | Data Acquisition & Prediction | Measures IAQ, VOCs, temperature, humidity; generates adaptive baseline to reduce alert fatigue |
| ESP32 MCU | Logic & Signal Generation | Processes sensor data, calculates deviations, generates modulated audio cues, logs dial interaction |
| Legal FM Broadcast / Transmitter (SI4713) | Output Actuator | Low-power modulation of dedicated audio signal, step resolution 0.01 MHz / 10 kHz |
| Analogue Radio / Tuning Dial (TUI) | Tangible User Interface | Receives internal FM broadcast; user adjusts dial to restore clarity; dial position sensed and fed back to MCU |

---

### 3. FM Cue Resolution and Procedural Feedback

- **Subtle Modulation:** Gentle onset of audio signals rather than abrupt alarms.
- **Layered Feedback:**  
  - **Layer 1:** Frequency modulation indicates chronic IAQ changes (macro-state)  
  - **Layer 2:** Tone texture modulation signals acute fume spikes (micro-state)
- **Procedural Confirmation:** Turning the dial provides low-cognitive-load confirmation of awareness, logging kinesthetic feedback essential for research.

---

### Implementation Note: Transmit Power Control (Proof of Concept)
- Uses **iHaospace SI4713 FM Transmitter** for availability, low cost, and digital power control.
- **TX Power:** Software-controlled to remain low (~90 dBµV) and can be set to 0 or powered down between transmissions.
- **Low-Power Operation:** Only the ESP32 wakeup module handles wireless transmission when idle.

---

## 🧓 Application for Gerontology Research

### 1. Addressing Sensory and Cognitive Decline
- **Non-Visual Cue:** Audio-based, suitable for visual impairment.
- **Familiarity:** Leverages radio-tuning interactions familiar to older generations.
- **Low Cognitive Load:** Single action confirms awareness.
- **Minimizing Anxiety:** Subtle modulation reduces stress compared to loud alarms.

### 2. Benefits for Dementia Care
- **Harnessing Procedural Memory:** Physical tuning bypasses impaired declarative memory.
- **Binary Feedback:** Simple interaction: Audio → Adjust dial → Audio clear.
- **User Agency:** Optional comfort calibration button allows baseline reset.

### 3. Predictive Context (Adaptive Baseline)
- **ESP32 integrates a predictive model** for a personalised home environment baseline.
- **Reduces Alert Fatigue:** Ignores routine fluctuations (e.g., cooking).
- **Maintains Trust:** Cues trigger only on genuine environmental changes.

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

## 📊 Interaction Logging for Research Use

### Overview
Interaction logging bridges environmental sensing and behavioural measurement. This allows researchers to **quantitatively study awareness, responsiveness, and procedural cognition** without complex interfaces or verbal tasks.

### Concept
- Subtle environmental deviations trigger mild FM distortion.
- Users instinctively **turn the dial** to restore clarity.
- The system logs **time-stamped, measurable interactions**.

### Logged Data

| Data Point | Description | Research Use |
|------------|-------------|--------------|
| Trigger Time | When deviation occurred | Establishes cue onset |
| Trigger Type | Type of deviation (IAQ, VOC, temperature) | Context for stimulus |
| Response Time | When the dial first moved | Measures awareness & attention |
| Resolution Time | When clarity was restored | Reflects motor control & engagement |
| Response Latency | Time from cue to first response | Indicator of processing speed |
| Outcome | Whether cue was resolved | Binary performance indicator |

**Example Log Entry (JSON):**
```json
{
  "event_id": "b13a7e2c-51d2-4d4b-94f8-ef0219af932b",
  "trigger_time": "2025-10-19T09:24:13Z",
  "trigger_type": "VOC_spike",
  "response_time": "2025-10-19T09:24:27Z",
  "resolution_time": "2025-10-19T09:24:48Z",
  "response_latency_s": 14,
  "resolution_duration_s": 21,
  "outcome": "resolved"
}
```

### Research Rationale

**Gerontology Perspective**
- Procedural memory preservation: radio-tuning gesture remains intact in older adults.
- Low cognitive load: simple, familiar motor response.
- Longitudinal insight: changes in response speed or success rate indicate cognitive decline.

**HCI Perspective**
- Objective, embodied data: timestamped, sensor-linked behavioural metrics.
- Non-intrusive: subtle cues reduce stress or confusion.
- Familiar tangible interaction: study procedural adaptation in ageing users.

### Implementation Guidance
- **Timestamp Key Events:** trigger_time, response_time, resolution_time
- **Track Dial Movement:** rotary encoder or potentiometer
- **Compute Metrics:** response_latency = response_time - trigger_time
- **Store Securely:** local file or database; optional secure sync
- **Export Easily:** CSV or JSON for analysis in R, Python, or MATLAB

---

## Summary
The **Adaptive Ambient Beacon (AAB)** is a novel, non-intrusive research instrument combining:
- Environmental sensing (IAQ/VOCs)
- Adaptive feedback via subtle FM modulation
- Procedural memory-based tangible interactions

This system enables objective, low-cognitive-load measurement of cognition, attention, and adaptation in ageing and cognitively diverse populations.






