// Definimos el pin del LED
int ledPin = 13;

void setup()
{
  // Configuramos el pin del LED como salida
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // Encendemos el LED
  digitalWrite(ledPin, HIGH);
  // Esperamos un segundo (1000 milisegundos)
  delay(1000);

  // Apagamos el LED
  digitalWrite(ledPin, LOW);
  // Esperamos otro segundo
  delay(1000);
}
