#include <servo.h>
int Xvr=AO,Yvr=A1;

int SW=13;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  servo1.attach(10);
  servo2.attach(9);
  servo3.attach(6);
  servo4.attach(5);
  servo5.attach(3);
pinMode(servo1,OUTPUT);
pinMode(servo2,OUTPUT);
pinMode(servo3,OUTPUT);
pinMode(servo4,OUTPUT);
pinMode(servo15,OUTPUT);

pinMode(SW,INPUT);
pinMode(Xvr,INPUT);
pinMode(Yvr,INPUT);
serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
