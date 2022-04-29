



int int1=11,int2=10,int3=9,int4=6;
int L,M,R;
int left=12,middle=8,right=13;




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


   if(L==1&&R==1)
   {
   if(M==0)
   {
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);   //forward
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW);
    
   }
   }


    
    
   if(R==1&&L==0)
   {
   if(M==1)
   {

    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //left
    digitalWrite(int4,LOW);
    
    Serial.println(" hey ");
    
    delay(sweep);
   
   
   }
   }


     if(R==1&&L==0)
   {
   if(M==0)
   {

    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //left
    digitalWrite(int4,LOW);
    

    
    delay(sweep);
   
   
   }
   }



   if(L==1&&R==0)
  {
    if(M==1)
    {

    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,HIGH);  //right
    digitalWrite(int4,LOW);

   delay(sweep);
    
    }

      
    }


    if(L==1&&R==0)
  {
    if(M==0)
    {

    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,HIGH);  //right
    digitalWrite(int4,LOW);

   delay(sweep);
    
    }

      
    }

    if(L==1&&R==1)
    {
      if(M==1)
      {
      
    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //left
    digitalWrite(int4,LOW);
    

   

      }
    }  
        
          


}
       
   
        
       
