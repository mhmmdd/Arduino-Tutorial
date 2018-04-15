int soundSensor = 2;
int led = 3;
int state = 0;
int treshold = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(soundSensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int statusSensor = digitalRead(soundSensor);

  if(statusSensor == 1) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  Serial.println(statusSensor);
  /*
  if(statusSensor >= treshold) {
    state = -state;
    digitalWrite(led, HIGH);
    delay(1000);
  } else {
    digitalWrite(led, LOW);
  }
  Serial.println(statusSensor);
  */
}
