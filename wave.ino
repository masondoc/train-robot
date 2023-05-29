/*
 Controlling a servo position on a schedule

 modified on May 29 2023
 by Mason and Chance Smith
 source http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;  // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // wave the arm from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(5);
  }

  delay(10000);

  // wave the arm from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(5);
  }

  delay(3000);
}

