// Pin Configurations
const int redLED = 4;           
const int vOutPin = A1; // Explicitly using A1 standard alias
const int baudRate = 9600;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(vOutPin, INPUT);
  Serial.begin(baudRate);
}

void loop() {
  float vout = (5.0/1023.0) * analogRead(vOutPin);
  if (vout >= 4) {
    digitalWrite(redLED, HIGH);
    Serial.print("Warning! Potentiometer output is ");
    Serial.print(vout);
    Serial.println(" Volts !");
  }
  else {
    digitalWrite(redLED, LOW);
    Serial.print("SAFE <3 Potentiometer output is ");
    Serial.print(vout);
    Serial.println(" Volts.");
  }
  delay(1000);
}

