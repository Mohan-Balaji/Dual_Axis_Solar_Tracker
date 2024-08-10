#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char auth[] = "AuthToken";
char ssid[] = "WiFiSSID";
char pass[] = "WiFiPassword";

#define DHTPIN D7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  lcd.begin(D1, D2);
  lcd.backlight();
}

void loop() {
  Blynk.run();
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" %");

  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);

  delay(2000);
}
