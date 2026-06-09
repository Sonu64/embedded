/*
    True Analog Voltage readings and LED dimming without PWM using Potentiometer.
*/

// Pin Configurations
const int voltageReadingPin = A1; // Explicitly use the 'A' alias for analog pins
const int baudRate = 9600;
const int delayTime = 300;

void setup() {
    pinMode(voltageReadingPin, INPUT);
    Serial.begin(baudRate);
    
    // The powerPin has been removed! Power your potentiometer 
    // directly from the 5V and GND pins on the Arduino board.
}

void loop() {
    // Read the actual hardware voltage coming off the potentiometer
    float readVoltage = (5.0 / 1023.0) * analogRead(voltageReadingPin);
    
    // Print a clean, formatted sentence to the Serial Monitor
    Serial.print("True Analog Voltage: ");
    Serial.print(readVoltage, 2); // 2 decimal spots  only.
    Serial.println(" V");
    
    delay(delayTime);
}