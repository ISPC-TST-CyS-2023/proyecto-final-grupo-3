/* Teste para la deteccion de direciones i2c */

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define I2C_SDA 21
#define I2C_SCL 22

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
    Wire.begin(I2C_SDA, I2C_SCL);
    Serial.begin(115200);
    Serial.println("\nI2C Scanner");
}

void loop()
{
    byte error, address;
    int nDevices;

    Serial.println("Scanning...");

    nDevices = 0;
    for (address = 1; address < 127; address++)
    {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print("I2C device found at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.print(address, HEX);
            Serial.println(" !");

            nDevices++;
        }
        else if (error == 4)
        {
            Serial.print("Unknow error at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.println(address, HEX);
        }
    }
    if (nDevices == 0)
        Serial.println("No I2C devices found\n");
    else
        Serial.println("done\n");

    delay(5000); // espera 5 segundos para el siguiente escaneo
}