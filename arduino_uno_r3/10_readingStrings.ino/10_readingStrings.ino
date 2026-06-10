const int baudRate = 9600;

// Digital Outputs
const int greenLED = 8;
const int redLED   = 9;
const int blueLED  = 10;

void turnRedOn() {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
}

void turnGreenOn() {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
}

void turnBlueOn() {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
}

void setup() {
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);

    Serial.begin(baudRate);
}

void loop() {

    Serial.println("Enter your name:");

    while (Serial.available() == 0) {}

    String name = Serial.readStringUntil('\n');
    name.trim();

    Serial.print("Hello, ");
    Serial.print(name);
    Serial.println("!");

    Serial.println("Enter LED color [red/green/blue]:");

    while (Serial.available() == 0) {}

    String led = Serial.readStringUntil('\n');
    led.trim();
    led.toLowerCase();

    if (led == "red" || led == "r") {
        turnRedOn();
        Serial.println("Red LED ON");
    }
    else if (led == "green" || led == "g") {
        turnGreenOn();
        Serial.println("Green LED ON");
    }
    else if (led == "blue" || led == "b") {
        turnBlueOn();
        Serial.println("Blue LED ON");
    }
    else {
        Serial.println("Invalid Input!");
    }

    Serial.println();
}