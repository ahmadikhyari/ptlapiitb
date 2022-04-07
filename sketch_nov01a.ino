int incomingByte = 0; // for incoming serial data
int nz = 0;
const int clockPin = 0; // SN74HC164N
const int dataPin = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  incomingByte = Serial.parseInt(); // 32767
  if(incomingByte == 0) {
    nz = nz;
  }
  else {
    nz = incomingByte;
  }
  shiftOut(dataPin, clockPin, LSBFIRST, Serial.println(nz, BIN));
  delay(300);

}
