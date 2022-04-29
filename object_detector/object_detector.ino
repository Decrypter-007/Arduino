#include <Servo.h>
 int powerPin=8;
int pos,p;
int servoPin=9;
int trigPin=13;
int echoPin=6;
float pingTime;
float v=31974;
float x;
Servo eyes;

void setup() {
  Serial.begin(9600);
 eyes.attach(servoPin);
 pinMode(powerPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(trigPin,OUTPUT);
 digitalWrite(powerPin,HIGH);
 
 

}

void loop() {
  

 
      
      
  
    
    
    
        for(pos=0;pos<=180;pos=pos+1)
        {
        eyes.write(pos);
         digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delay(5);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  
  if(pingTime<35000&&pingTime>125)
 { x=v*pingTime/2000000.0;}
  Serial.print("value = ");
  Serial.println(x);

  

    while(x<25){
      digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delay(5);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);

  if(pingTime<35000&&pingTime>125)
  {x=v*pingTime/2000000.0;}
  Serial.print("value = ");
  Serial.println(x);
      
      }
  
        }

     
 
      
      
    
        
        
          for(pos;pos>=0;pos=pos-1)
        {
        eyes.write(pos);
         digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delay(5);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);

if(pingTime<35000&&pingTime>125)
 
 { x=v*pingTime/2000000.0;}
  Serial.print("value = ");
  Serial.println(x);

  

    while(x<25){
      digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delay(5);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);

  if(pingTime<35000&&pingTime>125)
  {
  x=v*pingTime/2000000.0;}
  Serial.print("value = ");
  Serial.println(x);
      
      }
  
        
         
         }
        
       
     }
    
