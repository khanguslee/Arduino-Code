#define POT_PIN A9
void setup() {
  pinMode(POT_PIN, INPUT);
}

void loop() {
  int potentiometer_value = analogRead(POT_PIN);

  // Calculate voltage
  float reference_voltage = 3.3;
  float voltage = 3.3 * ((float)potentiometer_value / (float)1023);

  // Calculate angle
  float max_pot_angle = 300;
  float angle = max_pot_angle * ((float)potentiometer_value / (float)1023);
  Serial.println(String(angle, 3));
}
