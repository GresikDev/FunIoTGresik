#include <FastLED.h>
#define LED_PIN D4
#define NUM_LEDS  5

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(
    115200);
    
  FastLED.addLeds<WS2812, LED_PIN,GRB>(leds,NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i = 0; i<NUM_LEDS; i++) {
    leds[i]=CRGB(20+i,0,i*20);

    FastLED.show();
    delay(500);
    leds[i]=CRGB(0,0,0);
    FastLED.show();
    delay(500);
    }
  
}
