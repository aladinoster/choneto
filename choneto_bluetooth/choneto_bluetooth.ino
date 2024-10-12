#include <SoftwareSerial.h>

// SoftSerial(Tx, Rx);
SoftwareSerial BT(10, 11); // Definimos los pines RX y TX del Arduino conectados al Bluetooth

void setup()
{
  BT.begin(9600);     // Inicializamos el puerto serie BT
  Serial.begin(9600); // Inicializamos  el puerto serie
}

void loop()
{

  if (BT.available()) // Si llega un dato por el puerto BT se envía al monitor serial
  {
    char comando = BT.read();
    Serial.write(comando);
  }

  if (Serial.available()) // Si llega un dato por el monitor serial se envía al puerto BT
  {
    BT.write(Serial.read());
  }
}
