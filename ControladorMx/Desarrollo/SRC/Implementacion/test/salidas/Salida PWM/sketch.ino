// Incluye la librería de ESP32
#include <Arduino.h>

// Pin de entrada analógica para el potenciómetro
const int potentiometerPin = 34;

// Pin de salida PWM para el LED
const int pwmPin = 5;

void setup() {
  // Inicializa el pin de salida PWM
  pinMode(pwmPin, OUTPUT);
  ledcSetup(0, 5000, 8);  // Canal 0, frecuencia de 5 kHz y resolución de 8 bits
  ledcAttachPin(pwmPin, 0);
}

void loop() {
  // Lee el valor del potenciómetro
  int potValue = analogRead(potentiometerPin);

  // Mapea el valor leído (rango 0-4095) al rango del ciclo de trabajo del PWM (0-255)
  int dutyCycle = map(potValue, 0, 4095, 0, 255);

  // Establece el ciclo de trabajo del PWM
  ledcWrite(0, dutyCycle);
}
