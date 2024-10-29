#define BLYNK_TEMPLATE_ID "TMPL346xWCjz3"
#define BLYNK_TEMPLATE_NAME "CONTROL LED"
#define BLYNK_AUTH_TOKEN "C8DELcxbz-PP1YvHCQ70ZRFKGwPIqK7t"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "MotorolaArnob";  // Enter your Wifi Username
char pass[] = "19421942";  // Enter your Wifi password

int ledpin = D1;
void setup()
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(ledpin,OUTPUT);
}

void loop()
{
 Blynk.run();
}