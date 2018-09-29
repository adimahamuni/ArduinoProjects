// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(9, 10); // RX, TX

double rpm;
double Angle_1, Angle_2;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  //  pinMode(A0, OUTPUT);
  //  analogWrite(A0, 100);
  // initialize both serial ports:
  Serial.begin(38400);

  //   while (!Serial) {
  //    ; // wait for serial port to connect. Needed for native USB port only
  //  }
  Serial1.begin(38400);
  //mySerial.begin(38400);
  //  mySerial.begin(38400);
  if (Serial1.available())
    Serial.print("Program Started :");
}

void loop() {

  // read from port 1, send to port 0:
  if (Serial1.available() > 0) {
    //lcd.clear();
    delay(100);

    while (Serial1.available() > 0) {

 rpm = Serial1.parseInt();



      Angle_1 = Serial1.parseInt();
      Angle_2 = Serial1.parseInt();
      Serial.print("RPM :");
      Serial.print(rpm);
      Serial.print("\tAngle_1 :");
      Serial.print(Angle_1);
      Serial.print("\tAngle_2 :");
      Serial.println(Angle_2);

      lcd.setCursor(0, 0);
      lcd.print("RPM:"); lcd.print(rpm);
      lcd.setCursor(0, 1);
      lcd.print("Angle_1:"); lcd.print(Angle_1);
      lcd.setCursor(0, 2);
      lcd.print("Angle_2:"); lcd.print(Angle_2);
    }

  }
}
