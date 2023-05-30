/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 10 to the servo object
  myservo3.attach(11);  // attaches the servo on pin 11 to the servo object
}

int waveArm(Servo servo, int start, int end, int delayTime, int handUpTime, int handDownTime) {
  // wave the arm from start to end degrees
  for (int pos = start; pos <= end; pos += 1) {
    servo.write(pos);
    delay(delayTime);
  }

  delay(handUpTime);

  // wave the arm from end to start degrees
  for (int pos = end; pos >= start; pos -= 1) {
    servo.write(pos);
    delay(delayTime);
  }

  delay(handDownTime);

  return ((end - start + 1) * delayTime) + handUpTime + handDownTime;
}

void loop() {
  // reset arms
  myservo1.write(180);
  myservo2.write(180);
  myservo3.write(180);

  // timing
  int startPos = 0;
  int endPos = 180;
  int handUpTime = 3000;
  int handDownTime = 3000;
  int moveDelay = 5;
  int delayTime = ((endPos - startPos + 1) * delayTime) + handUpTime + handDownTime;

  waveArm(myservo1, startPos, endPos, moveDelay, handUpTime, handDownTime);
  delay(delayTime);

  waveArm(myservo2, startPos, endPos, moveDelay, handUpTime, handDownTime);
  delay(delayTime);

  waveArm(myservo3, startPos, endPos, moveDelay, handUpTime, handDownTime);
  delay(delayTime);
}
