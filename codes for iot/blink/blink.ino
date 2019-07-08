void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(7,OUTPUT);
for(int i=1;i<11;i++)
{
Serial.println("hello") ; 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

for(int i=1;i<11;i++)
{
digitalWrite(7,HIGH);
delay(500);
digitalWrite(7,LOW);
delay(500);
}
delay(5000);
}
