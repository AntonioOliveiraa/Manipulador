#include <Arduino.h>
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2; // create servo object to control
Servo myservo3; // create servo object to control
Servo myservo4; // create servo object to control
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.write(175); // sets initial position
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.write(90);  // sets initial position
  myservo2.attach(10); // attaches the servo on pin 10 to the servo object
  myservo3.write(170); // sets initial position
  myservo3.attach(11); // attaches the servo on pin 11 to the servo object
  myservo4.write(90); // sets initial position
  myservo4.attach(6); // attaches the servo on pin 6 to the servo object
  Serial.begin(9600);
}

void loop() {
  int motor = 0;
  int angulo = -1;

  // Wait for engine number via serial
  Serial.println("Digite o número do motor (1, 2, 3 ou 4):");
  while (Serial.available() == 0) {} // Wait for input
  motor = Serial.parseInt();

  // Wait for angle via serial
  Serial.println("Digite o ângulo (0 a 180):");
  while (Serial.available() == 0) {}  // Wait for input
  angulo = Serial.parseInt();

  // Checks if values ​​are within expected limits
  if (motor >= 1 && motor <= 4 && angulo >= 0 && angulo <= 180) {
    Serial.print("Movendo motor ");
    Serial.print(motor);
    Serial.print(" para o ângulo ");
    Serial.println(angulo);
  }

  if (motor == 1) {
    if (angulo >= myservo1.read()){
      for (pos = myservo1.read(); pos <= angulo; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo1.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } else {
      for (pos = myservo1.read(); pos >= angulo; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo1.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    }
  } else if (motor == 2) {
    if (angulo >= myservo2.read()){
      for (pos = myservo2.read(); pos <= angulo; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo2.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } else {
      for (pos = myservo2.read(); pos >= angulo; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo2.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    }
  } else if (motor == 3) {
    if (angulo >= myservo3.read()){
      for (pos = myservo3.read(); pos <= angulo; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo3.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } else {
      for (pos = myservo3.read(); pos >= angulo; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo3.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } 
  } else if (motor == 4) {
    if (angulo >= myservo4.read()){
      for (pos = myservo4.read(); pos <= angulo; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo4.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } else {
      for (pos = myservo4.read(); pos >= angulo; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo4.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    } 
  }
}