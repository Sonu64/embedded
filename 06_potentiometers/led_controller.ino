// Control LED Brightness by moving Potentiometer Knob, behaves like PWM, but you can control the knob physically, in pwm we only had power in code, here we have in Hardware.

int voltageReadingPin = 1;
int powerPin = 5;
const int baudRate = 9600;
const int delayTime = 300;

void setup() {
    pinMode(voltageReadingPin, INPUT);
    pinMode(powerPin, OUTPUT);
    Serial.begin(baudRate);
    digitalWrite(powerPin, HIGH);
}

void loop() {
    float readVoltage = (5.0/1023.0)*analogRead(voltageReadingPin);
    Serial.print(readVoltage);
    Serial.println("V");
    Serial.println();
    delay(delayTime);
}