const int delayTime = 500;

// PWM pins for analogWrite between 0-255
const int redLED = 3;
const int blueLED = 6;
const int greenLED = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redLED, 255);
  analogWrite(blueLED, 255);
  analogWrite(greenLED, 0);
  // magenta code
}
