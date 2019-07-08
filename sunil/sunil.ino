//HC RS04 Ultrasonic ranging module
int triggerPort = 7;
int echoPort = 8;
 
void setup() {
 
pinMode( triggerPort, OUTPUT );
pinMode( echoPort, INPUT );
Serial.begin( 115200 );
Serial.println( "Ultrasonic ranging module: ");
 
}
 
void loop() {
digitalWrite(triggerPort, LOW);			// set to LOW trigger's output
digitalWrite(triggerPort, HIGH);		// send a 10us pulse to the trigger
delayMicroseconds( 10 );
digitalWrite(triggerPort, LOW);
 
long duration = pulseIn(echoPort, HIGH);
 
long r = 3.4 * duration / 2;			// here we calculate the distance using duration

float distance = r / 100.00;

 
Serial.print("duration: ");
Serial.print(duration);
Serial.print(" , ");
Serial.print("distance: ");
 

if( duration > 38000 ) Serial.println("out of reach");		// if duration in greather than 38ms, the obstacle is out of reach
else { Serial.print(distance); Serial.println("cm");}
 

delay( 1000 );							// wait for 1s
}
