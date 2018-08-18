#include <Arduino.h>
#include <Sim800L.h>
#include <SoftwareSerial.h>

#define RX  10
#define TX  11
Sim800L GSM(RX, TX);

char* text;
char* number;
bool error; 

void setup() {
    Serial.begin(9600);
    GSM.begin(); 
}

void loop() {
    // put your main code here, to run repeatedly:
			
	text="Testing Sms";  		//text for the message. 
	number="5525155"; 		//change to a valid number.
    Serial.println("basla"); 
	error=GSM.sendSms(number, text);
    Serial.println(error); 
    Serial.println(GSM.getOperator()); 
    Serial.println(GSM.getProductInfo()); 
}