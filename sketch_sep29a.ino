const int clockPin = 2; // SN74HC164N
const int dataPin = 3;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

}

// 0,1,2,3,4,5,6,7,8,9 on 5611AH, Babcdefgh in order
byte d[] = {
  B11111100 /*0*/, B01100001 /*1*/, B11011010 /*2*/, 
  B11110011 /*3*/, B01100110 /*4*/, B10110111 /*5*/, 
  B10111110 /*6*/, B11100001 /*7*/, B11111110 /*8*/, 
  B11110111 /*9*/};

// 0,1,2,3,4,5,6,7,8,9 on 5611AH, Bhgfedcba in order
//byte d[] = {
  //B00111111 /*0*/, B10000110 /*1*/, B01011011 /*2*/, 
  //B11001111 /*3*/, B01100110 /*4*/, B11101101 /*5*/, 
  //B01111101 /*6*/, B10000111 /*7*/, B01111111 /*8*/, 
  //B11101111 /*9*/};

void loop() {
  // put your main code here, to run repeatedly:
  for (byte t=0;t<10;t++) {
    for (byte u=0;u<10;u++) {

      int stat = u % 2;
      digitalWrite(LED_BUILTIN, stat);   // turn the LED on (HIGH is the voltage level)
      
      //shiftOut(dataPin, clockPin, LSBFIRST, d[9]);
      shiftOut(dataPin, clockPin, LSBFIRST, d[t]);
      //shiftOut(dataPin, clockPin, LSBFIRST, d[2]);
      shiftOut(dataPin, clockPin, LSBFIRST, d[u]);
      
      Serial.println(stat);
      
      delay(1000);
    }
  }

}
