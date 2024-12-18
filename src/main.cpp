#include <Arduino.h>
#include <Servo.h>

Servo myservo1; // cria o objeto servo para controlar um servo
Servo myservo2; // cria o objeto servo para controlar um servo
Servo myservo3; // cria o objeto servo para controlar um servo
Servo myservo4; // cria o objeto servo para controlar um servo

int pos = 0;    // variável para armazenar a posição do servo

int motor = 0;  // variável para armazenar o motor
int angle = -1; // variável para armazenar o ângulo do motor

// Move os servos suavemente através da lista de dispositivos conectados e os escreve na porta serial
void moveServo(int motor, int angle) {
  if (motor >= 1 && motor <= 4 && angle >= 0 && angle <= 180) {
    Serial.print("Movendo motor ");
    Serial.print(motor);
    Serial.print(" para o ângulo ");
    Serial.println(angle);
  }

  if (motor == 1) {
    if (angle >= myservo1.read()){
      for (pos = myservo1.read(); pos <= angle; pos += 1) { 
        // em passos de 1 grau
        myservo1.write(pos);             // diz ao servo para ir para a posição na variável 'pos'
        delay(15);                       // espera 15 ms para o servo atingir a posição
      }
    } else {
      for (pos = myservo1.read(); pos >= angle; pos -= 1) { 
        myservo1.write(pos);             // diz ao servo para ir para a posição na variável 'pos'
        delay(15);                       // espera 15 ms para o servo atingir a posição
      }
    }
  } else if (motor == 2) {
    if (angle >= myservo2.read()){
      for (pos = myservo2.read(); pos <= angle; pos += 1) { 
        // em passos de 1 grau
        myservo2.write(pos);             // diz ao servo para ir para a posição na variável 'pos'
        delay(15);                       // espera 15 ms para o servo atingir a posição
      }
    } else {
      for (pos = myservo2.read(); pos >= angle; pos -= 1) { 
        myservo2.write(pos);             // diz ao servo para ir para a posição na variável 'pos'
        delay(15);                       // espera 15 ms para o servo atingir a posição
      }
    }
  } else if (motor == 3) {
    if (angle >= myservo3.read()){
      for (pos = myservo3.read(); pos <= angle; pos += 1) { 
        // em passos de 1 grau
        myservo3.write(pos);             // diz ao servo para ir para a posição na variável 'pos'
        delay(15);                       // espera 15 ms para o servo atingir a posição
      }
    } else {
      for (pos = myservo3.read(); pos >= angle; pos -= 1) { 
        myservo3.write(pos);             // diz ao servo para ir para a posição na variável 'pos'
        delay(15);                       // espera 15 ms para o servo atingir a posição
      }
    } 
  } else if (motor == 4) {
    if (angle >= myservo4.read()){
      for (pos = myservo4.read(); pos <= angle; pos += 1) { 
        // em passos de 1 grau
        myservo4.write(pos);             // diz ao servo para ir para a posição na variável 'pos'
        delay(15);                       // espera 15 ms para o servo atingir a posição
      }
    } else {
      for (pos = myservo4.read(); pos >= angle; pos -= 1) { 
        myservo4.write(pos);             // diz ao servo para ir para a posição na variável 'pos'
        delay(15);                       // espera 15 ms para o servo atingir a posição
      }
    } 
  }
}

// Reseta todos os servos para suas posições centrais
void resetServo(){
  moveServo(4, 100); // define a posição central
  delay(100); // espera 100 ms
  moveServo(2, 45); // define a posição central
  delay(100); // espera 100 ms
  moveServo(1, 170); // define a posição central
  delay(100); // espera 100 ms
  moveServo(3, 170); // define a posição central
}

// Move a garra para a posição desejada
void moveClaw(bool move){
  if (move) { // Abre a garra para a posição desejada se o argumento for == true
    moveServo(3, 135);
  } else { // Fecha a garra para a posição desejada se o argumento for == false
    moveServo(3, 170);
  }
}

// Pega a peça 1
void PickupPiece1(){
  // Pega a peça
  moveServo(4, 122);
  delay(100);
  moveClaw(true);
  delay(100);
  moveServo(1, 70);
  delay(100);
  moveServo(2, 107);
  delay(100);
  moveClaw(false);

  // Move a peça para a caixa
  moveServo(1, 160);
  delay(100);
  moveServo(4, 35);
  delay(100);
  moveClaw(true);
  delay(100);
}

// Pega a peça 2
void PickupPiece2(){
  // Pegou a peça
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
  
  // Move a peça para a caixa
  moveServo(1, 160);
  delay(100);
  moveServo(2, 107);
  delay(100);
  moveServo(4, 36);
  delay(100);
  moveClaw(true);
  delay(100);
  
}

// Pega a peça 3
void PickupPiece3(){
  // Pega a peça
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

  // Move a peça para a caixa
  moveServo(1, 160);
  delay(100);
  moveServo(4, 35);
  delay(100);
  moveClaw(true);
  delay(100);
}

bool stopMove = false; // true se o movimento da peça deve parar a animação de movimento

void setup() {
  resetServo();
  myservo1.attach(9);  // conecta o servo no pino 9 (esquerdo) ao objeto servo
  myservo2.attach(10); // conecta o servo no pino 10 (direito) ao objeto servo
  myservo3.attach(11); // conecta o servo no pino 11 (garra) ao objeto servo
  myservo4.attach(6);  // conecta o servo no pino 6 (base) ao objeto servo

  Serial.begin(9600); // porta serial conectada
}

void loop() {
  while (!stopMove) {
    // Repete o movimento das peças 3 vezes
    for (int i = 0; i < 3; i++) {
      PickupPiece1();
      resetServo();
      PickupPiece2();
      resetServo();
      PickupPiece3();
      resetServo();
    }
    stopMove = true; // Para o movimento depois que todas as peças forem movidas para a caixa repetidamente
  }
}
