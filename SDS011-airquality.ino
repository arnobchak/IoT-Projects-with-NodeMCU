#include <SDS011.h>
#include<OakOLED.h>
#include <WiFiManager.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//oled
OakOLED oled;
//#include <Adafruit_SSD1306.h>
//Adafruit_SSD1306 display(-1);
//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Mqtt
//const char* ssid ="motorola";
//const char* password ="123456789";

const char* ssid = "S22";  // "uniconverge_2_4g";
const char* password = "12345678"; //"#UCT@12345";



char mqtt_server[20] = "34.125.77.114";//"broker.hivemq.com" ; // enter your local host ip here
char port[6] = "1883";
char topic[40] = "AirQuality/UCT2";

float p10,p25;
int error;


//Dht11'
#define DHTPIN D5
#define DHTTYPE DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
float Temp,Humid;

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (200)
char json[MSG_BUFFER_SIZE];
int value = 0;

SDS011 my_sds;
void setup_wifi() {
  /* WiFiManager, Local intializati on. Once its business is done, there is no need to keep it around*/
  WiFiManager wm;
  // wm.resetSettings(); // uncommen t it for resetting wifi*/
  bool res;
  res = wm.autoConnect("AirQualityWIFI");

  if(!res) {
    Serial.println("Failed to connect");
   ESP.restart();
  }
  else {
 //if you get here you have connected to the WiFi    
    Serial.println("connected...yeey :)");
  }
}

void reconnect() {
 // Loop until we're reconnected
 while (!client.connected()) {
  Serial.print("Attempting MQTT connection...");
 // Create a random client ID
  String clientId = "espClient";
 clientId += String(random(0xffff), HEX);
 // Attempt to connect
  if (client.connect(clientId.c_str()))
// if (client.connect("espClient", "BTbDj8IUPl7778PYLSvI", ""))
  {
   Serial.println("connected to broker: ");
   Serial.println(mqtt_server);
 //Once connected, publish an announcement...
 //client.publish(topic, "hello world");
 // ... and resubscribe
 //client.subscribe("inTopic");
}

 else {
 Serial.print("failed, rc=");
 Serial.print(mqtt_server);
 Serial.print(client.state());
 Serial.println(" try again in 5 seconds");
 // Wait 5 seconds before retrying
 delay(5000);
 }
 }
}

void mqtt_setup(){
// delay(10000);
 client.setServer(mqtt_server, atoi(port));
}


void setup() {
  my_sds.begin(D3,D4);
  Serial.begin(9600);
  oled.begin();
  // display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  setup_wifi();
  Serial.println("start");
  mqtt_setup();
}

void loop() {
//AirQuality
error = my_sds.read(&p25,&p10);

//Dht11
sensors_event_t event;
dht.temperature().getEvent(&event);
Temp = event.temperature;
dht.humidity().getEvent(&event);
Humid = event.relative_humidity;

if (! error) {
Serial.println("P2.5: "+String(p25));
Serial.println("P10: "+String(p10));
}
 if (!client.connected()) {
 reconnect();
 }
StaticJsonDocument<300> doc;
 JsonObject root =doc.to<JsonObject>();
 root["P10"] = p10;
 root["P2_5"] = p25;
 root["Temp"] = Temp;
 root["Humid"] = Humid;

serializeJsonPretty(doc, Serial);
 serializeJsonPretty(doc, json);
  Serial.print("Publish message: ");
  Serial.println(json);
  client.publish(topic, json);
 client.loop();

//oled
 oled.clearDisplay();

oled.setTextSize(1.5);  // Normal 1:1 pixel scale
 oled.setTextColor(1);// Draw white text
 oled.setCursor(0,0); // Start at top-left corner
 oled.print("Temp : ");
 oled.print(Temp);
 oled.setCursor(0,10);
 oled.print("Humid : ");
 oled.print(Humid);
 oled.setCursor(0,20);
 oled.print("P10  : ");
 oled.print(p10);
 oled.setCursor(0,30);
 oled.print("P2.5 : ");
 oled.print(p25);
 oled.display();
delay(60000);
}