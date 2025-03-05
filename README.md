# AI-Based Acoustic Railway Track Defect Detection System

## Overview
This project aims to develop an AI-based acoustic wave monitoring system to detect railway track defects such as cracks, fractures, and wear. The system enhances railway safety, efficiency, and reliability by integrating sensors, AI algorithms, and communication modules.

## Problem Statement
Railway derailments account for over 50% of annual railway accidents, causing significant damage and casualties. The proposed AI-based Acoustic Railway Track Defect Detection System aims
to detect track defects such as cracks, gaps, broken sleepers, and interfoot defects using acoustic sensors and AI.Train derailments remain a significant safety hazard. This system addresses the issue by:
- Identifying frequency anomalies with a **Main Module**.
- Processing visual data using a **Child Module**.
- Providing real-time alerts for train supervisors and station admins.

## Objectives
- Design a modular system using **acoustic sensors, piezoelectric sensors, and cameras** to detect track defects.
- Implement **AI algorithms** for analyzing acoustic wave patterns.
- Utilize **LoRa technology** for seamless data exchange between modules.
- Deploy **ESP-CAM** for surface defect detection and **ESP32** for processing.
- Develop **dual user interfaces** for real-time alerts and reporting.
- Ensure a **cost-effective and scalable** solution.

## Solution Architecture
### 1. **Master Module (Train-Mounted)**
- Installed at the train's bottom.
- Uses **Raspberry Pi** to run **TinyML models** for defect analysis.
- Collects frequency data from **Piezoelectric Sensors**.

### 2. **Child Module (Track-Side, Unity Poles)**
- Uses **ESP-CAM** for object detection.
- Captures images and sends metadata to the Master Module.
- Relays processed data via **LoRa Module**.

### 3. **User Interface (Supervisors & Admins)**
- Displays real-time alerts and train location.
- Enables emergency communication and defect tracking.

## Technologies Used
| Component  | Tools/Technologies  |
|------------|---------------------|
| **Hardware**  | Raspberry Pi, Piezoelectric Sensor, Hall Effect Sensor, ADC, LoRa Module, GPS, GSM, ESP-CAM, IR Sensor, ESP32 |
| **Front-End** | Kotlin |
| **Data Processing** | TinyML, TensorFlow Lite |
| **Backend** | Firebase |
| **Database** | MongoDB |

## Workflow
1. **Detection:** Sensors capture track anomalies.
2. **Data Processing:** AI models analyze frequency inconsistencies.
3. **Communication:** LoRa transmits data between modules.
4. **Alert System:** UI notifies supervisors and admins.

## Benefits
- **Reduces Train Derailment by 35%**.
- **Saves Maintenance Costs** with early defect detection.
- **Improves Train Punctuality** by minimizing delays.
- **Enhances Accuracy** with dual-module anomaly detection.
- **Automates Inspections** to optimize resources.

## Impact
- Prevents accidents with early defect identification.
- Scalable for deployment across railway networks.
- Ensures high security and quality standards with AI-driven monitoring.

## Demo
The system generates a **processed frequency graph** from the Piezoelectric sensor to highlight anomalies.

## License
This project is licensed under the **MIT License**.

## Acknowledgments
Special thanks to all team members and mentors who contributed to this project.

---

_Thank You!_

