#include <StopWatch.h>
StopWatch MySW(StopWatch::MILLIS);

int interruptPin = 2;
int counter = 0;
double tym = 1;
double rpm, rps;
int x;
volatile int count = 0;

void setup() {
  Serial.begin(9600);           // start serial for output
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), increment, RISING);

}

void loop() {

}

void increment()
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 10ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 5)
  {
    counter ++;
    Serial.print("Count : ");
    Serial.println(counter);
    detachInterrupt(digitalPinToInterrupt(interruptPin));
    if (counter == 1)
      MySW.start();
    if (counter >= 25) {
      tym = MySW.elapsed();
      rpm = (60000 / tym) ;
      Serial.print("\t RPM : ");
      Serial.println(rpm);
      counter = 0;
      MySW.reset();
    }
    attachInterrupt(digitalPinToInterrupt(interruptPin), increment, RISING);
  }
}
