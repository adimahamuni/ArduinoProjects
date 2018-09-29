const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)
int x, y, z;
void setup() {
  // initialize the serial communications:
  Serial.begin(9600);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(zpin, INPUT);

}

void loop() {
  // print the sensor values:
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
  x = analogRead(xpin);
  y = analogRead(ypin);
  z = analogRead(zpin);
  delay(100);
 // if ((y <= 330) && (y > 290))
  if(xpin>3353
  {
    Serial.println("clockwise");

  }
  if ((y >= 340) && (y < 390))
  {
    Serial.println("anticlockwise");

  }
  if ((x > 330) && (y > 260) && (z > 330))
  {
    Serial.println("normal");

  }
  if ((x>335)||(x<335))
  {
    if (x > 340)
    {
      Serial.print("moving up");
    }
    if (x < 332)
    {
      Serial.print("moving down");
    }

  }
}
