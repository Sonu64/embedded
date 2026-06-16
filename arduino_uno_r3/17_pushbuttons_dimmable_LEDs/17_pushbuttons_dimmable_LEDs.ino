const int baudRate = 9600;
const int dt = 150;
const int buttonPin1 = 9;
const int buttonPin2 = 4;
const int ledPin = 11; // ~ PWM

// brightness control
// Step size for each button press.
float inc = (255.0)/(8.0);
// Current PWM level for the LED.
float brightness = 0.0;


void brightenLED() {
  // Clamp at max brightness.
  if (brightness + inc >= 255) {
    brightness = 255;
    analogWrite(ledPin, 255);
  }
  else {
    brightness = brightness + inc;
    analogWrite(ledPin, brightness);
  }
}

void dimLED() {
  // Clamp at minimum brightness.
  if (brightness - inc <= 0) {
    brightness = 0;
    analogWrite(ledPin, 0);
  }
  else {
    brightness = brightness - inc;
    analogWrite(ledPin, brightness);
  }
}



void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(baudRate);
}

void loop() {

  // Read both buttons each loop.
  int val1 = digitalRead(buttonPin2);
  int val2 = digitalRead(buttonPin1);
  
  if(val1 == 1) {
    brightenLED();
  }

  else if(val2 == 1) {
    dimLED();
  }

  // Small delay to reduce bounce noise.
  delay(dt);
}
