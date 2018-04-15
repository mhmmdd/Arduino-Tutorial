int x = A0;
int y = A1;
int buttonPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xValue = analogRead(x);
  int yValue = analogRead(y); 
  int buttonValue = digitalRead(buttonPin); 

  if(buttonValue == HIGH && xValue != 520 && yValue !=512) {
    Serial.print("X: ");
    Serial.println(xValue);
    Serial.print("Y: ");
    Serial.println(yValue);
  
    Serial.println("");
  }
  delay(100);
}
