#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "MotorolaArnob";         // Your WiFi SSID
const char* password = "19421942"; // Your WiFi password
const char* mqtt_server = "broker.hivemq.com"; // MQTT broker (example)
const char* topic = "ldr/value";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT); // LDR connected to A0

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int ldrValue = analogRead(A0); // Read LDR value
  String message = String(ldrValue);
  client.publish(topic, message.c_str());

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  
  delay(2000); // Publish every 2 seconds
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("NodeMCUClient")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(2000);
}
}
}