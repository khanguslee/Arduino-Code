static const int REED_SWITCH_PIN = 2;
volatile unsigned long PREV_TIME = 0;
void setup() {
  pinMode(REED_SWITCH_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(REED_SWITCH_PIN), reedSwitchInterruptHandler, FALLING); // interrrupt 1 is data ready
  Serial.begin(9600);
}

void loop() {
  Serial.println("OFF");
  delay(100);
}

void reedSwitchInterruptHandler() {
  // Get start time
  if(PREV_TIME == 0) {
    PREV_TIME = millis();
    return;
  }
  unsigned long current_time = millis();
  unsigned long total_time = current_time - PREV_TIME;
  if(total_time == 0) {
    return;
  }
  
  float diameter = 0.8;
  double velocity = (1/total_time) * PI * diameter * 3.6;
  Serial.println("ON");
  Serial.println(total_time);

  Serial.print("Velocity: ");
  Serial.println(velocity);
  PREV_TIME = current_time;
}

