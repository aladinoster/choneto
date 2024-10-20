#include <Arduino.h>

const int IN1 = 12;
const int IN2 = 11;
const int ENA = 10;

const int IN3 = 7;
const int IN4 = 8;
const int ENB = 9;

// Pin del LED integrado
const int ledPin = 13;

void setup()
{
  // Configuramos los pines como salida
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configuramos el pin del LED como salida
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // Preparamos la salida para que los dos motores giren hacia

  // Incrementos más pequeños (cada 5%)
  for (int i = 0; i <= 100; i += 5)
  {
    // Mapeamos de 0-100% a 0-255 PWM
    int pwmValue = map(i, 0, 100, 0, 255);

    // Control de parpadeo del LED, más rápido a medida que aumenta PWM

    // Mapeamos 0-100% a 1500-200ms delay (más lento)
    int blinkDelay = map(i, 0, 100, 1500, 200);

    // Número de parpadeos en 1.5 segundos
    for (int j = 0; j < 1500 / (blinkDelay * 2); j++)
    {
      // Encender el LED
      digitalWrite(ledPin, HIGH);

      // Esperar por el retardo del parpadeo
      delay(blinkDelay);

      // Apagar el LED
      digitalWrite(ledPin, LOW);

      // Esperar por el retardo del parpadeo
      delay(blinkDelay);
    }

    // Control de los motores, ambos giran hacia adelante

    // Motor 1 hacia adelante
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    // Controlamos la velocidad con PWM
    analogWrite(ENA, pwmValue);

    // Motor 2 también hacia adelante
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    // Controlamos la velocidad con PWM
    analogWrite(ENB, pwmValue);

    // Espera de 1.5 segundos para observar el cambio de velocidad
    delay(1500);
  }
}
