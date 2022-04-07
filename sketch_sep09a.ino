const int clockPin = 0;
const int dataPin1 = 2; //SN74HC164N

void setup() {
  // put your setup code here, to run once:
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  shiftOut(dataPin1, clockPin, MSBFIRST, B10101001);
  delay(1000);

}
