/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

// Sensor: IR rv 1838b 

#include <IRremote.h>

int RECV_PIN = 11;
int led = 3;
int result = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    result = 1;
    irrecv.resume(); // Receive the next value
  }
  if(result && results.value == 0xffa25d) {
     digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  delay(100);
  result = 0;
}
