#include <TM1637Display.h>
const int CLK = 7;
const int DIO = 8;

TM1637Display display(CLK, DIO);
int counter = 0;

void setup() {
  display.setBrightness(1);
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter);
  if (counter % 3 == 0) {
    Serial.println("Fizz");
  }
  if (counter % 5 == 0) {
    Serial.println("Buzz");
  }
  display.showNumberDec(counter);
  counter++;
  delay(1000);
}
