#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

int mos = 35 ;
int b4 = 0 ;
int af = 0 ;

char auth[] = "5RTU4bqhxS-d6t2yj1gLWXtznR21kYuh";
char ssid[] = "S";
char pass[] = "pete1636";

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Blynk.virtualWrite(V2,pinValue);
} 

 
void setup()
{
  Serial.begin(9600);
  pinMode(mos,INPUT);
  Blynk.begin(auth, ssid, pass, "43.229.135.169", 8080);
}

void loop()
{
  b4 = analogRead(mos);
  af = map(b4,1900,4095,100,0);
  Serial.println(analogRead(mos));
  Serial.println(b4);
  Serial.println(af);
  Serial.println("-----------------------");
  Blynk.run();
  delay(1000);
  Blynk.virtualWrite(V5,b4);
  Blynk.virtualWrite(V4,af);
}
