#include <dht.h>
#include <LiquidCrystal.h>

#define dht_pin A0

dht DHT;
float tempF = 0;
const int RS = 12, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);

void setup()
{
  lcd.begin(16,2);
}  


void loop()
{
  DHT.read11(dht_pin);
  tempF = DHT.temperature * 1.8 + 32;
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempF);
  lcd.print("F");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  delay(2000); //Reduce Time for Quick Reply
}
