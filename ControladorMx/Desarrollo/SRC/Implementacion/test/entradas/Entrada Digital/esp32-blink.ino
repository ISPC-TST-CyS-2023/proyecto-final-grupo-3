#include <Arduino.h>

// pines para el pulsador y LED
int pinPulsador2 = 4;
int pinLed2 = 2;

void setup()
{
  // Configuracion pin del pulsador como una entrada
  pinMode(pinPulsador2, INPUT);

  // Configuracion pin de LED como salida
  pinMode(pinLed2, OUTPUT);
}

void loop()
{
  // Si el pulsador está activado enciende el LED
  if (digitalRead(pinPulsador2) == HIGH)
  {
    digitalWrite(pinLed2, HIGH);
  }
  else
  {
    digitalWrite(pinLed2, LOW);
  }
}
