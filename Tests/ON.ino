// Test all digital pins on Arduino Mega2560 (0–53)

void setup() {
  // Set all pins from 0 to 53 as outputs
  for (int pin = 0; pin <= 69; pin++) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}
}

void loop() {
  // Nothing needed here – pins stay HIGH
}