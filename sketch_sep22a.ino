const int clockPin = 0; // SN74HC164N
const int dataPinA = 1;
const int dataPinB = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(clockPin, OUTPUT);
  pinMode(dataPinA, OUTPUT);
  pinMode(dataPinB, OUTPUT);

}

// 0,1,2,3,4,5,6,7,8,9 // modif //dibalik antara G & H
byte z[]={B11111100,B01100010,B11011001,
          B11110011,B01100101,B10110111,
          B10111101,B11100010,B11111101,B11110111};

void loop() {
  // put your main code here, to run repeatedly:
  for (byte t=0;t<10;t++)
  {
    for (byte u=0;u<10;u++)
    {
      shiftOut(dataPinA, clockPin, LSBFIRST, z[u]);
      shiftOut(dataPinB, clockPin, LSBFIRST, z[t]);
      delay(300);
    }
  }

}
