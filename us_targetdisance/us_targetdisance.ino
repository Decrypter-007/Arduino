int trigPin=4;
int echoPin=3;
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
  x=v*pingTime/2000000.0;
  Serial.print(" x = " );
  Serial.println(x);
  delay(2000);

}
