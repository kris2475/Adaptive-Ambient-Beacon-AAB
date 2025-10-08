# Adaptive Contextual Biometric Beacon (ACBB) – Suggested Improvements

**Author:** K Seunarine  
**Date:** 8 October 2025  

This document outlines **potential enhancements and future directions** for the ACBB project to make it more impactful, research-driven, and user-centred. These suggestions aim to expand functionality, improve user experience, and provide a pathway towards publishable research and practical deployment.

---

## 1. Technical Enhancements

### a) Multi-Sensor Integration
- Expand sensing beyond IAQ and VOCs to include:  
  - **CO / CO₂ detection** for gas hazards.  
  - **Temperature and humidity trends** for comfort optimisation.  
  - **Motion or fall detection** for safety monitoring.  
- Integrate all sensors into **layered feedback** for richer contextual awareness.

### b) Adaptive FM Signalling
- Use FM modules (e.g., Si4713) to:  
  - Modulate carrier subtly based on IAQ deviation.  
  - Implement **graded frequency drift and tone textures**, so minor deviations feel “soft” and acute events are more noticeable.  

### c) Multi-Room / Mesh Feedback
- Deploy multiple low-power FM beacons per room.  
- Each beacon adjusts **local feedback** according to its micro-environment.  
- Optional **BLE mesh coordination** for whole-house contextual intelligence.

### d) Optional Visual or Haptic Layer
- Secondary cues for caregivers or users:  
  - **LED colour strips** to indicate air quality levels.  
  - **Vibration alerts** for urgent events without alarming the user.  

---

## 2. Human-Centred Enhancements

### a) Dementia-Focused UX
- Personalised **familiar sound cues** (radio stations, gentle chimes).  
- Reinforce **procedural memory** via dial-turning or button press interactions.  
- **Custom comfort baselines** per user to reduce alert fatigue.  

### b) Ambient Storytelling / Mood
- Blend environmental data with **subtle audio feedback**:  
  - Rising static can mimic “wind” or environmental cues.  
  - Gentle modulation reinforces calmness rather than alarm.  
- Incorporate **music preferences** for mood-supportive ambient feedback.  

### c) Caregiver Dashboard
- ESP32 or SDR-connected web dashboard for caregivers:  
  - Track air quality trends.  
  - Review alerts history.  
  - Adjust system sensitivity or comfort baselines remotely.

---

## 3. Research & Academic Directions

- **HCI and procedural memory study**: evaluate effectiveness of FM-based procedural cues for dementia.  
- **Quantitative SDR analysis**: record interference perception thresholds, frequency drift mapping, and modulation efficacy.  
- **Human factors evaluation**: assess user independence, anxiety reduction, and safety outcomes.

---

## 4. Prototyping & Maker Enhancements

- **Modular design**: allow easy swapping of sensors, transmitters, and interface components.  
- **Open-source kits**: enable replication and refinement by other researchers or makers.  
- **Custom PCB / enclosure**: integrate seamlessly with analogue radios for discreet deployment.  

---

## 5. Optional “Glory Bonus” Ideas

- **Gamification of interaction**: subtle rewards for responding to environmental alerts.  
- **AI-driven predictive comfort**: use ESP32 + ML model to predict IAQ risk hours before spikes.  
- **Smart home integration**: automated windows, air purifiers, or HVAC respond to FM feedback triggers.  
- **Multi-sensory feedback**: combine FM static, gentle airflow, or subtle scent cues to reinforce environmental awareness.

---

## Conclusion

Implementing these enhancements can transform the ACBB from a **novel proof-of-concept** into a **comprehensive, human-first ambient intelligence system**. The project would provide measurable benefits for ageing populations, particularly individuals with cognitive decline, while producing **research insights and real-world impact**.

---
