#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = "zgIEMmA3c1hA1YQ6W7g_gnePkHjoQvFQ";
char ssid[] = "S";
char pass[] = "pete1636";
const int light = 36 ;
int lightaf = 0 ;
void setup() 
{
  Serial.begin(9600);
  pinMode(light,INPUT);
  Blynk.begin(auth, ssid, pass, "43.229.135.169", 8080);
}

void loop() 
{
  lightaf = analogRead(light);
  Serial.println(lightaf);
  Blynk.virtualWrite(V5,lightaf);
  Blynk.run();
}
