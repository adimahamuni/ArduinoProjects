char data;
int button  =13;
int butn;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(button, INPUT);
  digitalWrite(button,LOW);
}

void loop() {
  if (Serial.available() > 0) // Send data only when you receive data:
  {
    data = Serial.read();
  }
  butn = digitalRead(button);
    // put your main code here, to run repeatedly:
    if (butn == HIGH)
    {
      Serial.write('1');
      data = 1;
    }
    else if (butn == LOW)
    {
      Serial.write('0');
      data = 0;
    }
  }
