#include <Arduino.h>
#include <Servo.h>

Servo myservo1; // create servo object to control a servo
Servo myservo2; // create servo object to control
Servo myservo3; // create servo object to control
Servo myservo4; // create servo object to control

int pos = 0;    // variable to store the servo position

int motor = 0;  // variable to store the motor
int angle = -1; // variable to store the angle of the motor

// Moves servos smoothly through the list of connected devices and writes them to the serial port
void moveServo(int motor, int angle) {
  if (motor >= 1 && motor <= 4 && angle >= 0 && angle <= 180) {
    Serial.print("Movendo motor ");
    Serial.print(motor);
    Serial.print(" para o ângulo ");
    Serial.println(angle);
  }

  if (motor == 1) {
    if (angle >= myservo1.read()){
      for (pos = myservo1.read(); pos <= angle; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo1.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } else {
      for (pos = myservo1.read(); pos >= angle; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo1.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    }
  } else if (motor == 2) {
    if (angle >= myservo2.read()){
      for (pos = myservo2.read(); pos <= angle; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo2.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } else {
      for (pos = myservo2.read(); pos >= angle; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo2.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    }
  } else if (motor == 3) {
    if (angle >= myservo3.read()){
      for (pos = myservo3.read(); pos <= angle; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo3.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } else {
      for (pos = myservo3.read(); pos >= angle; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo3.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } 
  } else if (motor == 4) {
    if (angle >= myservo4.read()){
      for (pos = myservo4.read(); pos <= angle; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo4.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } else {
      for (pos = myservo4.read(); pos >= angle; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo4.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } 
  }
}

// Resets all servos to their center positions
void resetServo(){
  moveServo(4, 100); // sets the center position
  delay(100); // waits 100 ms
  moveServo(2, 45); // sets the center position
  delay(100); // waits 100 ms
  moveServo(1, 170); // sets the center position
  delay(100); // waits 100 ms
  moveServo(3, 170); // sets the center position
}

// Moves the claw to the desired position
void moveClaw(bool move){
  if (move) { // Open the claw to the desired position if the argument is == true
    moveServo(3, 135);
  } else { // Close the claw to the desired position if the argument is == false
    moveServo(3, 170);
  }
}

// Pick up the piece 1
void PickupPiece1(){
  // Pick up the piece
  moveServo(4, 122);
  delay(100);
  moveClaw(true);
  delay(100);
  moveServo(1, 70);
  delay(100);
  moveServo(2, 107);
  delay(100);
  moveClaw(false);

  // Move the piece to the box
  moveServo(1, 160);
  delay(100);
  moveServo(4, 35);
  delay(100);
  moveClaw(true);
  delay(100);
}

// Pick up the piece 2
void PickupPiece2(){
  // Picked up the piece
  moveClaw(true);
  delay(100);
  moveServo(4, 100);
  delay(100);
  moveServo(1, 75);
  delay(100);
  moveServo(2, 120);
  delay(100);
  moveClaw(false);
  delay(100);
  
  // Move the piece to the box
  moveServo(1, 160);
  delay(100);
  moveServo(2, 107);
  delay(100);
  moveServo(4, 36);
  delay(100);
  moveClaw(true);
  delay(100);
  
}

// Pick up the piece 3
void PickupPiece3(){
  // Pick up the piece
  delay(100);
  moveClaw(true);
  delay(100);
  moveServo(4, 75);
  delay(100);
  moveServo(2, 65);
  delay(100);
  moveServo(1, 100);
  delay(100);
  moveServo(2, 90);
  delay(100);
  moveServo(1, 80);
  delay(100);
  moveServo(2, 105);
  delay(100);
  moveClaw(false);
  delay(100);

  // Move the piece to the box
  moveServo(1, 160);
  delay(100);
  moveServo(4, 35);
  delay(100);
  moveClaw(true);
  delay(100);
}

bool stopMove = false; // true if moving the piece should stop the move animation

void setup() {
  resetServo();
  myservo1.attach(9);  // attaches the servo on pin 9 (left) to the servo object
  myservo2.attach(10); // attaches the servo on pin 10 (right) to the servo object
  myservo3.attach(11); // attaches the servo on pin 11 (claw) to the servo object
  myservo4.attach(6);  // attaches the servo on pin 6 (base) to the servo object

  Serial.begin(9600); // serial port connected
}

void loop() {
  while (!stopMove) {
    // Repeat the movement of the pieces 3x
    for (int i = 0; i < 3; i++) {
      PickupPiece1();
      resetServo();
      PickupPiece2();
      resetServo();
      PickupPiece3();
      resetServo();
    }
    stopMove = true; // Stop movement after all pieces have been moved to the box repeatedly
  }
}