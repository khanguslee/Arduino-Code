/*
 * Arduino sketch to test a common anode RGB LED.
 * Common Pin: 5v
 * Red: 220 ohm resistor
 * Green: 100 ohm resistor
 * Blue: 100 ohm resistor
 * 
 * Tutorial: https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/overview
 * 
 */

const int redPin = 7;
const int greenPin = 6;
const int bluePin = 5;

bool flag = false;
void setup() {
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int red, green, blue;
  delay(200);
  setColour(0,0,255);     // Blue
  delay(200);
  setColour(0,255,0);     // Green
  delay(200);
  setColour(255,0,0);     // Red
  delay(200);
  setColour(255,255,0);   // Yellow
  delay(200);
  setColour(255,0,255);   // Purple
  delay(200);
  setColour(255,255,255); // White
  delay(200);
  setColour(0,255,255);   // Aqua
}

void setColour(int red, int green, int blue)
{
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

