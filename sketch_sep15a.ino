const int clockPin = 0; //SN74HC164N
const int dataPinA = 1;
const int dataPinB = 2;
const int dataPinC = 3;
const int dataPinD = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(clockPin, OUTPUT);
  pinMode(dataPinA, OUTPUT);
  pinMode(dataPinB, OUTPUT);
  pinMode(dataPinC, OUTPUT);
  pinMode(dataPinD, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  shiftOut(dataPinA, clockPin, MSBFIRST, B10011001);
  delay(1000);
  shiftOut(dataPinB, clockPin, MSBFIRST, B01010101);
  delay(1000);
  shiftOut(dataPinC, clockPin, MSBFIRST, B01010110);
  shiftOut(dataPinD, clockPin, MSBFIRST, B01010100);
  delay(1000);

}
