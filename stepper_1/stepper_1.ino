#include <Stepper.h>

const float steps_per_rev=32;
const float steps_red_rev=64;

const float steps_out=steps_per_rev*steps_red_rev;





  Stepper stepperMotor(steps_per_rev,8,10,9,11);
  

void setup() {

  
  
Serial.begin(9600);
}

void loop() {
int i;
for(i=1;i<900;i=i+1){
  stepperMotor.setSpeed(i);

int  stepsRequired=1;
  stepperMotor.step(-stepsRequired);
  Serial.println(i);
}
  
  
}
