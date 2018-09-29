#include <StopWatch.h>
StopWatch MySW(StopWatch::MICROS);

#define trig_1 4
#define echo_1 5

#define trig_2 6
#define echo_2 7

long Start_dur, Dist_1, Dist_2;
long End_dur, cm2;
long distance, duration;
unsigned long tym = 1, last_tym = 1;
double d = 150;
boolean Start = false;
void setup() {
  Serial.begin(9600);
  Serial.println("Program Started");
  // Ultrasonic....
  pinMode(trig_1, OUTPUT);
  pinMode(echo_1, INPUT);
  pinMode(trig_2, OUTPUT);
  pinMode(echo_2, INPUT);
}

void loop() {
  Sensor(trig_1, echo_1);
  Dist_1 = distance;
  Sensor(trig_2, echo_2);
  Dist_2 = distance;

  //      Serial.print("First Reading :"); Serial.print(Dist_1); Serial.print("  cm");
  //      Serial.print("\t\tSecond Reading :"); Serial.print(Dist_2); Serial.println("  cm");

  if (Dist_1 < 15) {
    if (!Start) {
      MySW.reset();
      MySW.start();
      Start = true;
    }
    //  Serial.print("Start :");
  }
  if (Dist_2 < 15) {
    tym = MySW.elapsed();
    //    last_tym = tym;
    if (Start) {
      //  Serial.print("\t End :");
      Serial.print(" Time: "); Serial.print(tym);
      Serial.print(" Velocity : "); Serial.print((d / tym) * 1000); Serial.println(" m/s");
      MySW.stop();
      tym = 0;
      Start = false;
      delay(3000);
    }
  }
}

void Sensor(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH, 25000);
  distance = (duration / 2) / 29.1;
}
//long Distance(long microseconds) {
//  //  Serial.print(microseconds / 29 / 2);
//  return microseconds / 29.1 / 2;
//
//}

