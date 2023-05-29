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

int pos1 = 0;  // variable to store the servo position
int pos2 = 0;  // variable to store the servo position
int pos3 = 0;  // variable to store the servo position

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 10 to the servo object
  myservo3.attach(11);  // attaches the servo on pin 11 to the servo object
}

void waveArm(Servo servo, int start, int end) {
  // wave the arm from start to end degrees
  for (int pos = start; pos <= end; pos += 1) {
    servo.write(pos);
    delay(5);
  }

  delay(3000);

  // wave the arm from end to start degrees
  for (int pos = end; pos >= start; pos -= 1) {
    servo.write(pos);
    delay(5);
  }

  delay(10000);
}

void loop() {
  // reset arms
  myservo1.write(180);
  myservo2.write(180);
  myservo3.write(180);

  waveArm(myservo1, 0, 180);
  waveArm(myservo2, 180, 0);
  waveArm(myservo3, 180, 0);
}
