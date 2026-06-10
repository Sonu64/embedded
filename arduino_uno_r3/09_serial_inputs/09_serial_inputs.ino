const int baudRate = 9600;
const int delayTimer = 350; // ms 
const int redLED = 8; // for digital outputs
String prompt = "Enter number of times you want to blink LED: ";

void setup() {
    pinMode(redLED, OUTPUT);
    Serial.begin(baudRate);
}

void loop() {
    Serial.println(prompt);
    while (Serial.available() == 0) {
        // empty blocking behaviour, wait until something
        // is available in the Serial input buffer
    }
    int blinks = Serial.parseInt();

    // !!! IMPORTANT !!! //
    while(Serial.available() > 0) 
        Serial.read();  // consume leftovers like \r or \n from buffer

    // blink those number of times
    for(int i=0; i<blinks; i++) {
        digitalWrite(redLED, HIGH);
        delay(delayTimer);
        digitalWrite(redLED, LOW);
        delay(delayTimer);
    }
}