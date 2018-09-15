

  /*----------( Declare DHT11 )----------*/
  //the following is setup for sensor
#include "dht.h"
dht DHT;

  //connected digital 2 to DHT11 pin2
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

const int rs = 4, en = 5, d4 = 6, d5 = 8, d6 = 9, d7 = 10;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  /*----------( Declare Auduino Setup & Loop )----------*/
void setup()
{
  lcd.begin(16, 2);
}

void loop()
{

  int chk = DHT.read11(DHT_PIN);
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");

  lcd.setCursor(6, 0);
  lcd.print(DHT.temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("RH:");

  lcd.setCursor(6, 1);
  lcd.print(DHT.humidity);
  lcd.print("%");

  delay(2000);
  
}
