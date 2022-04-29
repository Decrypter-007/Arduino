int trigPin=13;
int echoPin=11;
int pingTime;
float v=31974;
float x;



void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(11,INPUT);
  

}

void loop() {
  digitalWrite(13,LOW);
  delayMicroseconds(2000);
  digitalWrite(13,HIGH);
  delay(10);
  digitalWrite(13,LOW);
  pingTime=pulseIn(echoPin,HIGH);
  Serial.println(pingTime);
  x=31974*pingTime*500000.0;
  Serial.print(" x = " );
  Serial.println(x);
  delay(2000);

}
