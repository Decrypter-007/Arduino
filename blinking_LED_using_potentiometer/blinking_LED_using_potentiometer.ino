int potPin=A0;
int readValue;
int voltage;
int wait;
void setup() {
  pinMode(potPin,INPUT);
  Serial.begin(9600);
  

}

void loop() {
  
  
  readValue=analogRead(potPin);
  
  
  
  Serial.println(readValue);
  
}
