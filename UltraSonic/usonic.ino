
#define trig 7
#define echo 8

int distance;

int duration;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 29) / 2;
  Serial.print("-----------------------");
  Serial.println(distance);
  if (distance <= 17)
  {
    digitalWrite(13, HIGH);
  }
  else
   digitalWrite(13, LOW);
  
}


