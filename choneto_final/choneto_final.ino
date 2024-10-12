#include <SoftwareSerial.h>

const int PinIN1 = 7;
const int PinIN2 = 6;
const int PinIN3 = 5;
const int PinIN4 = 4;

// SoftSerial(Tx, Rx);
SoftwareSerial BT(10, 11); // Definimos los pines RX y TX del Arduino conectados al Bluetooth

void setup()
{
  BT.begin(9600);     // Inicializamos el puerto serie BT
  Serial.begin(9600); // Inicializamos  el puerto serie

  // configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
}

void loop()
{

  if (BT.available()) // Si llega un dato por el puerto BT se envía al monitor serial
  {
    char comando = BT.read();
    Serial.write(comando);

    // Procesa el comando
    if (comando == 'F')
    {
      // Avanzar
      robotadelante();
    }
    else if (comando == 'B')
    {
      // Retroceder
      robotatras();
    }
    else if (comando == 'L')
    {
      // Girar a la izquierda
      robotizquierda();
    }
    else if (comando == 'R')
    {
      // Girar a la derecha
      robotderecha();
    }
    else if (comando == 'S')
    {
      // Detenerse
      robotpara();
    }
  }

  if (Serial.available()) // Si llega un dato por el monitor serial se envía al puerto BT
  {
    BT.write(Serial.read());
  }
}

void robotadelante()
{
  // Motor derecha
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, HIGH);

  // Motor izquierda
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, HIGH);
}

void robotatras()
{
  // Motor derecha
  digitalWrite(PinIN1, HIGH);
  digitalWrite(PinIN2, LOW);

  // Motor derecha
  digitalWrite(PinIN3, HIGH);
  digitalWrite(PinIN4, LOW);
}

void robotpara()
{
  // Motor derecha
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, LOW);

  // Motor izquierda
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, LOW);
}

void robotizquierda()
{
  // Motor Izquierda
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, HIGH);

  // Motor Derecha
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, LOW);
}

void robotderecha()
{
  // Motor Izquierda
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, LOW);

  // Motor Derecha
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, HIGH);
}
