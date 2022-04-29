#include <Servo.h>
int pos=0;
int potPin=A0,readValue;
int servoPin=11;
int servoWait=25;
Servo myPointer;
void setup() {
 Serial.begin(9600);
 myPointer.attach(servoPin);
 

}

void loop() {
  
readValue=analogRead(potPin);
pos=map(readValue,0,900,0,180);
Serial.print(" pos = ");
Serial.println(pos);


myPointer.write(pos);
  
  

  
 
}
