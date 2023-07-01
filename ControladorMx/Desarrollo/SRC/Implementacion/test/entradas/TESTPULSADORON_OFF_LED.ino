#include <Arduino.h>

// Definiciones de pines
const int PIN_PULSADOR = 2;
const int PIN_LED = 13;
const int PIN_DISPLAY_A = 14;
const int PIN_DISPLAY_B = 15;
const int PIN_DISPLAY_C = 16;
const int PIN_DISPLAY_D = 17;
const int PIN_DISPLAY_E = 18;
const int PIN_DISPLAY_F = 19;
const int PIN_DISPLAY_G = 20;
const int PIN_DISPLAY_1 = 21;
const int PIN_DISPLAY_2 = 22;

// Función para encender el LED
void encenderLED() {
    digitalWrite(PIN_LED, HIGH);
}

// Función para apagar el LED
void apagarLED() {
    digitalWrite(PIN_LED, LOW);
}

// Función para mostrar "on" en el display de 7 segmentos
void mostrarOn() {
    digitalWrite(PIN_DISPLAY_A, LOW);
    digitalWrite(PIN_DISPLAY_B, HIGH);
    digitalWrite(PIN_DISPLAY_C, LOW);
    digitalWrite(PIN_DISPLAY_D, LOW);
    digitalWrite(PIN_DISPLAY_E, LOW);
    digitalWrite(PIN_DISPLAY_F, LOW);
    digitalWrite(PIN_DISPLAY_G, LOW);
}

// Función para mostrar "off" en el display de 7 segmentos
void mostrarOff() {
    digitalWrite(PIN_DISPLAY_A, HIGH);
    digitalWrite(PIN_DISPLAY_B, HIGH);
    digitalWrite(PIN_DISPLAY_C, HIGH);
    digitalWrite(PIN_DISPLAY_D, HIGH);
    digitalWrite(PIN_DISPLAY_E, HIGH);
    digitalWrite(PIN_DISPLAY_F, HIGH);
    digitalWrite(PIN_DISPLAY_G, HIGH);
}

void setup() {
    // Configurar pines como entrada o salida
    pinMode(PIN_PULSADOR, INPUT);
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_DISPLAY_A, OUTPUT);
    pinMode(PIN_DISPLAY_B, OUTPUT);
    pinMode(PIN_DISPLAY_C, OUTPUT);
    pinMode(PIN_DISPLAY_D, OUTPUT);
    pinMode(PIN_DISPLAY_E, OUTPUT);
    pinMode(PIN_DISPLAY_F, OUTPUT);
    pinMode(PIN_DISPLAY_G, OUTPUT);
    pinMode(PIN_DISPLAY_1, OUTPUT);
    pinMode(PIN_DISPLAY_2, OUTPUT);

    // Mostrar "off" inicialmente en los displays
    mostrarOff();
    digitalWrite(PIN_DISPLAY_1, LOW);
    digitalWrite(PIN_DISPLAY_2, LOW);
}

void loop() {
    static bool ledEncendido = false;
    static bool estadoAnterior = false;

    // Leer el estado del pulsador
    bool pulsadorPresionado = digitalRead(PIN_PULSADOR);

    // Verificar si el estado del pulsador ha cambiado
    if (pulsadorPresionado != estadoAnterior) {
        if (pulsadorPresionado) {
            // Si el pulsador ha sido presionado, cambiar el estado del LED
            ledEncendido = !ledEncendido;
            if (ledEncendido) {
                encenderLED();
                mostrarOn();
            } else {
                apagarLED();
                mostrarOff();
            }
        }

        // Actualizar el estado anterior
        estadoAnterior = pulsadorPresionado;
    }

    // Mostrar el estado en los displays
    if (ledEncendido) {
        digitalWrite(PIN_DISPLAY_1, HIGH);
        digitalWrite(PIN_DISPLAY_2, LOW);
    } else {
        digitalWrite(PIN_DISPLAY_1, LOW);
        digitalWrite(PIN_DISPLAY_2, HIGH);
    }

    delay(10); // Pequeña pausa para evitar rebotes en el pulsador
}
