const int clockPin = 9;
const int dataPin = 8; //74-164

void setup(){
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop(){
  //for(int i = 0; i<3; i++)
  {
    shiftOut(dataPin, clockPin, LSBFIRST, B10101010 );
    delay(1000);//125*8 = 1 second
  }
 //for(int i = 0; i<3; i++)
 {
    shiftOut(dataPin, clockPin, LSBFIRST, B10010110 );
    delay(1000);
  }

  {
    shiftOut(dataPin, clockPin, MSBFIRST, B10010110 );
    delay(1000);
  }

}
