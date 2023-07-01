#include <Arduino.h>
#include <Wire.h>
#include <FastLED.h>

#define LED_PIN 19
#define NUM_LEDS 86
#define BRIGHTNESS 30
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

// Mapa de segmentos para todos los displays y puntos
#define D1_E 0
#define D1_D 3
#define D1_C 6
#define D1_B 9
#define D1_A 12
#define D1_F 15
#define D1_G 18

#define D2_E 21
#define D2_D 24
#define D2_C 27
#define D2_B 30
#define D2_A 33
#define D2_F 36
#define D2_G 39

#define P1 42
#define P2 43

#define D3_E 44
#define D3_D 47
#define D3_C 50
#define D3_B 53
#define D3_A 56
#define D3_F 59
#define D3_G 62

#define D4_E 65
#define D4_D 68
#define D4_C 71
#define D4_B 74
#define D4_A 77
#define D4_F 80
#define D4_G 83

void setup()
{
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
    // Definimos un arreglo con los inicios de cada segmento
    int segmentStarts[] = {D1_E, D1_D, D1_C, D1_B, D1_A, D1_F, D1_G,
                           D2_E, D2_D, D2_C, D2_B, D2_A, D2_F, D2_G,
                           P1, P2,
                           D3_E, D3_D, D3_C, D3_B, D3_A, D3_F, D3_G,
                           D4_E, D4_D, D4_C, D4_B, D4_A, D4_F, D4_G};

    // Enciende cada segmento en secuencia y luego lo apaga
    for (int j = 0; j < sizeof(segmentStarts) / sizeof(int); j++)
    {
        int segmentStart = segmentStarts[j];
        int segmentLength = (segmentStart == P1 || segmentStart == P2) ? 1 : 3;

        // Enciende el segmento
        for (int i = segmentStart; i < segmentStart + segmentLength; i++)
        {
            leds[i] = CRGB::Red;
        }
        FastLED.show();
        delay(1000);

        // Apaga el segmento
        for (int i = segmentStart; i < segmentStart + segmentLength; i++)
        {
            leds[i] = CRGB::Black;
        }
        FastLED.show();
    }
}