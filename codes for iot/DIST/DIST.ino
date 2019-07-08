void setup() {
  // put your setup code here, to run once:kx-9
Serial.begin(9600);
pinMode(4,OUTPUT);
pinMode(5,INPUT);
}

void loop()
{  // put your main code here, to run repeatedly:
digitalWrite(4,LOW);
delayMicroseconds(5);
digitalWrite(4,HIGH);
delayMicroseconds(10);
double dur = pulseIn(5,HIGH);
double dist=343*dur/20000;
Serial.println(dist);
}
