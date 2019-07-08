void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(D2,OUTPUT);

}

void loop() {
Serial.println(analogRead(A0));
int temp=(5*analogRead(A0)*100/1024);
Serial.println(temp);

}
