void setup() {
  // put your setup code here, to run once:kx-9
Serial.begin(115200);
pinMode(D2,OUTPUT);
pinMode(D3,INPUT);
}

void loop()
{  // put your main code here, to run repeatedly:
digitalWrite(D2,LOW);
delayMicroseconds(5);
digitalWrite(D2,HIGH);
delayMicroseconds(10);
double dur = pulseIn(D3,HIGH);
double dist=343*dur/20000;
Serial.println(dist);
}
