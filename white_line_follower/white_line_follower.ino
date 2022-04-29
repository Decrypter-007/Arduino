



int int1=12,int2=13,int3=7,int4=8;
int L,M,R;
int left=11,middle=10,right=9;

int trigPinL=2,echoPinL=3;  //left US X
int trigPinR=4,echoPinR=5;  //right US Y


int pingTimeL,pingTimeR;
int sweep=250;
float v=31974;
float X,Y,gap=6;



void setup() {

  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  

Serial.begin(9600);

  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(middle,INPUT);

  pinMode(echoPinR,INPUT);
  pinMode(trigPinR,OUTPUT);

  pinMode(echoPinL,INPUT);
  pinMode(trigPinL,OUTPUT);
}

void loop() {
  
   L=digitalRead(left);
   M=digitalRead(middle);
   R=digitalRead(right);


   if(L==0&&R==0)
   {
   if(M==1)
   {
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);   //forward
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW);
    
   }
   }


    Serial.println(" forwad");
    
     if(L==1&&R==0)
   {
   if(M==1)
   {
     digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,HIGH);  //left
    digitalWrite(int4,LOW);
    
    Serial.println(" sweeping ");

    
    while(L=!0)
    {
      L=digitalRead(left);
    }
   
   
   }
   }



  if(L==0&&R==1)
  {
    if(M==1)
    {

    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //right
    digitalWrite(int4,LOW);

    while(R!=0)
    {
      R=digitalRead(right);
    }
    
    }

      
    }

    if(L==1&&R==1)
    {
      if(M==0)
      {

     digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //right
    digitalWrite(int4,LOW);

    while(L!=0&&R!=0)
    {
      L=digitalRead(left);
      R=digitalRead(right);
    }
    }
        
        
        
        
        }
      

    if(L==0&&R==0)
    {
      if(M==0)
      {
        while(M!=1)
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


        
      }

 }
    
    if(L==1&&R==1)
    {
      if(M==1)
      {
        while(M!=0)
        {

    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //right
    digitalWrite(int4,LOW);


        }


        
      }





    
}   

}
        
         
   
    
       
   
        
       
