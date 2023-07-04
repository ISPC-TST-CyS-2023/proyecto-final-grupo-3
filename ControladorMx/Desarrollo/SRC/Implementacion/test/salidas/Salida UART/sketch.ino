#include <Arduino.h>
#include <HardwareSerial.h>

// Definir el número de UART a utilizar (0 o 1)
#define UART_NUM 0

// Definir la velocidad de transmisión (baud rate)
#define BAUD_RATE 115200

void setup() {
  // Inicializar el UART
  Serial.begin(BAUD_RATE, SERIAL_8N1, UART_NUM);
  
  // Esperar a que el UART esté listo
  while (!Serial) {
    delay(10);
  }
  
  // Enviar un mensaje de prueba
  Serial.println("¡Hola desde el ESP32!");
}

void loop() {
  // Verificar si hay datos disponibles para leer
  if (Serial.available()) {
    // Leer el byte recibido
    char data = Serial.read();
    
    // Imprimir el byte recibido en el monitor serie
    Serial.print("Byte recibido: ");
    Serial.println(data);
  }
  
  // Retardo para evitar una lectura excesiva del UART
  delay(100);
}
