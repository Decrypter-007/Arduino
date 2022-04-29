#include <Servo.h>
 int powerPin=8;
int pos;
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
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;
  Serial.print("value = ");
  Serial.println(x);

  

    while(x<15){
      digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;
  Serial.print("value = ");
  Serial.println(x);
      
      }
  
        }

     
 
      
      
    
        
        
          for(pos;pos>=0;pos=pos-1)
        {
        eyes.write(pos);
         digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;
  Serial.print("value = ");
  Serial.println(x);

  

    while(x<15){
      digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;
  Serial.print("value = ");
  Serial.println(x);
      
      }
  
        
         
         }
        
       
     }
    
