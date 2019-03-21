static const int REED_SWITCH_PIN = 8;

void setup() {
  pinMode(REED_SWITCH_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int REED_SWITCH_STATE = digitalRead(REED_SWITCH_PIN);
  if(REED_SWITCH_STATE == HIGH) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
}
