int greenLED = 8;
int greenLED = 7;
int blueLED = 5;
int fastDelay = 100;
int midDelay = 400;
int highDelay = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED, OUTPUT); 
  pinMode(greenLED, OUTPUT);
  // this pin number 8 will have Arduino Provided +5V, but this can be controlled by digitalWrite, 
  // if we used constant +5V supply, this can't be controlled programmatically.
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenLED, HIGH);
  delay(fastDelay);
  digitalWrite(greenLED, LOW);
  delay(100);  
  digitalWrite(greenLED, HIGH);
  delay(100);
  digitalWrite(greenLED, LOW);
  delay(100);  
  digitalWrite(greenLED, HIGH);
  delay(100); 


  digitalWrite(greenLED, HIGH);
  delay(400);
  digitalWrite(greenLED, LOW);
  delay(400);
  digitalWrite(greenLED, HIGH);
  delay(400);
  digitalWrite(greenLED, LOW);
  delay(400);
  digitalWrite(greenLED, HIGH);
  delay(400);
  digitalWrite(greenLED, LOW);
  delay(400);
  digitalWrite(greenLED, HIGH);
  delay(400);
  digitalWrite(greenLED, LOW);
  delay(400);
  digitalWrite(greenLED, HIGH);
  delay(400);
  digitalWrite(greenLED, LOW);
  delay(400);
  digitalWrite(greenLED, HIGH);
  delay(400);

  // Blue LED - 14 full blinks
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);
  digitalWrite(blueLED, HIGH);
  delay(1000);
  digitalWrite(blueLED, LOW);
  delay(1000);

  // 15th blink, ending on HIGH as requested
  digitalWrite(blueLED, HIGH); 

}
