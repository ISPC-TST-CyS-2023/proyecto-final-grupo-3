#include <Arduino.h>
#include <Wire.h>
#include <FastLED.h>

#define LED_PIN 19
#define NUM_LEDS 86
#define BRIGHTNESS 30
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

static const uint8_t displayStartIdx[4] = {0, 21, 44, 65};
static const uint8_t segmentIdx[7] = {0, 3, 6, 9, 12, 15, 18};

static const bool segmentMap[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 0, 1, 1, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {0, 1, 1, 1, 1, 0, 1}, // 3
    {0, 0, 1, 1, 0, 1, 1}, // 4
    {0, 1, 1, 0, 1, 1, 1}, // 5
    {1, 1, 1, 0, 1, 1, 1}, // 6
    {0, 0, 1, 1, 1, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {0, 1, 1, 1, 1, 1, 1}  // 9
};

class Display
{
public:
    Display(uint8_t displayNumber) : startIdx(displayStartIdx[displayNumber - 1]) {}

    void displayNumber(uint8_t number)
    {
        for (uint8_t i = 0; i < 7; ++i)
        {
            for (uint8_t j = 0; j < 3; ++j)
            {
                if (segmentMap[number][i])
                {
                    leds[startIdx + segmentIdx[i] + j] = CRGB::Green;
                }
                else
                {
                    leds[startIdx + segmentIdx[i] + j] = CRGB::Black;
                }
            }
        }
    }

private:
    uint8_t startIdx;
};

void setup()
{
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
    Display display1(1);
    Display display2(2);
    Display display3(3);
    Display display4(4);

    unsigned long time = millis() / 1000;
    display1.displayNumber((time / 1000) % 10);
    display2.displayNumber((time / 100) % 10);
    display3.displayNumber((time / 10) % 10);
    display4.displayNumber(time % 10);

    FastLED.show();
    delay(1000);
}