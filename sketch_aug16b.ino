int greenPin = 8;
int yellowPin = 9;
int redPin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenPin, HIGH); // turns on green LED
delay(3000); // waits 5 seconds
digitalWrite(greenPin, LOW); // turns off green LED
for(int i=0;i<3;i++) // flashes 3x
{
delay(100); // waits 5 seconds
digitalWrite(yellowPin, HIGH); // turns on yellow LED
delay(100); // waits 5 seconds
digitalWrite(yellowPin, LOW); // turns off yellow LED
}
delay(300); // waits 5 seconds
digitalWrite(redPin, HIGH); // turns on red LED
delay(1000); // waits 5 seconds
digitalWrite(redPin, LOW);

}
