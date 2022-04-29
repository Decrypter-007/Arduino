#include <IRremote.h>
#include <Servo.h>

long Go_Forward = 0x00FF18E7;
long Left_Rotate =  0x00FF5AA5;
long Right_Rotate = 0x00FF10EF;

long Go_Back = 0x00FF4AB5;
long Stand_Stop = 0x00FF38C7;

Servo myservo;  // create servo object to control a servo
int pos = 0;        
long timeDelay;

int LED = 3; //

int input1 = 6; //
int input2 = 5; // 
int input3 = 8; //
int input4 = 7; // 

int RECV_PIN = 2;//
IRrecv irrecv(RECV_PIN);
decode_results results;
  
  
void setup() {  
Serial.begin (9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  
irrecv.enableIRIn(); //

pinMode(input2,OUTPUT);  
pinMode(input1,OUTPUT);  
pinMode(input3,OUTPUT);  
pinMode(input4,OUTPUT); 

pinMode(LED,OUTPUT);  

}  
  
void loop() {  
   digitalWrite(LED,LOW);     
  if (irrecv.decode(&results)){ 
    
       Serial.println(results.value);  
    
    if(results.value == 4211107991){
       Serial.println("Go_Forward");  
       digitalWrite(LED,HIGH);  //   
       delay(50); 
       digitalWrite(LED,LOW);  //  

       
        digitalWrite(input1,HIGH); //  
        digitalWrite(input2,LOW);  //
        digitalWrite(input3,HIGH); // 
        digitalWrite(input4,LOW);  //    
      }

    if(results.value == 4211084021){
             Serial.println("Left_Rotate");  
                    digitalWrite(LED,HIGH);  //   
       delay(50); 
       digitalWrite(LED,LOW);  //  
       
        digitalWrite(input1,HIGH); //
        digitalWrite(input2,LOW);  //
        digitalWrite(input3,LOW); //
        digitalWrite(input4,HIGH);  // 

        
      }   
    if(results.value == 4211116151){
                   Serial.println("Right_Rotate");  

                          digitalWrite(LED,HIGH);  //   
       delay(50); 
       digitalWrite(LED,LOW);  //  
       
        digitalWrite(input1,LOW); //
        digitalWrite(input2,HIGH);  //
        digitalWrite(input3,HIGH); //
        digitalWrite(input4,LOW);  // 
        
      }   

    if(results.value == 4211092181){
     Serial.println("up");    

            digitalWrite(LED,HIGH);  //   
       delay(50); 
       digitalWrite(LED,LOW);  //  
  
       pos = 45  ;                             
       myservo.write(pos);                        // tell servo to go to position in variable 'ONpos'
       delay(15);                                        // randomize wait time for the servo to reach the position
    
     
      }
    if(results.value == 4211124311){
     Serial.println("down");    

            digitalWrite(LED,HIGH);  //   
       delay(50); 
       digitalWrite(LED,LOW);  //  
       pos = 89  ;                             
       myservo.write(pos);                        // tell servo to go to position in variable 'ONpos'
       delay(15);      
     
     
      }
    
    
    
    if(results.value == 4211099831){
         Serial.println("Stop");  
       digitalWrite(LED,HIGH);  //   
       delay(50); 
       digitalWrite(LED,LOW);  //  
         
        digitalWrite(input1,LOW); //
        digitalWrite(input2,LOW);  //
        digitalWrite(input3,LOW); //
        digitalWrite(input4,LOW);  // 
      }   

    if(results.value == 4211110031){

             digitalWrite(LED,HIGH);  //   
       delay(50); 
       digitalWrite(LED,LOW);  //  
       
         Serial.println("back");  
        digitalWrite(input1,LOW); //  
        digitalWrite(input2,HIGH);  //
        digitalWrite(input3,LOW); // 
        digitalWrite(input4,HIGH);  //    
      }   
      
    irrecv.resume();
    }   
  
}


 

 
 
