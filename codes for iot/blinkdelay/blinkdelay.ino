void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(D2,INPUT);
pinMode(D3,OUTPUT);}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println(digitalRead(D2));
if(digitalRead(D2)==0)
{
 digitalWrite(D3,HIGH); 
  }
else{digitalWrite(D3,LOW);}  
}
