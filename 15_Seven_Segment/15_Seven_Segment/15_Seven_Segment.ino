int strobePin = 3;
//Pin connected to Data (pin 2) of 4094
int dataPin = 5;
//Pin connected to Clock (pin 3) of 4094
int clockPin = 4;
//Pin connected to OE (pin 15) of 4094
int oePin = 2;

/* Decimal representation of binary numbers for each
digit in the 7 segment display from 0 to 9

*/
byte segChar[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(strobePin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(oePin, OUTPUT);
  digitalWrite(oePin, HIGH);
  Serial.begin(9600);
}

void loop() {
  //count up routine

  for (int i = 0; i < 10; i++) {
    //set strobe pin low to begin storing bits
    digitalWrite(strobePin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, segChar[i]);  
    Serial.print(MSBFIRST);
    //set strobe pin high to stop storing bits
    digitalWrite(strobePin, HIGH);
    delay(500);
  }
}
