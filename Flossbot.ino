/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo torso;  // create servo object to control a servo
Servo right;
Servo left;
// twelve servo objects can be created on most boards

int right_pos = 38;//start back
int left_pos = 78;//start back
int torso_pos = 70;

const int del = 10;

void setup() {
  //myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  torso.attach(9);
  right.attach(11);
  left.attach(10);

  torso.write(torso_pos); //70 middle start position
  right.write(right_pos); //38 arm down 
  left.write(left_pos); //78 arm down

  arms_forwards(80, 40);
}

void arms_forwards(int right_end, int left_end) {
  while(!((right_pos == right_end) && (left_pos == left_end)))
  {
    if(right_pos < right_end)
    {
      right_pos++;
    }
    if(left_pos > left_end)
    {
      left_pos--;
    }
    right.write(right_pos);
    left.write(left_pos);
    delay(del);
  }
}

void arms_backwards(int right_end, int left_end) {
  while(!((right_pos == right_end) && (left_pos == left_end)))
  {
    if(right_pos > right_end)
    {
      right_pos--;
    }
    if(left_pos < left_end)
    {
      left_pos++;
    }
    right.write(right_pos);
    left.write(left_pos);
    delay(del);
  }
}

void torso_right(int end_pos) {
  while(!(torso_pos == end_pos))
  {
    if(torso_pos > end_pos)
    {
      torso_pos--;
    }
    torso.write(torso_pos);
    delay(del);
  }
}

void torso_left(int end_pos) {
  while(!(torso_pos == end_pos)) {
    if(torso_pos < end_pos) {
      torso_pos++;
    }

    torso.write(torso_pos);
    delay(del);
  }
}
void loop() { 
  /*
  torso.write(70); //90 left - 50 right
  right.write(38); //80 forward - 0 back
  left.write(78); //40 forward - 130 back
  */

  torso_left(110);
  arms_backwards(0, 130);
  arms_forwards(80, 40);
  torso_right(30);
  arms_backwards(0, 130);
  arms_forwards(80, 40);
  
  /*for (pos = start_pos; pos <= end_pos; pos += 1) 
  {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  */
  /*for (pos = start_pos; pos <= end_pos; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  for (pos = end_pos; pos >= start_pos; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }*/
}

