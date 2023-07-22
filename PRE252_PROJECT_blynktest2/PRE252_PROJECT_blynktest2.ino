#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = "rhBgPTRxC3qXCy3AWYcc_L_4IPvgww7m";
char ssid[] = "S";
char pass[] = "pete1636";

void setup()

{
  //yield();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "43.229.135.169", 8080);


}

void loop()

{

  Blynk.run();
  
}
BLYNK_WRITE(V3) 
{
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 Serial.println(pinValue);
 delay(1000);
 if(pinValue == 1 )
 {
  pinValue = 0 ;
  Serial.println(pinValue);
  Blynk.virtualWrite(V3, pinValue);
 }
 else
 {
  pinValue = 1 ;
  Serial.println(pinValue);
  Blynk.virtualWrite(V3, pinValue);
 }
}
BLYNK_WRITE(V2) 
{
 int pinValue2 = param.asInt(); // Assigning incoming value from pin V3 to a variable
  Serial.println(pinValue2);
  Blynk.virtualWrite(V4, pinValue2);
}
