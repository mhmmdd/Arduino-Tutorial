#include <Arduino.h>

//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int waterSens = A0; //define water sensor
const int led = 9;//define led to pin 9
int waterVal; //define the water sensor value

void setup()
{
  pinMode(12, OUTPUT);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");

}

void loop()
{
  waterVal = analogRead(waterSens); 

  lcd.clear();
  lcd.home();
  lcd.noBlink();

  if(waterVal == 0) {
    digitalWrite(12, HIGH);
    lcd.print("Su yok");
  } 
  else {
    digitalWrite(12, LOW);
    lcd.print("Su var");
  }

  delay(1000);
}