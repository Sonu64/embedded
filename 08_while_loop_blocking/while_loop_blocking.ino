const int delayTime = 500; // ms 
const int potPin = A1; // explicit analog pins for inputs 
const int redLED = 4; 
const int baudRate = 9600;

void setup() {
    pinMode(potPin, INPUT);
    pinMode(redLED, OUTPUT);
    Serial.begin(baudRate);
}

void loop() {
    int readVoltage = analogRead(potPin);
    Serial.print("Raw Potentiometer output = ");
    Serial.println(readVoltage);

    /* blocking while loop below, until this loop is escaped 
    the code below it will not run, the code below it can be senstive related
    to actuators. */

    while (readVoltage > 1000) {
        Serial.println("Arduino blocked due to the while loop barrier :( ");
        readVoltage = analogRead(potPin); // Read it again !
    }

    Serial.println("\n Sensitive Code running successfuly. Barrier crossed.");
}