



int int1=12,int2=13,int3=7,int4=8;
int L,M,R;
int left=11,middle=10,right=9;


int sweep=250;

void setup() {

  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  

Serial.begin(9600);

  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(middle,INPUT);

 
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
    digitalWrite(int2,HIGH);
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
    digitalWrite(int4,HIGH);

    while(R!=0)
    {
      R=digitalRead(right);
    }
    
    }

   }
      
        
 if(L==0&&R==1)
 {
  if(M==0)
  {
    
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //right
    digitalWrite(int4,LOW);

    delay(sweep);
      
  }
 }
   
    if(R==0&&L==1)
 {
  if(M==0)
  {
    
    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,HIGH);      //left
    digitalWrite(int4,LOW);

    delay(sweep);
      
  }
 }


}
   
       
   
        
       
