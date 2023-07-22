
int mos = 32 ;
int b4 = 0 ;
int af = 0 ;


void setup()
{
  Serial.begin(9600);
  pinMode(mos,INPUT);
}

void loop()
{
  b4 = analogRead(mos);
  af = map(b4,1900,4095,100,0);
  Serial.println(analogRead(mos));
  Serial.println(b4);
  Serial.println(af);
  Serial.println("-----------------------");
  delay(1000);
}
