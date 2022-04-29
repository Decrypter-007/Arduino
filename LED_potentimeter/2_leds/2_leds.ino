
int j=4,ontime=500,offtime=500;

void setup() {
  pinMode(j,OUTPUT);

}

void loop() 
  {
 

  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  delay(ontime);
  digitalWrite(8,LOW);
  delay(offtime);
  
}
