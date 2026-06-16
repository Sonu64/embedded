#include <Servo.h>

const int servoPin = 9; // ~pwm
const int baudRate = 9600;
const int dt = 500;

int servoPosition = 0; // unused here



Servo myServo;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(baudRate);
}

void loop() {
  for(int i=0; i<=180; i+=10) {
    myServo.write(i);
  }
  delay(dt);
  for(int j=180; j>=0; j-=10) {
    myServo.write(j);
  }
  delay(dt);
}



/* Smaller steps send more write commands in the same tiny time window.
  Without a delay, the servo gets updated too fast and starts jittering.
  Add a small delay between writes if you want smooth motion with step 10. */