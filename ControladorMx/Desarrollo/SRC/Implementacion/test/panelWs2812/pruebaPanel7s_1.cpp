#include <Arduino.h>
#include <Wire.h>
#include <FastLED.h>

#define LED_PIN 19
#define NUM_LEDS 86
#define BRIGHTNESS 30
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

// Mapa de segmentos para el primer display
#define D1_E 0
#define D1_D 3
#define D1_C 6
#define D1_B 9
#define D1_A 12
#define D1_F 15
#define D1_G 18

void setup()
{
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
    // Enciende cada segmento en secuencia y luego lo apaga
    for (int segmentStart = D1_E; segmentStart <= D1_G; segmentStart += 3)
    {
        // Enciende el segmento
        for (int i = segmentStart; i < segmentStart + 3; i++)
        {
            leds[i] = CRGB::Red;
        }
        FastLED.show();
        delay(1000);

        // Apaga el segmento
        for (int i = segmentStart; i < segmentStart + 3; i++)
        {
            leds[i] = CRGB::Black;
        }
        FastLED.show();
    }
}