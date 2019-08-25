#define S0 3
#define S1 4
#define S2 6
#define S3 5
#define sensorOutput 7

int frequency = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOutput, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  // Set filter to read red
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOutput, LOW);
  Serial.print("R=");
  Serial.print(frequency);
  Serial.print(" ");
  delay(100);

  // Set filter to read green
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOutput, LOW);
  Serial.print("G=");
  Serial.print(frequency);
  Serial.print(" ");
  delay(100);

  // Set filter to read blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOutput, LOW);
  Serial.print("B=");
  Serial.print(frequency);
  Serial.println(" ");
  delay(100);

}
