int X=0;;
int Y=0;
int Z=0;




void setup() {
 Serial.begin(115200);
 

}

void loop() {
  X=X+1;
  Y=Y+2;
  Z=Z+4;


  Serial.print(X);
  Serial.print(",");
  
  Serial.print(Y);
  Serial.print(",");
  
 
  Serial.println(Z);
  



delay(200);

  
}
