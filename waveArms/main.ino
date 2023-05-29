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

void loop() {
  // reset arms
  myservo1.write(180);
  myservo2.write(180);
  myservo3.write(180);

  // wave the arm 1 from 0 to 180 degrees
  for (pos1 = 0; pos1 <= 180; pos1 += 1) {
    myservo1.write(pos1);
    delay(5);
  }

  delay(10000);

  // wave the arm 1 from 180 to 0 degrees
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) {
    myservo1.write(pos1);
    delay(5);
  }

  delay(3000);

  // wave the arm 2 from 0 to 180 degrees
  for (pos2 = 0; pos2 <= 180; pos2 += 1) {
    myservo2.write(pos2);
    delay(5);
  }

  delay(10000);

  // wave the arm 2 from 180 to 0 degrees
  for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
    myservo2.write(pos2);
    delay(5);
  }

  delay(3000);

  // wave the arm 3 from 0 to 180 degrees
  for (pos3 = 0; pos3 <= 180; pos3 += 1) {
    myservo3.write(pos3);
    delay(5);
  }

  delay(10000);

  // wave the arm 3 from 180 to 0 degrees
  for (pos3 = 180; pos3 >= 0; pos3 -= 1) {
    myservo3.write(pos3);
    delay(5);
  }

  delay(3000);
}
