// Pin Configurations
const int redLED = 11; // PWM capable pin
const int voltageReadingPinB = A2;             
const int voltageReadingPinC = A1; // Explicitly using A1 standard alias
const int baudRate = 9600;

// Global Variables
float voltage = 0.0; 

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(voltageReadingPinC, INPUT);
  pinMode(voltageReadingPinB, INPUT);
  Serial.begin(baudRate);
}

void printVoltage(int rawADC, int  point) {
  // Convert raw value into actual voltage (assuming 5V reference)
  voltage = (rawADC * 5.0) / 1023.0;
  
  // Print human-readable voltage value
  if (point == 1)
    Serial.print("Voltage@B: ");
  else if (point == 2)
    Serial.print("Voltage@C (Voltage across LED): "); 

  Serial.print(voltage);
  Serial.println(" V");
}

void loop() {
  // Force Pin 11 to stay slightly lower than HIGH constantly, PWM Oscillation occurs !
  analogWrite(redLED, 230); 
  
  // Read the resulting constant voltage at Node B
  int rawADCB = analogRead(voltageReadingPinB);
  printVoltage(rawADCB, 1);

  // Read the resulting constant voltage at Node C
  int rawADCC = analogRead(voltageReadingPinC);
  printVoltage(rawADCC, 2);
  delay(500); 
  Serial.println("\n");
}

