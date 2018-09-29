#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define dir 17
#define pull 16
int led = 13;
char x, y;
int flag;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(9, OUTPUT);
  analogWrite(9, 100);
  pinMode(dir, OUTPUT);
  pinMode(pull, OUTPUT);
  digitalWrite(dir, LOW);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
  lcd.clear();
  flag = 1;
  lcd.write("Connecting");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  { x = Serial.read();
    y = Serial.read();
    Serial1.write(x);
  //  Serial1.write("\t");
//    Serial1.write(y);
  //  Serial1.write("\n");

    if (flag == 1)
    { lcd.clear();
      lcd.setCursor(0, 0);
      lcd.write("Connected");
      flag = 0;
    }

    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.write("x=");
    lcd.setCursor(3, 1);
    lcd.write(x);
    lcd.setCursor(7, 1);
    lcd.write("y=");
    lcd.setCursor(10, 1);
    lcd.write(y);
    int newy = 120 - y;
    if (y > 0)
    { 
      digitalWrite(dir, LOW);
     for (int i = 0; i < (abs(newy) * 66); i++)
      { 
        digitalWrite(pull, LOW);
        delayMicroseconds(1500);
        digitalWrite(pull, HIGH);
        delay(1);

      }
      lcd.setCursor(0, 0);
      lcd.write("done");

    }
    if (y < 0)
    { 
      digitalWrite(dir, HIGH);
      for (int i = 0; i < (abs(newy) * 66); i++)
      {
        digitalWrite(pull, LOW);
        delayMicroseconds(1500);
        digitalWrite(pull, HIGH);
        delay(1);
      }
      lcd.setCursor(0, 0);
      lcd.write("done");

    }

  }

}
