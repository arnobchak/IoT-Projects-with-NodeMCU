# IoT Projects with NodeMCU ESP8266 Arduino Board

This repository contains multiple IoT projects using the **NodeMCU ESP8266** board to read data from various sensors and publish it to an MQTT broker for monitoring or control. The setup includes sensors for **light (LDR)**, **distance (Ultrasonic)**, **temperature and humidity (DHT22/11)**, **OLED display**, and **LED control**.

## Project Overview

Each project involves connecting a specific sensor to the NodeMCU ESP8266, reading sensor data, and then publishing it to an MQTT broker. This allows you to monitor sensor data in real-time from anywhere with internet access.

## Table of Contents

- [Requirements](#requirements)
- [Hardware Components](#hardware-components)
- [Setup](#setup)
- [Project Details](#project-details)
  - [Light Sensor (LDR)](#light-sensor-ldr)
  - [Ultrasonic Sensor (HC-SR04)](#ultrasonic-sensor-hc-sr04)
  - [Temperature and Humidity Sensor (DHT22/11)](#temperature-and-humidity-sensor-dht22-11)
  - [OLED Display (128x64 I2C)](#oled-display-128x64-i2c)
  - [LED Control (3 LED Lights)](#led-control-3-led-lights)
- [MQTT Setup](#mqtt-setup)
- [License](#license)

---

## Requirements

- **Arduino IDE** (configured with the ESP8266 board)
- **MQTT Broker** (e.g., HiveMQ, Mosquitto, or any other broker)
- Libraries:
  - `ESP8266WiFi.h`
  - `PubSubClient.h`
  - `DHT.h` (for temperature and humidity)
  - `Adafruit_SSD1306.h` and `Adafruit_GFX.h` (for OLED display)

## Hardware Components

- **NodeMCU ESP8266** board
- **LDR** (Light Dependent Resistor) sensor
- **HC-SR04** Ultrasonic sensor
- **DHT22/11** Temperature and Humidity sensor
- **128x64 I2C OLED Display**
- **3 LED lights** (for visual indicators)

## Setup

1. **Connect each sensor** to the NodeMCU ESP8266 according to the pin configurations below.
2. **Install necessary libraries** in the Arduino IDE.
3. **Configure WiFi and MQTT settings** in the Arduino sketches provided.
4. **Upload the sketches** to the NodeMCU and monitor the data published to the MQTT topics.

### Pin Configurations

- **LDR**: Connect to analog pin `A0`.
- **Ultrasonic Sensor**: Trigger pin to `D5`, Echo pin to `D6`.
- **DHT22/11**: Data pin to `D4`.
- **OLED Display**: SDA to `D2`, SCL to `D1`.
- **LED Lights**: Connect each LED to a digital pin (e.g., `D7`, `D8`, `D9`).

## Project Details

### Light Sensor (LDR)

The **Light Dependent Resistor (LDR)** is connected to the analog pin `A0` and measures the ambient light level. The value is read and published to an MQTT topic `/ldr/value` every 2 seconds.

### Ultrasonic Sensor (HC-SR04)

The **HC-SR04 Ultrasonic Sensor** measures distance and is connected via `D5` (Trigger) and `D6` (Echo). It publishes distance data to the MQTT topic `/ultrasonic/distance`.

### Temperature and Humidity Sensor (DHT22/11)

The **DHT22/11** sensor reads temperature and humidity and publishes the values to MQTT topics `/temperature/value` and `/humidity/value`. This sensor connects to `D4`.

### OLED Display (128x64 I2C)

The **OLED Display** shows sensor readings, making it easier to visualize data locally. The display is connected via I2C (SDA on `D2`, SCL on `D1`). You can update the display code to show the latest readings from each sensor.

### LED Control (3 LED Lights)

Three **LED lights** are connected to digital pins (e.g., `D7`, `D8`, `D9`) and are used as status indicators. They can be controlled through MQTT topics to signal various conditions, such as specific sensor thresholds.

## MQTT Setup

1. Choose an MQTT broker, such as HiveMQ or Mosquitto. Update the MQTT broker address in each sketch with the broker IP or hostname.
2. Define MQTT topics for each sensor as outlined in the project sections above.
3. Monitor the data from each sensor in real-time using any MQTT client or create a dashboard using MQTT-compatible platforms like **Node-RED** or **Home Assistant**.

## License

This project is open-source and free to use under the MIT License. Contributions and improvements are welcome!

---

Happy IoT Experimenting! If you have any questions or run into issues, feel free to open an issue on GitHub.
