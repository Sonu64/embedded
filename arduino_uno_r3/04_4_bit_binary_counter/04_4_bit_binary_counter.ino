int thirdBit = 8; // MSB
int secondBit = 7;
int firstBit = 6;
int zerothBit = 5; // LSB

const int lastDelay = 1000;
const int maxNum = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(thirdBit, OUTPUT);
  pinMode(secondBit, OUTPUT);
  pinMode(firstBit, OUTPUT);
  pinMode(zerothBit, OUTPUT);
}

void loop() {
  int i = 0;
  for(i = 0; i <= maxNum; i++) {
    digitalWrite(thirdBit, bitRead(i, 3));
    digitalWrite(secondBit, bitRead(i, 2));
    digitalWrite(firstBit, bitRead(i, 1));
    digitalWrite(zerothBit, bitRead(i, 0));
    delay(lastDelay);
  }
}
