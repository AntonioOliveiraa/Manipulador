#include <Arduino.h>
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2; // create servo object to control
Servo myservo3; // create servo object to control
Servo myservo4; // create servo object to control
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int motor = 0; // variable to store the motor
int angulo = -1; // variable to store the angle of the motor

void setup() {
  myservo1.write(155); // sets initial position
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.write(15);  // sets initial position
  myservo2.attach(10); // attaches the servo on pin 10 to the servo object
  myservo3.attach(11); // attaches the servo on pin 11 to the servo object - garra
  myservo4.attach(6); // attaches the servo on pin 6 to the servo object - base
  Serial.begin(9600);
}

void moveServo(int motor, int angulo) {
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

void resetServo(){
  moveServo(1, 170); // sets the center position
  moveServo(2, 45); // sets the center position
  moveServo(3, 170); // sets the center position
  moveServo(4, 90); // sets the center position
}

void extendServo(){
  moveServo(2, 90);
  delay(150);
  moveServo(1, 95);
  delay(150);
  moveServo(2, 120);
  delay(150);
  moveServo(1, 80);
  delay(150);
  moveServo(2, 140);
  delay(150);
  moveServo(1, 120);
  delay(150);
  moveServo(2, 150);
}

void abrirGarra() {
  moveServo(3, 45);
}

void fecharGarra() {
  moveServo(3, 170);
}

void loop() {
  // Menu de opções
  Serial.println("Escolha uma opção:");
  Serial.println("1. Extender braço");
  Serial.println("2. Resetar todos os motores");
  Serial.println("3. Abrir garra");
  Serial.println("4. Fechar garra");
  while (Serial.available() == 0) {}  // Wait for input
  int option = Serial.parseInt();
  
  if (option == 1) {
    extendServo();
  } else if (option == 2) {
    resetServo();
  } else if (option == 3) {
    abrirGarra();
  } else if (option == 4) {
    fecharGarra();
  }
}