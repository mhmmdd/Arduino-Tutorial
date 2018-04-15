const int potantiometerPin = A0;
const int buzzerPin = 11;
int potantiometerVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potantiometerVal = analogRead(potantiometerPin);
  int mappedVal = map(potantiometerVal, 0, 1023, 0, 255);
  Serial.println(potantiometerVal);
  Serial.print(" - ");
  Serial.println(mappedVal);
  analogWrite(buzzerPin, mappedVal);
  delay(10);
}
