
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "sajEB3eazEZbOdkh09Kjjix5IqsxxOW8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "S";
char pass[] = "pete1636";
Servo myservo ;
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
BLYNK_WRITE(V1)
{
  int pinvalue ;
  myservo.write(param.asInt()); // assigning incoming value from pin V1 to a variable
  pinvalue = param.asInt();
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V1 Motor pos is: ");
  Serial.println(pinvalue);
  
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  myservo.attach(22);
}

void loop()
{
  Blynk.run();
}
