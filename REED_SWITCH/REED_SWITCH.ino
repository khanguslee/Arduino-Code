static const int REED_SWITCH_PIN = 2;
volatile unsigned long PREV_TIME = 0;
volatile unsigned long REED_SWITCH_COUNTER = 0;
void setup() {
  pinMode(REED_SWITCH_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(REED_SWITCH_PIN), reedSwitchInterruptHandler, FALLING); // interrrupt 1 is data ready
  Serial.begin(9600);
}

void loop() {
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
  // 50ms means we have a maximum velocity of 180km/h with a wheel diameter of 0.8
  if(total_time <= 50) {
    return;
  }
  REED_SWITCH_COUNTER = REED_SWITCH_COUNTER + 1;
  // 700C Rims + 33mm tyre
  const float diameter = 0.622 + (0.033 * 2);
  float velocity = (1/(float)total_time) * PI * diameter * 3600;

  //Serial.print("Velocity: ");
  Serial.println(String(velocity, 4) + ",");

  float distance = REED_SWITCH_COUNTER * diameter;
  //Serial.print("Distance: ");
  //Serial.println(String(distance, 4));
  PREV_TIME = current_time;
}

