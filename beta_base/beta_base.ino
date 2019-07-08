#include <Servo.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "water-20e5f.firebaseio.com"
#define FIREBASE_AUTH "t4Fxu1fJW09hDOXh2k23b4vDYPEhRiJJyJCmDXLn"
#define WIFI_SSID "sunil's laptop"
#define WIFI_PASSWORD "12345678"
Servo servo;  // create servo object to control a servo  // twelve servo objects can be created on most boards             
int pos = 0;    // variable to store the servo position
int triggerPort =14;
int echoPort = 12;
double arr[8]; 
int i=0,flag=0;

//boolean flag = false;
double a,b,c,d,e;
double dur=0;
double dist=0;
void setup() {
    Serial.begin( 9600 );
    // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    pinMode( triggerPort, OUTPUT );
    pinMode( echoPort, INPUT );
    pinMode(16,OUTPUT);
    servo.attach(16);  // attaches the servo on pin 6 to the servo object  // tell servo to go to position in variable 'pos'
    Serial.println( "Ultrasonic ranging module: ");
    
}


 //int n = 0;
void loop(){ 
 if(Firebase.getString("/tap/status")=="ON")
{
 if(flag==0)
  {
     for (pos = 90; pos >= 0; pos -= 1) 
      { // goes from 180 degrees to 0 degrees
           servo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
      }
  flag=1;
  }
    for(i=0;i<=5;i++)
      {
          digitalWrite(triggerPort,LOW);
          delayMicroseconds(5);
          digitalWrite(triggerPort,HIGH);
          delayMicroseconds(10);
          int dur = pulseIn(echoPort,HIGH);
          float dist = dur*0.034/2; 
          Serial.println(dist);
          arr[i] = dist;
              
          delay(1000);
      } 
      
      a=arr[0];
      b=arr[1];
      c=arr[2];
      d=a-b;
      e=b-c;
      if(e<2)
      {
          if(d<2)
          {//stop the flow
            
              for(pos = 0; pos <= 90; pos += 1)    // command to move from 0 degrees to 180 degrees 
              {                                  
                    servo.write(pos);                 //command to rotate the servo to the specified angle
                    delay(15);                       
              } 
           Firebase.setString("/tap/status","OFF");
             int flag=0;
            // Serial.println("Finish1");
            if(flag==0)
            {
              
              }
           
          }
      }
      else
      {
          a=arr[2];
          b=arr[3];
          c=arr[4];
          d=a-b;
          e=b-c;
          if(e<2)
          {
                  //stop water
                  if(d<2)
                  {
               
                  //Serial.println("motor2");
                   for(pos = 0; pos <=90; pos += 1)    // command to move from 0 degrees to 180 degrees 
                  {                                  
                      servo.write(pos);                 //command to rotate the servo to the specified angle
                      delay(15);                       
                  } 
                   Firebase.setString("/tap/status","OFF");
                   
                   int flag=0;
                //   Serial.println("Finish2");
                  
                  }
           }
              
   }
//  Serial.println("*******",arr[4]);
 // Firebase.setFloat("height",arr[4]);
//  Serial.println("Finish3");




}
}



