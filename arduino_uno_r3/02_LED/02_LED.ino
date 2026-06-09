void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT); 
  // this pin number 8 will have Arduino Provided +5V, but this can be controlled by digitalWrite, 
  // if we used constant +5V supply, this can't be controlled programmatically.
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);
}
