const int delayTime = 500;
const int photoResistorVoltage = A0; // analog in
const int redLED = 6;
const int greenLED = 10;
const int baudRate = 9600;


void setup() {
  // put your setup code here, to run once:
  // pinMode(readVoltage, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(baudRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print("\n");

}
