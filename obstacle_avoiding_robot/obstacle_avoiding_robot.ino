#include <Servo.h>



int int1=12,int2=13,int3=7,int4=8;
int trigPin=4,echoPin=3;
int servoPin=2,pos;
int pingTime;
int sweep=894;
float v=31974;
float x,gap=10;

Servo eyes;

void setup() {

  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);

Serial.begin(9600);

  
  

  
  eyes.attach(servoPin);

  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
}

void loop() {
  pos=90;
  eyes.write(pos);
  Serial.print(pos);
  delay(750);
     
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;

if(x>gap)
  {
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);   //forward
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW);


    Serial.println(" forwad");
    
digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000;


while(x>gap){
      digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000;


  Serial.print("forward  x = ");
  Serial.println(x);
           }
 }


 
if(x<gap)
         {


          digitalWrite(int1,LOW);
    digitalWrite(int2,HIGH);   //forward
    digitalWrite(int3,LOW);
    digitalWrite(int4,HIGH);


    Serial.println(" backward");
    
digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000;


while(x>gap){
      digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000;


  Serial.print("forward  x = ");
  Serial.println(x);
           }
         }
         digitalWrite(int1,LOW);
         digitalWrite(int2,LOW);  //stop
         digitalWrite(int3,LOW);
         digitalWrite(int4,LOW);


         Serial.println(" stop ");


         eyes.write(0);
         delay(750);

       digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;

if(x>gap)
  {
    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,HIGH);  //left
    digitalWrite(int4,LOW);
    
    Serial.println(" sweeping ");
    
   
   delay(sweep);

  

 }


   else 
{



   
    eyes.write(180);
    delay(750);

           digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=v*pingTime/2000000.0;

if(x>gap)
  {
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //right
    digitalWrite(int4,LOW);
    
    delay(sweep);

    // i removed the pos at 90

   
    
    

 }
    

digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //right
    digitalWrite(int4,LOW);
    
    delay(sweep);




    
}   

}
        
         
   
    
       
   
        
       
