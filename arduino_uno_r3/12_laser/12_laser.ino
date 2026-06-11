// KY-008 Laser Module Test Code
const int LASER_PIN = 7; // Connects to the 'S' pin of the module

void setup() {
  pinMode(LASER_PIN, OUTPUT); // Configure the laser pin as an output driver
}

void loop() {
  digitalWrite(LASER_PIN, HIGH); // Turn Laser ON
  delay(1000);                   // Wait for 1 second
  
  // digitalWrite(LASER_PIN, LOW);  // Turn Laser OFF
  // delay(1000);                   // Wait for 1 second
}