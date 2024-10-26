#include <Arduino.h>

// A basic code  forreading the sensor values from the BFD-1000 module and displaying them over serial:

const int line_pin[5] = {8, 9, 10, 11, 12};
const int near_pin = 7;
const int clp_pin = 6;
int line_val[5] = {0};
int near_val = 0;
int clp_val = 0;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 5; i++)
  {
    pinMode(line_pin[i], INPUT);
  }
  pinMode(near_pin, INPUT);
  pinMode(clp_pin, INPUT);
}

void loop()
{
  read_sensor();
  display_serial();
}

void display_serial()
{
  for (int i = 0; i < 5; i++)
  {
    Serial.print(line_val[i]);
    Serial.print(" ");
  }
  Serial.print(near_val);
  Serial.print(" ");
  Serial.println(clp_val);
  delay(1000);
}

void read_sensor()
{
  for (int i = 0; i < 5; i++)
  {
    line_val[i] = digitalRead(line_pin[i]);
  }
  near_val = digitalRead(near_pin);
  clp_val = digitalRead(clp_pin);
}