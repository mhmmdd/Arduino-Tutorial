#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup(){
  
  lcd.begin(16,2);               // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("abi nasilsin");
}

void loop() {

}
