#include <StopWatch.h>
StopWatch MySW(StopWatch::MICROS);
StopWatch tymer(StopWatch::MILLIS);

#define interruptPin 2
#define START_POINT 3
#define END 18SE

double tym = 1;
double rpm, rps;
String RPM;
int counter = 0;

unsigned long Time, startTime, endTime;
double d = 200;
int total = 0;
boolean startP =  false, endP =  false;
int rheoanalog = A0;
int rheodigital = 22;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Program Started");
  Serial3.begin (9600);

  //IR-------
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), incrementCounter, RISING);
  attachInterrupt(digitalPinToInterrupt(END), endHere, RISING);
  attachInterrupt(digitalPinToInterrupt(START_POINT), start1, RISING);

  //  tymer.start();

  //Proximity---------
  pinMode(START_POINT, INPUT);
  pinMode(END, INPUT);
  pinMode(rheodigital, OUTPUT);
  pinMode(rheoanalog, INPUT);
  digitalWrite(rheodigital, HIGH);
}

void loop() {
  //Serial.print(digitalRead(interruptPin));
  //  attachInterrupt(digitalPinToInterrupt(END), endHere, RISING);
  //  attachInterrupt(digitalPinToInterrupt(START_POINT), start1, RISING);

}

void incrementCounter() {
  counter ++;
  //  Serial.print("Count : ");
  //  Serial.println(counter);
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  if (counter == 1)
    MySW.start();
  if (counter >= 2) {
    tym = MySW.elapsed();
    rpm = (60000000 / tym) ;
    //  Serial.print("\t RPM : ");
    //  Serial.println(rpm);
    Serial3.print(String(rpm)); Serial3.print('"');

    counter = 0;
    MySW.reset();
  }
  attachInterrupt(digitalPinToInterrupt(interruptPin), incrementCounter, RISING);
}

void start1() {
  //  if (startP == false) {
  // mySW.reset();
  Serial.print("Start ");
  detachInterrupt(digitalPinToInterrupt(START_POINT));
  tymer.start();
//  attachInterrupt(digitalPinToInterrupt(END), endHere, RISING);
  //    startP = true;
  //  }
}

void endHere() {
  //  if (startP) {
  detachInterrupt(digitalPinToInterrupt(END));
  endTime = tymer.elapsed();
  tymer.stop();
  tymer.reset();
  Serial.print(" Time: "); Serial.print(endTime);
  //  Time = endTime - startTime;
  //  Serial.print("Time: "); Serial.print(Time);
  Serial.print("\t\t\t\tVelocity : "); Serial.print((d / endTime)/* * 1000*/); Serial.println(" m/s");
  endTime = 0;
  startP = false;
  attachInterrupt(digitalPinToInterrupt(END), endHere, RISING);
  attachInterrupt(digitalPinToInterrupt(START_POINT), start1, RISING);
  //  }
}
