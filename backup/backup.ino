#include <Servo.h>
Servo servo;  // create servo object to control a servo  // twelve servo objects can be created on most boards             
int pos = 0;    // variable to store the servo position
int triggerPort =4;
int echoPort = 5;
long arr[8]; 
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
  do{
       for (pos = 90; pos >= 0; pos -= 1) 
      { // goes from 180 degrees to 0 degrees
           servo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
      }
      for(i=0;i<5;i++)
      {   //collecting reading of udm in an array
          digitalWrite(triggerPort,LOW);
          delayMicroseconds(5);
          digitalWrite(triggerPort,HIGH);
          delayMicroseconds(10);
          //digitalWrite(triggerPort,LOW);
          float dur = pulseIn(echoPort,HIGH);
          float dist=3.4 * dur/ 200; 
          Serial.println(dist);
          arr[i] = dist;
          delay(1000);
      }
      a=arr[0];  //storing first three value of an array in it for comparing first three value
      b=arr[1];
      c=arr[2];
      d=a-b;
      e=b-c;
      if(e<=2)
      {
          if(d<2)
          {//stop the flow
              flag = true;
              Serial.println("motor1");
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
          if( e<=2)
          {
                  //stop water
                  if(d<2)
                  {
                  flag= true;
                  Serial.println("motor2");
                  for(pos = 0; pos < 90; pos += 1)    // command to move from 0 degrees to 180 degrees 
                  {                                  
                      servo.write(pos);                 //command to rotate the servo to the specified angle
                      delay(15);                       
                  } 
                  //myservo.write(90);  
                      /*for(int i=1;i<5;i++)
                       {
                        Serial.println("motor2");
                    digitalWrite(7,HIGH);
                    delay(500);
                    digitalWrite(7,LOW);
                    delay(20);
                      }*/
                   Serial.println("Finish");
                   exit(0);
                  }
           }
           else{flag=false;}      
   }
  }while(flag==false);
  Serial.println("Finish");
}



