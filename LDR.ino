void setup() {
  Serial.begin(115200); // Start the Serial Monitor
}

void loop() {
  int ldrValue = analogRead(A0); // Read the LDR value
  Serial.print("LDR Value: ");
  Serial.println(ldrValue); // Print the value to Serial Monitor
  delay(1000); // Wait for a second
}
