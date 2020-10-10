const int buttonPin = 4;
const int motorPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);
  delay(100);
  if (!buttonState) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
    delay(50);
  }
  }
