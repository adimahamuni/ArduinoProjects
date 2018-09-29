void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial1.print(String("590")); Serial1.print('"');
  Serial1.print(String("15"));
}

void loop() {

}
