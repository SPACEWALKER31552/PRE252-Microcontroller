#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "5RTU4bqhxS-d6t2yj1gLWXtznR21kYuh";
char ssid[] = "S";
char pass[] = "pete1636";


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "43.229.135.169", 8080);
}

void loop()
{
  Blynk.run();
}
