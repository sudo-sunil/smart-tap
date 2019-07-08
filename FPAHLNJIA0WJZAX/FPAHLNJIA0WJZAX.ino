//HC RS04 Ultrasonic ranging module
int triggerPort =4;
int echoPort = 5;
float dist;
float arr[8]; 
int i=0, j=0;
int MAX=8;
float dur;
boolean flag = false;
float a,b,c,d,e;
void setup() {
 Serial.begin( 9600 );
pinMode( triggerPort, OUTPUT );
pinMode( echoPort, INPUT );
pinMode(6,OUTPUT);

Serial.println( "Ultrasonic ranging module: ");
 
}
 
void loop() 
{
 
do{
for(i=0;i<5;i++)
{
  digitalWrite(triggerPort,LOW);
delayMicroseconds(5);
digitalWrite(triggerPort,HIGH);
delayMicroseconds(10);
digitalWrite(triggerPort,LOW);
float dur = pulseIn(echoPort,HIGH);
float dist=3.4 * dur/ 200; 
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
      if(d<2){
       //stop the flow
       flag = true;
        for(int i=1;i<5;i++)
        {
          Serial.println("motor1");
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    delay(20);
        } 
        exit(0); 
      }
   }else{
          a=arr[2];
          b=arr[3];
          c=arr[4];
          d=a-b;
          e=b-c;

          if( e<=2){
                  //stop water
                  if(d<2) {
                  flag= true;
                      for(int i=1;i<5;i++)
                       {
                        Serial.println("motor2");
                    digitalWrite(7,HIGH);
                    delay(500);
                    digitalWrite(7,LOW);
                    delay(20);
                      }
                      exit(0);
                  }
               }else{flag=false;}
                 
   }
   
}while(flag==false);
Serial.println("Finish");

/* 
Serial.print("duration: ");
Serial.print(duration);
Serial.print(" , ");
Serial.print("distance: ");
 

if( duration > 38000 ) Serial.println("out of reach");   // if duration in greather than 38ms, the obstacle is out of reach
else { Serial.print(distance); Serial.println("cm");}
 

delay( 1000 ); */             // wait for 1s
}



