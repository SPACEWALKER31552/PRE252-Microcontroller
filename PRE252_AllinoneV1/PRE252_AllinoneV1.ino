//All in one V1
//-------------------------Library Preparetion-----------------------------
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
#define DHTPIN 21
#define DHTTYPE DHT11 
#include <TridentTD_LineNotify.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
BlynkTimer timer ;
WidgetRTC rtc ;
#define LINE_TOKEN "qxBXbQGHPSpf4PMIE0kdNRBV7paT94f0AiF6VZ9Dh9o"
#define LINE_TOKEN2 "PNhp4RSWJIOw5eiWTftpw2lGhJuwO1FgWDpwS0ujA3O"
//-------------------------Variable Configuration--------------------------
char auth[] = "b4DCwDHbzdPQB6zoZDEaz_D_DMAbw8Vn";
char ssid[] = "S";
char pass[] = "pete1636";
DHT dht(DHTPIN, DHTTYPE);
int i = 0 ;
int mos = 32 ;
int mosbefore = 0 ;
int mosafter = 0 ;
const int light = 35 ;
int lightaf = 0 ;
String Lmosb4 = "" ;
String Lmosaf = "" ;
String Lhumid = "" ;
String Ltemp = "" ;
String LheatC = "" ;
String LheatF = "" ;
String Lldr = "" ;
String Lbutton = "" ;
String Line1 = "" ;
String Line2 = "" ;
String Line3 = "" ;
String currenttime = "" ;
String currentdate = "" ;
String date = "" ;
String timme = "" ;
String Lhour = "" ;
String Lminute = "" ;
String Lsecond = "" ;
String Lday = "" ;
String Lmonth = "" ;
String Lyear = "" ;
//--------------------------------CLOCK-----------------------------------
void clockDisplay()
{
  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + " " + month() + " " + year();
  Blynk.virtualWrite(V1, currentTime);
  Blynk.virtualWrite(V2, currentdate);
}
BLYNK_CONNECTED() 
{
  rtc.begin();
}
//--------------------------------SET UP-----------------------------------
void setup()
{
  Serial.begin(9600);
  pinMode(mos,INPUT);
  pinMode(light,INPUT);
  dht.begin();
  Blynk.begin(auth, ssid, pass, "43.229.135.169", 8080);
  setSyncInterval(10 * 60); // Sync interval in seconds (10 minutes)
  // Display digital clock every 10 seconds
  timer.setInterval(10000L, clockDisplay);
}
void loop() 
{
//------------------------------Variable-----------------------------------
  mosbefore = analogRead(mos);
  mosafter = map(mosbefore,1900,4095,100,0);
  lightaf = analogRead(light);
  float humidity = dht.readHumidity(); //วัดค่าความชื้น
  float temperature = dht.readTemperature(); // วัดค่าอุณหภูมิ
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f, humidity);
  float hic = dht.computeHeatIndex(temperature, humidity, false);
//-------------------------Serial Monitor-----------------------------------
  Serial.print("Mosture Sensor Before Mapping : ");
  Serial.println(mosbefore);
  Serial.print("Mosture Sensor After Mapping : ");
  Serial.println(mosafter);
  Serial.print("LDR Sensor : "); 
  Serial.println(lightaf);
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  Serial.println("-----------------------");
//-----------------------------Blynk----------------------------------------
  Blynk.run();
  timer.run();
  Blynk.virtualWrite(V6,lightaf);
  Blynk.virtualWrite(V5,mosbefore);
  Blynk.virtualWrite(V4,mosafter);
  Blynk.virtualWrite(V3,humidity);
  Blynk.virtualWrite(V8,temperature);
  Blynk.virtualWrite(V9,hic);
  Blynk.virtualWrite(V0,hif);
  Blynk.virtualWrite(V7,digitalRead(23));
//-------------------------Line Notify--------------------------------------
  
  Lmosb4 = String(mosbefore) ;
  Lmosaf = String(mosafter) ;
  Lhumid = String(humidity) ;
  Ltemp = String(temperature) ;
  LheatC = String(hic) ;
  LheatF = String(hif) ;
  Lldr = String(lightaf) ;
  
//------------------------Case รดน้ำต้นไม้-------------------------------------  
  if(digitalRead(23) == 1)
  {
      Lbutton = "ระบบปั้มน้ำเปิด" ;
  }
  else{Lbutton = "ระบบปั้มน้ำปิด" ;}
  
  timme  = String(hour()) + ":" + minute() + ":" + second();
  date  = String(day()) + " เดือน " + month() + " ปี " + year();
  Line1 = String("\nแจ้งเตือน ณ วันที่ " + date + "\n------------------- เวลา " + timme + " -------------------" + "\nค่าความชื้นในดิน(ดิบ) : " + Lmosb4 + "\nค่าความชื้นในดิน(เปอร์เซ็น) : " + Lmosaf + "%" + "\nค่าความชื้นในอากาศ(เปอร์เซ็น) : " + Lhumid + "%" + "\nอุณหภูมิ : " + Ltemp + " Celcius" + "\nความร้อนในอากาศ : " + LheatC + " Celcius" + "\nความร้อนในอากาศ : " + LheatF + " Farenhiet" + "\nค่าความเข้มแสงแดด : " + Lldr + "\nสถานะระบบปั้มน้ำ : " + Lbutton);  

//--------------------Case แจ้งเตือน 8 โมงเช้า กับ 6 โมงเย็น // Restart ทุกๆ 3 9 15 21 -------------------
  if(hour()== 8 && minute()== 0 && second()==0)
  {
    LINE.setToken(LINE_TOKEN);
    LINE.notify(Line1);
    LINE.setToken(LINE_TOKEN2);
    LINE.notify(Line1);
    // ปิดไฟ
  }
  else if(hour()== 18 && minute()== 0 && second()==0)
  {
    LINE.setToken(LINE_TOKEN);
    LINE.notify(Line1);
    LINE.setToken(LINE_TOKEN2);
    LINE.notify(Line1);
    // เปิดไฟ
  }
  else if(hour()== 3 || hour()== 9 || hour()== 15 || hour()== 21) 
  {
    if(minute()== 0 && second()==0)
    {
      ESP.restart();
    }
    else{}
  }
  else{}
  
//--------------------Case แจ้งเตือน ความชื้นต่ำ -------------------
  if(mosafter <= 20)
  {
    Line2 = "***** คำเตือน !!!! ความชื้นต่ำ กรุณาเปิดระบบรดน้ำด้วย ***** " ;
    LINE.setToken(LINE_TOKEN);
    LINE.notify(Line1);
    LINE.notify(Line2);
    LINE.setToken(LINE_TOKEN2);
    LINE.notify(Line1);
    LINE.notify(Line2);
  }

  
   
  
  
}
