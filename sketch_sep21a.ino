const int clockPin = 0; //SN74HC164N
const int dataPin = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

// 0,1,2,3,4,5,6,7,8,9
byte z[]={B11111100,B01100001,B11011010,
          B11110011,B01100110,B10110111,
          B10111110,B11100001,B11111110,B11110111};

void loop() {
  // put your main code here, to run repeatedly:
  for (byte i=0;i<10;i++)
  {
    shiftOut(dataPin, clockPin, LSBFIRST, z[t]);
    delay(1000);
  }

}
