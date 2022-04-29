int reader=9;
int power=8;



void setup() {
  Serial.begin(9600);
  pinMode(reader,INPUT);
  pinMode(power,OUTPUT);
  digitalWrite(power,HIGH);

}

void loop() {
  int x=digitalRead(reader);
  
Serial.println(x);
delay(100);
}
