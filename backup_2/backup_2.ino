#include <Servo.h>
Servo servo;  // create servo object to control a servo  // twelve servo objects can be created on most boards             
int pos = 0;    // variable to store the servo position
int triggerPort =4;
int echoPort = 5;
float arr[8]; 
int i=0;
boolean flag = false;
float a,b,c,d,e;

void setup() {
    Serial.begin( 9600 );
    pinMode( triggerPort, OUTPUT );
    pinMode( echoPort, INPUT );
    pinMode(6,OUTPUT);
    servo.attach(6);  // attaches the servo on pin 6 to the servo object  // tell servo to go to position in variable 'pos'
    Serial.println( "Ultrasonic ranging module: ");
    
}
 
void loop(){ 
       for (pos = 90; pos >= 0; pos -= 1) 
      { // goes from 180 degrees to 0 degrees
           servo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
      }
  do{

      for(i=0;i<5;i++)
      {
          digitalWrite(triggerPort,LOW);
          delayMicroseconds(5);
          digitalWrite(triggerPort,HIGH);
          delayMicroseconds(10);
          float dur = pulseIn(echoPort,HIGH);
          float dist = 3.4 * dur/ 200; 
          Serial.println(dist);
          arr[i] = dist;
          delay(1000);
      }
      a=arr[0];
      b=arr[1];
      c=arr[2];
      d=a-b;
      e=b-c;
      if(e<=2)
      {
          if(d<2)
          {//stop the flow
              flag = true;
              //Serial.println("mitor1");
              for(pos = 0; pos <= 90; pos += 1)    // command to move from 0 degrees to 180 degrees 
              {                                  
                    servo.write(pos);                 //command to rotate the servo to the specified angle
                    delay(15);                       
              } 
             // myservo.write(90); 
             Serial.println("Finish");
             exit(0); 
          }
      }
      else
      {
          a=arr[2];
          b=arr[3];
          c=arr[4];
          d=a-b;
          e=b-c;
          if(e<=2)
          {
                  //stop water
                  if(d<2)
                  {
                  flag= true;
                  //Serial.println("motor2");
                   for(pos = 0; pos < 90; pos += 1)    // command to move from 0 degrees to 180 degrees 
                  {                                  
                      servo.write(pos);                 //command to rotate the servo to the specified angle
                      delay(15);                       
                  } 
                   Serial.println("Finish");
                   exit(0);
                  }
           }
           else{flag=false;}      
   }
  }while(flag==false);
  Serial.println("Finish");
}



