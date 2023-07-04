// *****************************************************************************************
// Compañia: Gonaiot
// Autor: Cristian Gonzalo Vera
// Fecha: 24/10/2021 01:00
// Descripción: Programa que lee el puerto P del PCF8574 y lo imprime en el monitor serial
//              cada vez que se presiona una tecla del teclado matricial 4x3
//              Se utiliza la librería Wire.h para comunicarse con el PCF8574
//              Se utiliza la librería Arduino.h para utilizar las funciones de Arduino
// Hardware: ESP32, PCF8574, Teclado matricial 4x3
// Software: PlatformIO, Visual Studio Code
// Licencia: MIT License
// *****************************************************************************************
// Notas:
// Conexiones:
// I2C
//    SDA -> GPIO 21
//    SCL -> GPIO 22
// PCF y Teclado
//    P7 -> Fila 1
//    P6 -> Fila 2
//    P5 -> Fila 3
//    P4 -> Fila 4
//    P2 -> Columna 1
//    P1 -> Columna 2
//    P0 -> Columna 3
//
//    P3 -> No se utiliza y siempre es = 0
// *****************************************************************************************
// Librerías
#include <Arduino.h>
#include <Wire.h>

// Definiciones
#define Fila1 0b01110111 // 0x77
#define Fila2 0b10110111 // 0xB7
#define Fila3 0b11010111 // 0xD7
#define Fila4 0b11100111 // 0xE7

#define PCF8574_ADDRESS 0x3F

// Mapa de teclas
const char keymap[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

// Prototipo de funciones
void writePCF(unsigned char data);
unsigned char readPCF();
void readKeypad();

// Setup
void setup()
{
    Serial.begin(115200);
    Wire.begin();
    writePCF(0xFF); // Configurar todas las filas en alto
}

// Loop
void loop()
{
    readKeypad();
    delay(100);
}


// Implementacion de funciones
void readKeypad()
{
    unsigned char rowPins[4] = {Fila1, Fila2, Fila3, Fila4};
    for (int row = 0; row < 4; row++)
    {
        writePCF(rowPins[row]);         // Configurar una fila en bajo
        unsigned char data = readPCF(); // Leer el estado de las columnas
        for (int col = 0; col < 3; col++)
        {
            if ((data & (1 << (2 - col))) == 0)                        // Si la tecla correspondiente a la fila y la columna está presionada
            {
                Serial.print("Tecla presionada: ");
                Serial.println(keymap[row][col]);
                delay(100); // Esperar 100ms para evitar rebotes (debería ser mayor a 10ms
            }
        }
    }
}

void writePCF(unsigned char data)
{
    Wire.beginTransmission(PCF8574_ADDRESS);
    Wire.write(data);
    Wire.endTransmission();
}

unsigned char readPCF()
{
    Wire.requestFrom(PCF8574_ADDRESS, 1);
    if (Wire.available())
    {
        return Wire.read();
    }
    return 0;
}
