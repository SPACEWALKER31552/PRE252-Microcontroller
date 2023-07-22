#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <TridentTD_LineNotify.h>
//########## CONFIGURATION : MODIFY HERE ##########
char ssid[] = "S"; // เครือข่าย Wi-Fi ที่ต้องการเชื่อมต่อ
char pass[] = "pete1636"; // รหัสผ่านเครือข่าย

//รหัสเชื่อมต่อ Line token
#define LINE_TOKEN "qxBXbQGHPSpf4PMIE0kdNRBV7paT94f0AiF6VZ9Dh9o"
#define LINE_TOKEN2 "PNhp4RSWJIOw5eiWTftpw2lGhJuwO1FgWDpwS0ujA3O"

// ข้อความ ที่จะแสดงใน Line
String txt1 = "มีผู้บุกรุก!!! ที่อาคาร 5";

void setup() 
{
pinMode(23, INPUT);
Serial.begin(115200);

WiFi.begin(ssid, pass);
Serial.print("WiFi Connecting");

while (WiFi.status() != WL_CONNECTED) 
{
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
}

void loop() 
{

LINE.setToken(LINE_TOKEN);
LINE.notify(txt1);
LINE.setToken(LINE_TOKEN2);
LINE.notify(txt1);

}
