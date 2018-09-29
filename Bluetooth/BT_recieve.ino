#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

double rpm, Angle;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
}

void loop() {

  if (Serial1.available()) {
    delay(100);

    while (Serial1.available() > 0) {
      rpm = Serial1.parseInt();
      Angle = Serial1.parseInt();

      Serial.print("RPM :"); Serial.print(rpm);
      Serial.print("Angle :"); Serial.println(Angle);

      lcd.setCursor(0, 1);
      lcd.print("RPM :"); lcd.print(rpm);
      lcd.setCursor(1, 0);
      lcd.print("Angle :"); lcd.print(Angle);
    }
  }
}
