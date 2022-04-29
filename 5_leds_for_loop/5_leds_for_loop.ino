int ontime=500,offtime=500,j;
void setup() {
pinMode(j,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int j=1;
  while(j<=5)
{
digitalWrite(j,HIGH);
delay(ontime);
digitalWrite(j,LOW);
delay(offtime);
j++;

}
}
