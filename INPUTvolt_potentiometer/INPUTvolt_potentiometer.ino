int potPin=A0;
int readValue;
int ledPin=11;
float voltage;
int LED;
void setup() {
  pinMode(potPin,INPUT);
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);

}

void loop() {
  
  
  readValue=analogRead(potPin);
  LED=(readValue*150)/255;
  analogWrite(ledPin,LED);
  delay(250);
  Serial.println(LED);
  Serial.println(readValue);
  voltage=readValue*5.0/1023;
  Serial.print("voltage= ");
  Serial.println(voltage);
  

}
