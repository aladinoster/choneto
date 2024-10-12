// Definicion de pines de conexion puente H
const int PinIN1 = 7;
const int PinIN2 = 6;
const int PinIN3 = 5;
const int PinIN4 = 4;

void setup()
{
  // Inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);

  // Configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
}

void loop()
{

  robotadelante();
  delay(1000);
  robotpara();
  delay(1000);
  robotderecha1();
  delay(1000);
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

  // Motor izquierda
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

void robotizquierda1()
{
  // Motor Izquierda
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, HIGH);

  // Motor Derecha
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, LOW);
}

void robotderecha1()
{
  // Motor Izquierda
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, LOW);

  // Motor Derecha
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, HIGH);
}
