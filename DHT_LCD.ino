

  /*----------( Declare DHT11 )----------*/
  //the following is setup for sensor
#include "dht.h"
dht DHT;

  //connected digital 7 to DHT11 pin2

#define DHT_PIN 7

  //define what sensor you're using
  /*
  DHT11-Pin Define & connected
  Pin1 to VCC
  Pin2 to what pin we define, this project is Digital 2 (line 3)
  Pin3 means nothing
  Pin4 to GND
  */

  /*----------( Declare LCD )----------*/
#include <Wire.h>
#include <LiquidCrystal.h>

// Define lcd pins as header labels

const int rs = 4, en = 5, d4 = 6, d5 = 8, d6 = 9, d7 = 10;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  /*----------( Declare Auduino Setup & Loop )----------*/
void setup()
{
	// Initialize 16x2 LCD
  lcd.begin(16, 2);
}

void loop()
{
	
	//Read DHT sensor

  int chk = DHT.read11(DHT_PIN);
  
	//Move cursor to begin line 0, write static content
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
	
	//Advance cursor, write DHT temperature and unit
  lcd.setCursor(6, 0);
  lcd.print(DHT.temperature);
  lcd.print(" C");
	
	//Move cursor to begin line 1, write static content
  lcd.setCursor(0, 1);
  lcd.print("RH:");

	//Advance cursor, write DHT humidity and "unit"
  lcd.setCursor(6, 1);
  lcd.print(DHT.humidity);
  lcd.print("%");
	
	//Wait 2 seconds
		//DHT11 has max sample rate of 1 Hz
		//DHT22 has max sample rate of 2 Hz
  delay(2000);
  
}
