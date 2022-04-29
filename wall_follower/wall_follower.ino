int int1=12,int2=13,int3=7,int4=8;
int L,M,R;
int left=11,middle=10,right=9;

int trigPinL=2,echoPinL=3;  //left US X
int trigPinR=4,echoPinR=5;  //right US Y


int pingTimeL,pingTimeR;
int sweep=250;
float v=31974;
float X,Y,gap=10;




void setup() {
  // put your setup code he

}

void loop() {

  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


  if(X>gap&&Y>gap)
  {

    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);   //forward
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW);

  
 while(X>gap&&Y>gap)
 {
  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


  
 }

    
  }

  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


    if(X<gap&&Y>gap)
  {

    digitalWrite(int1,LOW);
    digitalWrite(int2,HIGH); //R is reversed          //turning right
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW); //L is  forward

  
 while(X<gap&&Y>gap)
 {
  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


  
 }

    
  }



  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


    if(X>gap&&Y<gap)
  {

    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);   //R is reversed          //turning left
    digitalWrite(int3,LOW);
    digitalWrite(int4,HIGH);  //L is  forward

  
 while(X>gap&&Y<gap)
 {
  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


  
 }

    
  }



    digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


    if(X<gap&&Y>gap)
  {

    digitalWrite(int1,LOW);
    digitalWrite(int2,HIGH); //R is reversed          //turning right
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW); //L is  forward

  
 while(X<gap&&Y>gap)
 {
  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


  
 }

    
  }


   digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;

  if(X<gap&&Y<gap)
  {
 
 
    digitalWrite(int1,LOW);
    digitalWrite(int2,HIGH); //R is reversed          //rotating on its axis as clockwise
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW); //L is  forward
   
    delay(sweep);

  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;
  
  
if(X>gap&&Y>gap)
   
{

}
 else
{
    digitalWrite(int1,LOW);
    digitalWrite(int2,HIGH); //R is  forward          //rotating on its axis as anticlockwise
    digitalWrite(int3,LOW);
    digitalWrite(int4,HIGH); //L is  reversed
   
    delay(2*sweep);

  digitalWrite(trigPinL,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinL,HIGH);   //scanning from left US
  delay(10);
  digitalWrite(trigPinL,LOW);
  pingTimeL=pulseIn(echoPinL,HIGH);
  Serial.println(pingTimeL);
  X=v*pingTimeL/2000000.0;

 
  digitalWrite(trigPinR,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPinR,HIGH);
  delay(10);
  digitalWrite(trigPinR,LOW);      //scanning from right US
  pingTimeR=pulseIn(echoPinR,HIGH);
  Serial.println(pingTimeR);
  Y=v*pingTimeR/2000000.0;


  if(X>gap&&Y>gap)
  {

  }

  
}

   
  
}

}
