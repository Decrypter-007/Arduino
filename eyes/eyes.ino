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
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;
  Serial.print(" x = " );
  Serial.println(x);
  
  if(x<15)
  {
    
    
  }
  else
  {
    for(pos=5;pos<175;pos=pos+1)
    {
      eyes.write(pos);
      delay(5);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;
  Serial.print(" x= ");
  Serial.println(x);
  
      if(x<15)
      break;
 
    
    for(pos=175;pos>5;pos=pos-1)
    {
      eyes.write(pos);
      delay(5);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;
  Serial.print(" x= ");
  Serial.println(x);
  
      if(x<15)
      break;
 
    }
    
    
  }
  }
}
