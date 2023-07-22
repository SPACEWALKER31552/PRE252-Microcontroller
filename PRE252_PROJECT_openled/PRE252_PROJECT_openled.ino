#define BLYNK_PRINT Serial    
#include "ESP8266WiFi.h"
#include <BlynkSimpleEsp8266.h>
char auth[] = "xzRxu5yXnR_uvZ0qx1knmThS-0gQ-3fa";


void setup()

{
  //yield();
  Serial.begin(9600);
  Blynk.begin(auth,"S", "pete1636");
  ESP.wdtDisable();
  ESP.wdtEnable(WDTO_8S);

}

void loop()

{
  ESP.wdtFeed();
  Blynk.run();
  
}
