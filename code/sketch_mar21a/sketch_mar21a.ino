#include <Servo.h>

Servo servo;

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

char comando;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  servo.attach(8);
}

void loop() {
  if (Serial.available() > 0) {
    comando = Serial.read();

    Serial.print(comando);

    switch (comando) {
      case 'F':
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        Serial.println("Frente");
        break;

      case 'B':
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        Serial.println("Trás");
        break;

      case 'L':
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        Serial.println("Esquerda");
        break;

      case 'R':
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        Serial.println("Direita");
        break;

      case 'S':
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        Serial.println("Parado");
        break;

      case 'W':
        servo.write(0);
        Serial.println("Ataque");
        break;

      case 'w':
        servo.write(90);
        Serial.println("Reset Servo");
        break;

      default:
        Serial.println("Comando inválido");
        break;
    }
  }
