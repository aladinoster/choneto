#include <Arduino.h>

const int IN1 = 12;
const int IN2 = 11;
const int ENA = 10;

const int IN3 = 7;
const int IN4 = 8;
const int ENB = 9;

const int ledPin = 13; // Pin del LED integrado

void setup()
{
  // Configuramos los pines como salida
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT); // Configuramos el pin del LED como salida
}

void loop()
{
  // Preparamos la salida para que los dos motores giren hacia adelante
  for (int i = 0; i <= 100; i += 5) // Incrementos más pequeños (cada 2%)
  {
    int pwmValue = map(i, 0, 100, 0, 255); // Mapeamos de 0-100% a 0-255 PWM

    // Control de parpadeo del LED, más rápido a medida que aumenta PWM
    int blinkDelay = map(i, 0, 100, 1500, 200);       // Mapeamos 0-100% a 1500-200ms delay (más lento)
    for (int j = 0; j < 1500 / (blinkDelay * 2); j++) // Número de parpadeos en 1.5 segundos
    {
      digitalWrite(ledPin, HIGH); // Encender el LED
      delay(blinkDelay);          // Esperar por el retardo del parpadeo
      digitalWrite(ledPin, LOW);  // Apagar el LED
      delay(blinkDelay);          // Esperar por el retardo del parpadeo
    }

    // Control de los motores, ambos giran hacia adelante
    digitalWrite(IN1, HIGH); // Motor 1 hacia adelante
    digitalWrite(IN2, LOW);
    analogWrite(ENA, pwmValue); // Controlamos la velocidad con PWM

    digitalWrite(IN3, LOW); // Motor 2 también hacia adelante
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, pwmValue); // Controlamos la velocidad con PWM

    delay(1500); // Espera de 1.5 segundos para observar el cambio de velocidad
  }
}
