#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX



void setup() {

  mySerial.begin(38400);
 
  mySerial.print(String("200")); mySerial.print('"');
  mySerial.print(String("15")); mySerial.print('"');
  mySerial.print(String("15")); 
}

void loop() {}
