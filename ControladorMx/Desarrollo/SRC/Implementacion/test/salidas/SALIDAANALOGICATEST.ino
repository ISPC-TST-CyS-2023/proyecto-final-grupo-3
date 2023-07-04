#include <Arduino.h>

// Definiciones de pines
const int PIN_SALIDA_ANALOGICA = DAC1;  // Pin DAC1 en ESP32
const int PIN_DISPLAY_A = 14;
const int PIN_DISPLAY_B = 16;
const int PIN_DISPLAY_C = 17;
const int PIN_DISPLAY_D = 18;
const int PIN_DISPLAY_E = 27;
const int PIN_DISPLAY_F = 19;
const int PIN_DISPLAY_G = 21;
const int PIN_DISPLAY_1 = 22;
const int PIN_DISPLAY_2 = 23;

// Tabla de segmentos para mostrar dígitos
const byte TABLA_SEGMENTOS[] = {
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11110110   // 9
};

// Función para mostrar un dígito en el display de 7 segmentos
void mostrarDigito(int digito) {
  if (digito >= 0 && digito <= 9) {
    byte segmentos = TABLA_SEGMENTOS[digito];
    digitalWrite(PIN_DISPLAY_A, bitRead(segmentos, 0));
    digitalWrite(PIN_DISPLAY_B, bitRead(segmentos, 1));
    digitalWrite(PIN_DISPLAY_C, bitRead(segmentos, 2));
    digitalWrite(PIN_DISPLAY_D, bitRead(segmentos, 3));
    digitalWrite(PIN_DISPLAY_E, bitRead(segmentos, 4));
    digitalWrite(PIN_DISPLAY_F, bitRead(segmentos, 5));
    digitalWrite(PIN_DISPLAY_G, bitRead(segmentos, 6));
  }
}

void setup() {
  // Configurar pines como salida para el display de 7 segmentos
  pinMode(PIN_DISPLAY_A, OUTPUT);
  pinMode(PIN_DISPLAY_B, OUTPUT);
  pinMode(PIN_DISPLAY_C, OUTPUT);
  pinMode(PIN_DISPLAY_D, OUTPUT);
  pinMode(PIN_DISPLAY_E, OUTPUT);
  pinMode(PIN_DISPLAY_F, OUTPUT);
  pinMode(PIN_DISPLAY_G, OUTPUT);
  pinMode(PIN_DISPLAY_1, OUTPUT);
  pinMode(PIN_DISPLAY_2, OUTPUT);

  // Configurar DAC1 como salida analógica
  ledcSetup(1, 2000, 12);  // Canal 1, frecuencia de muestreo de 2000 Hz, resolución de 12 bits
  ledcAttachPin(PIN_SALIDA_ANALOGICA, 1);  // Asignar DAC1 al canal 1
}

void loop() {
  // Generar valor analógico de prueba (rango: 0-4095)
  int valor_analogico = random(4096);
  ledcWrite(1, valor_analogico);  // Escribir valor analógico en DAC1

  // Mostrar el valor en el display de 7 segmentos
  int digito_1 = valor_analogico / 1000;      // Obtener el primer dígito (miles)
  int digito_2 = (valor_analogico / 100) % 10;  // Obtener el segundo dígito (centenas)

  mostrarDigito(digito_1);
  digitalWrite(PIN_DISPLAY_1, HIGH);  // Encender el primer dígito
  delay(5);
  digitalWrite(PIN_DISPLAY_1, LOW);   // Apagar el primer dígito

  mostrarDigito(digito_2);
  digitalWrite(PIN_DISPLAY_2, HIGH);  // Encender el segundo dígito
  delay(5);
  digitalWrite(PIN_DISPLAY_2, LOW);   // Apagar el segundo dígito

  delay(200);  // Pequeña pausa entre actualizaciones del display
}
