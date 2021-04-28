#include "FastLED.h"

//https://www.sparkfun.com/products/14555

// How many leds in your strip?
#define NUM_LEDS 20 //# of segments on the LED Neon Flex Rope
#define DATA_PIN 5

// Define the array of leds
CRGB leds[NUM_LEDS];
//define potentiometer pins, one potentiometer for R, G, and B
int redPin = A0;    // select the input pin for the potentiometer
int greenPin = A1;
int bluePin = A2;  
  
int red = 0;       // variable to store the value coming from the sensor
int blue = 0;  
int green = 0;  

int rangePot = 1023;
int rangeRGB = 255;
int lowerBound = 0;

void setup() {
  Serial.begin(9600); //declare baud rate
  delay( 3000 ); // power-up safety delay
  // put your setup code here, to run once:
  FastLED.addLeds<UCS1903, DATA_PIN, BRG>(leds, NUM_LEDS);
  for(int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Gray;
  }
}

void loop() {

  //read POTs, get RGB
  red = analogRead(redPin);
  green = analogRead(greenPin);
  blue = analogRead(bluePin);
  
  red = map(red, lowerBound, rangePot, lowerBound, rangeRGB);
  green = map(green, lowerBound, rangePot, lowerBound, rangeRGB);
  blue = map(blue, lowerBound, rangePot, lowerBound, rangeRGB);
  

  for(int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB(red, green, blue);
  }
  Serial.println(red);
  Serial.println(blue);
  Serial.println(green);

  delay(100);
  FastLED.show();
    
}
