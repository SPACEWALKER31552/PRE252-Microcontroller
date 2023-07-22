
#include "WiFi.h"
const char* ssid = "SPACEWALKER'S NETWORK"; //Enter SSID
const char* password = "pete1636"; //Enter Password

void setup(void)
{ 
  Serial.begin(115200);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
  }
  
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP32 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address
}

void loop() 
{
  // EMPTY
}
