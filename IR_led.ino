#define IR_SENSOR_PIN D2  // GPIO pin connected to the IR sensor
#define LED_PIN D1        // GPIO pin connected to the LED

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);  // Set IR sensor pin as input
  pinMode(LED_PIN, OUTPUT);       // Set LED pin as output
  Serial.begin(115200);           // Start serial communication for debugging
  Serial.println("IR Sensor with LED Test Initialized");
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);  // Read the IR sensor output

  if (sensorValue == LOW) {
    // Object detected, turn the LED on
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Object Detected! LED is ON");
  } else {
    // No object, turn the LED off
    digitalWrite(LED_PIN, LOW);
    Serial.println("No Object. LED is OFF");
  }

  delay(500);  // Add a small delay to avoid flooding the serial monitor
}
