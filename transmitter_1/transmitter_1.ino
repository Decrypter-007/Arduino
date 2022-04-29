#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);

const byte address[6]="00001";



void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  
  radio.stopListening();

}

void loop() {
  const char text[]="hello world";
  radio.write(&text,sizeof(text));
  delay(100);

}
