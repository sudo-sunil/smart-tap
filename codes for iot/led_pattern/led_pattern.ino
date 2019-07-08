void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(D2,OUTPUT);
}

void loop() {
Serial.println(analogRead(A0));
if(analogRead(A0)<150)
{digitalWrite(D2,HIGH);}
else{digitalWrite(D2,LOW);}

}
