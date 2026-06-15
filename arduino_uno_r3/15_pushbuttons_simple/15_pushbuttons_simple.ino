const int baudRate = 9600;
const int dt = 500;
const int buttonPin = 9; // digital i/o 
const int ledPin = 11;

const turnOnLED() {
  Serial.println("ON");
  digitalWrite(ledPin, HIGH);
}

const turnOffLED() {
  Serial.println("OFF");
  digitalWrite(ledPin, LOW);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(baudRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonValue = digitalRead(buttonPin);
  Serial.println(buttonValue);
  if(buttonValue==1)  
    turnOnLED();
  else if(buttonValue==0)
    turnOffLED();
  else
    Serial.println("Error!");
}
