# IoT Projects with NodeMCU ESP8266 Arduino Board

This repository features a collection of IoT projects using the NodeMCU ESP8266 board to gather data from various sensors and publish it to an MQTT broker for monitoring and control. Additionally, data visualization and control dashboards are implemented with Node-RED and ThingSpeak for seamless real-time monitoring.

## Project Overview

Each project involves connecting specific sensors to the NodeMCU ESP8266, reading data from these sensors, and then publishing the information to an MQTT broker. Node-RED and ThingSpeak platforms enable real-time data visualization and interactive control.

### Table of Contents

- Requirements
- Hardware Components
- Setup
- Project Details
  - Light Sensor (LDR)
  - Ultrasonic Sensor (HC-SR04)
  - Temperature and Humidity Sensor (DHT22/11)
  - Air Quality Sensor
  - MPU6050 Sensor (Gyroscope and Accelerometer)
  - OLED Display (128x64 I2C)
  - Push Buttons (2)
  - LED Control (3 LED Lights)
- Node-RED and ThingSpeak Integration
- License

## Requirements

- Arduino IDE (configured with the ESP8266 board)
- MQTT Broker (e.g., HiveMQ, Mosquitto, or any other broker)
- Node-RED for real-time dashboards
- ThingSpeak for online data storage and analysis
- Libraries:
  - ESP8266WiFi.h for WiFi functionality
  - PubSubClient.h for MQTT functionality
  - DHT.h (for temperature and humidity)
  - Adafruit_SSD1306.h and Adafruit_GFX.h (for OLED display)
  - MPU6050.h for gyroscope and accelerometer functionality

## Hardware Components

- NodeMCU ESP8266 board
- LDR (Light Dependent Resistor) sensor
- HC-SR04 Ultrasonic sensor
- DHT22/11 Temperature and Humidity sensor
- Air Quality sensor
- MPU6050 Gyroscope and Accelerometer sensor
- 128x64 I2C OLED Display
- 2 Push Buttons for user control
- 3 LED lights for visual indicators

## Setup

1. Connect each sensor to the NodeMCU ESP8266 according to the pin configurations below.
2. Install necessary libraries in the Arduino IDE.
3. Configure WiFi, MQTT, and ThingSpeak settings in each Arduino sketch.
4. Upload the sketches to the NodeMCU and monitor the data in Node-RED or ThingSpeak.

### Pin Configurations

- LDR: Connect to analog pin A0.
- Ultrasonic Sensor: Trigger pin to D5, Echo pin to D6.
- DHT22/11: Data pin to D4.
- Air Quality Sensor: Analog pin A0.
- MPU6050: SDA to D2, SCL to D1.
- OLED Display: SDA to D2, SCL to D1.
- Push Buttons: Connect to digital pins D7 and D8.
- LED Lights: Connect each LED to a digital pin (e.g., D9, D10, D11).

## Project Details

### Light Sensor (LDR)

The Light Dependent Resistor (LDR) is connected to analog pin A0 and measures ambient light levels. The value is published to an MQTT topic /ldr/value every 2 seconds for monitoring light intensity.

### Ultrasonic Sensor (HC-SR04)

The HC-SR04 Ultrasonic Sensor measures distance and is connected via D5 (Trigger) and D6 (Echo). It publishes distance data to the MQTT topic /ultrasonic/distance.

### Temperature and Humidity Sensor (DHT22/11)

The DHT22/11 sensor reads temperature and humidity and publishes these values to MQTT topics /temperature/value and /humidity/value. This sensor connects to D4.

### Air Quality Sensor

The Air Quality Sensor monitors the surrounding air quality and publishes an analog reading to an MQTT topic /air_quality/value. The sensor connects to A0.

### MPU6050 Sensor (Gyroscope and Accelerometer)

The MPU6050 Gyroscope and Accelerometer provide orientation data, which includes pitch, roll, and yaw values. Data is published to the MQTT topic /gyroscope/data. The MPU6050 is connected via I2C.

### OLED Display (128x64 I2C)

The OLED Display shows sensor readings, making it easier to visualize data locally. It’s connected via I2C (SDA on D2, SCL on D1). The display can be configured to show the latest readings from each sensor.

### Push Buttons (2)

Two push buttons are connected to digital pins D7 and D8. These buttons can trigger specific actions or data publication events based on user input.

### LED Control (3 LED Lights)

Three LED lights are connected to digital pins (e.g., D9, D10, D11) and can serve as status indicators. LEDs can be controlled via MQTT topics to signal specific sensor conditions or thresholds.

## Node-RED and ThingSpeak Integration

**Node-RED**:

- Use MQTT nodes to subscribe to data from each sensor.
- Configure gauge and chart nodes to create a real-time dashboard.
- Push Buttons can be monitored to trigger Node-RED flows for automation or alerts.

**ThingSpeak**:

- Register an account and create a new channel for each sensor type.
- Use ThingSpeak.begin() in the Arduino sketch to send data to the ThingSpeak platform for long-term storage and trend analysis.
- ThingSpeak channels will visualize data trends and patterns over time, providing valuable insights.

## License

This project is open-source under the MIT License. Contributions and improvements are welcome.
