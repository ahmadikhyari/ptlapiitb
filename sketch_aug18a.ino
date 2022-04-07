const int clockPin = 11;
const int latchPin = 12;
const int dataPin = 13; 

void setup() {
  // put your setup code here, to run once:
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B10111010 );
  digitalWrite(latchPin, HIGH);
  delay(1000);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B01001101 );
  digitalWrite(latchPin, HIGH);
  delay(200);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B01110001 );
  digitalWrite(latchPin, HIGH);
  delay(200);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B11111111 );
  digitalWrite(latchPin, HIGH);
  delay(200);

}
