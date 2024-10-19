#include <Arduino.h>

void robotadelante();
void robotpara();
void robotderecha();
void robotizquierda();
void robotatras();

// Definicion de pines de conexion puente H
const int IN1 = 12;
const int IN2 = 11;
const int ENA = 10;

const int IN3 = 7;
const int IN4 = 8;
const int ENB = 9;

const int pwmValue = 128; // Fixed PWM value (128 out of 255)

void setup()
{
  // Inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);

  // Configuramos los pines como salida
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  robotadelante();
  delay(1000);
  robotpara();
  delay(1000);
  robotderecha();
  delay(1000);
  robotpara();
  delay(1000);
  robotizquierda();
  delay(1000);
  robotpara();
  delay(1000);
  robotatras();
  delay(1000);
  robotpara();
  delay(2000);
}

void robotadelante()
{
  // Motor derecha
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, pwmValue); // Fixed PWM value for motor 1

  // Motor izquierda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, pwmValue); // Fixed PWM value for motor 2
}

void robotatras()
{
  // Motor derecha
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, pwmValue); // Fixed PWM value for motor 1

  // Motor izquierda
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, pwmValue); // Fixed PWM value for motor 2
}

void robotpara()
{
  // Motor derecha
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Stop motor 1

  // Motor izquierda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); // Stop motor 2
}

void robotizquierda()
{
  // Motor Izquierda
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, pwmValue); // Fixed PWM for motor 1 (left)

  // Motor Derecha
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); // Stop motor 2 (right)
}

void robotderecha()
{
  // Motor Izquierda
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Stop motor 1 (left)

  // Motor Derecha
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, pwmValue); // Fixed PWM for motor 2 (right)
}
