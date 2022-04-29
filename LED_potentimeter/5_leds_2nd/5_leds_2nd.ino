
int ontime=500,offtime=500;

void setup() {
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
Serial.begin(9600);
}

void loop() 
  {
 Serial.println("  1st led blinks  ");
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(1,LOW);
 delay(ontime);
 
Serial.println("  2nd led blinks  ");
 digitalWrite(1,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(2,HIGH);
 delay(ontime);

Serial.println("  3rd led blinks  ");
 digitalWrite(2,LOW);
 digitalWrite(1,LOW);
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);
 digitalWrite(3,HIGH);
 delay(ontime);

Serial.println("  4th led blinks  ");
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(1,LOW);
 digitalWrite(5,LOW);
 digitalWrite(4,HIGH);
 delay(ontime);

Serial.println("  5th led blinks  ");
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 digitalWrite(1,LOW);
 digitalWrite(5,HIGH);
 delay(ontime);
}
