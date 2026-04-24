# smart-bin-embedded
Smart bin using ESP32 with dual ultrasonic sensors and Bluetooth alert Smart Bin using Arduino UNO (Dual Ultrasonic + Bluetooth)

## Overview

This project implements a touchless smart waste bin system using an Arduino UNO. The system integrates **dual ultrasonic sensors for lid automation and fill-level monitoring, along with a **Bluetooth communication module (HC-05) to notify users when the bin is full.

The design focuses on embedded control, real-time sensing, and wireless communication, making it suitable for smart environment and IoT-based waste management applications.



##  Features

  Automatic lid opening using proximity detection
  Real-time fill-level monitoring inside the bin
  Bluetooth alert when bin reaches threshold capacity
  Modular and scalable embedded system design



## System Architecture

The system consists of three functional modules:

1. Lid Control Module**

   * Uses an external ultrasonic sensor
   * Detects object proximity (< 20 cm)
   * Triggers servo motor to open/close lid

2. Fill-Level Detection Module**

   * Internal ultrasonic sensor measures garbage level
   * Calculates fill level using bin height reference

3. Communication Module**

   * HC-05 Bluetooth module
   * Sends alert message to mobile device



Components Used

* Arduino UNO
* 2 × HC-SR04 Ultrasonic Sensors
* SG90 Servo Motor
* HC-05 Bluetooth Module
* Jumper Wires
* Power Supply



Working Principle

Distance Measurement

The ultrasonic sensor calculates distance using time-of-flight:


Where:

(v) = speed of sound
(t) = echo time



 Fill-Level Calculation

fill level = H - d


Where:

  (H) = total bin height
  (d) = measured internal distance


 
 System Logic

* If external distance < 20 cm → lid opens
* If internal fill level exceeds threshold → send Bluetooth alert
* Otherwise → lid remains closed



  Bluetooth Communication

* Device: HC-05
* Mode: Serial communication (9600 baud)
* Mobile App: Serial Bluetooth Terminal


 Testing & Results

* Accurate object detection within 2–200 cm range
* Stable lid operation using servo control
* Reliable Bluetooth notification on threshold condition



Challenges & Considerations

* Ultrasonic interference between sensors → handled using delay
* Servo power instability → may require external power supply
* Noise in sensor readings → can be improved with filtering



 Applications

* Smart homes
* Public waste management systems
* IoT-based environmental monitoring

Developed as an embedded systems project demonstrating sensor integration, control systems, and communication protocols.


