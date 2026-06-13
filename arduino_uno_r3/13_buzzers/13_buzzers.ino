/*
 * Voltage Warning System with Buzzer and LED Alert
 * 
 * This program reads an analog voltage from a potentiometer and triggers
 * a warning system when the voltage exceeds 3.5V. The warning system includes
 * an audible buzzer alarm and a blinking red LED. A lower voltage reading keeps
 * the system in a safe state with no alerts. Voltage readings are continuously
 * monitored and reported to the serial console.
 */

const int buzzPin = 5; // ~
const int delayTime = 200; 
const int potPin = A0; // Explicit Analog In Pin.
const int baudRate = 9600;
const int redLED = 9;

void playBuzzer() {
  digitalWrite(buzzPin, HIGH);
  delay(delayTime);
  digitalWrite(buzzPin, LOW);
}

void turnOffBuzzer() {
  digitalWrite(buzzPin, LOW);
}

void blinkLED() {
  digitalWrite(redLED, HIGH);
  delay(delayTime);
  digitalWrite(redLED, LOW);
}

void turnLEDOff() {
  digitalWrite(redLED, LOW);
}

void printFormattedVoltage(float voltage) {
  if (voltage >= 3.50) {
      Serial.print("WARNING ! Voltage is ");
      Serial.print(voltage);
      Serial.println(" V");
  }
  else {
      Serial.print("ALL SAFE :) Voltage is ");
      Serial.print(voltage);
      Serial.println(" V");
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(baudRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage = (5.0/1023.0)*(analogRead(potPin));
  printFormattedVoltage(voltage);
  if (voltage > 3.5) {
    playBuzzer();
    blinkLED();
  }
  else {
    turnOffBuzzer();
    turnLEDOff();
  }
  delay(delayTime);
}
