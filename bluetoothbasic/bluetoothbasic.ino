#include <SoftwareSerial.h>

SoftwareSerial QuartzBT(10, 11); // RX | TX

int LED = 13;

int val;

void setup()

{

  Serial.begin(9600);

  QuartzBT.begin(9600);

  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");

  pinMode(LED, OUTPUT);

}

void loop()

{

  if (QuartzBT.available()) {

    val = QuartzBT.read();

    if (val == '1') {

      digitalWrite(LED, 1);

      QuartzBT.println("LED  On D07 ON ! ");
      Serial.begin(9600);

    }

    else if (val == '0') {

      digitalWrite(LED, 0);

      QuartzBT.println("LED  On D07 Off ! ");
      Serial.begin(9600);

    }

    else QuartzBT.println("Enter 0 for off or 1 for on :)"); 

  }

}
