/*


*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String message; //string that stores the incoming message
void setup() {
  // Open serial communications and wait for port to open:
  // Serial.begin(9600);
  Serial.begin(9600);
  Serial3.begin(9600);
  //  pinMode(A0, OUTPUT);
  //  pinMode(12, OUTPUT);
  //  pinMode(11, OUTPUT);
  //  pinMode(5, OUTPUT);
  //  pinMode(4, OUTPUT);
  //  pinMode(3, OUTPUT);
  //  pinMode(2, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 4);
  pinMode(A0, OUTPUT);
  analogWrite(A0, 100);
  // Print a message to the LCD.
  


}

void loop() {
  //lcd.setCursor(4, 0);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  
  // run over and over



  while(Serial3.available())

  { char x = Serial3.read();
    if (x == 'A')
    { int y = (int)Serial3.parseInt();
      Serial.print("RPM= ");
      Serial.print(y);
      lcd.setCursor(0, 0);
      lcd.print("RPM = ");
      lcd.setCursor(6, 0);
      lcd.print(y);
      break;
    }
    if (x == 'B')
    { int y = (int)Serial3.parseInt();
      Serial.print("RPM= ");
      Serial.print(y);
      lcd.setCursor(1, 0);
      lcd.print("RPM2 = ");
      lcd.setCursor(6, 1);
      lcd.print(y);
      break;
    }
    if (x == 'C')
    { int y = (int)Serial3.parseInt();
      Serial.print("RPM= ");
      Serial.print(y);
      lcd.setCursor(2, 0);
      lcd.print("RPM2 = ");
      lcd.setCursor(6, 1);
      lcd.print(y);
   break;
    }
    else
    {
      Serial.print(Serial3.read());
    }




  }


}
/*if (Serial3.available()) {

  Serial.println( Serial3.available() );
  // lcd.clear();
  if(Serial3.available()==3)//(Serial3.available()>50 && Serial3.available()<100)
  {
   Serial.print("\t RPM");
  lcd.setCursor(0, 0);
  lcd.print("RPM: ");
  lcd.setCursor(4, 0);
  lcd.print(Serial3.read());
  //delay(500);
  }
  else  if(Serial3.available()==2)//(Serial3.available()>10 && Serial3.available()<20)
  {
   Serial.println("\t ANGLE");
  lcd.setCursor(0, 1);
  lcd.print("ANGLE:");
  lcd.setCursor(6, 1);
  lcd.print(Serial3.read());
  // delay(500);
  }

  else if(Serial3.available()==1)//(Serial3.available()<20 && Serial3.available()<50)
  {
   Serial.println("\t SA");
  lcd.setCursor(7, 0);
  lcd.print("SA:");
  lcd.setCursor(10, 0);
  lcd.print(Serial3.read());
  //delay(500);
  }
  // Serial.println(me ssage);
  }/*
  if (Serial3.available()) {
  message+=char(Serial3.read());
   lcd.print( message);
   //Serial.println(message);
   delay(20);
  }
*/
////
/*
  if (Serial3.available()) {
  int inByte = Serial3.read();
  // Serial.write(inByte);
  Serial.println(inByte);
  }
  /*
  // read from port 0, send to port 1:
  if (Serial.available()) {
  int inByte = Serial.read();
  Serial1.write(inByte);
  }
*/




