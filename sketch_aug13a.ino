
int ledPin = 3;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(ledPin, OUTPUT); // Defines PIN with connected LED as
  // output

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ledPin, HIGH); // turns on LED
  delay(200); // waits a second
  digitalWrite(ledPin, LOW); // turns off LED
  delay(200); // waits a second
  
}
