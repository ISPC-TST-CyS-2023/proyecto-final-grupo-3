#include <Arduino.h>

// Pines de salida
const int PIN_1 = 5;
const int PIN_2 = 14;
const int PIN_3 = 16;
const int PIN_4 = 17;
const int PIN_5 = 18;
const int PIN_6 = 27;

void setup() {
  // Configurar pines como salida
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  pinMode(PIN_5, OUTPUT);
  pinMode(PIN_6, OUTPUT);
}

void loop() {
  // Alternar el estado de los pines de salida
  digitalWrite(PIN_1, HIGH);
  digitalWrite(PIN_2, LOW);
  digitalWrite(PIN_3, HIGH);
  digitalWrite(PIN_4, LOW);
  digitalWrite(PIN_5, HIGH);
  digitalWrite(PIN_6, LOW);
  delay(1000);
  digitalWrite(PIN_1, LOW);
  digitalWrite(PIN_2, HIGH);
  digitalWrite(PIN_3, LOW);
  digitalWrite(PIN_4, HIGH);
  digitalWrite(PIN_5, LOW);
  digitalWrite(PIN_6, HIGH);
  delay(1000);
}
