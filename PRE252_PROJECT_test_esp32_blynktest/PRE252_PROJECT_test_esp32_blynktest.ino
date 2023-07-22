#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int LED = 19 ;

char auth[] = "yDO1_8qdgYMRmBI0PRIK7ldQXHOqGxku";
char ssid[] = "SPACEWALKER'S NETWORK";
char pass[] = "pete1636";

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
  
}

void setup()
{
  Serial.begin(9600);
  pinMode (LED, OUTPUT);
  Blynk.begin(auth, ssid, pass, "43.229.135.169", 8080);
}

void loop()
{
  Blynk.run();
}
