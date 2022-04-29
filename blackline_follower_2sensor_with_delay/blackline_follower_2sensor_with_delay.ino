int int1=11,int2=10,int3=9,int4=6;
int L,R;
int left=12,right=13;




int sweep=250;




void setup() {

  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  

Serial.begin(9600);

  pinMode(left,INPUT);
  
  pinMode(right,INPUT);

  
}

void loop() {
  
   L=digitalRead(left);
   
   R=digitalRead(right);


   if(L==1&&R==1)
   {
   
   
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);   //forward
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW);

    delay(sweep);
   
   }


    Serial.println(" forwad");
    
     if(L==0&&R==1)
   {
   
   
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);  //left
    digitalWrite(int4,LOW);
    
    delay(sweep);
   
   
   
   }



  if(L==1&&R==0)
  {
    

    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,HIGH);  //right
    digitalWrite(int4,LOW);

    delay(sweep);
  }

 if(L==0&&R==0)
   {
   
   
    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);   //forward
    digitalWrite(int3,LOW);
    digitalWrite(int4,LOW);

    delay(sweep);
   
   }
   
}
       
   
