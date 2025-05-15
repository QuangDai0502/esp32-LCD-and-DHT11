#include <Wire.h> //thu vien I2C
#include <LiquidCrystal_I2C.h> //thu vien man hinh lcd
#include <DHT.h> //thu vien cam bien DHT11
#include <Adafruit_Sensor.h>

#define dhttype DHT11 //khai bao loai cam bien
#define dhtpin 4 //khai bao chan
DHT dht(dhtpin,dhttype);

LiquidCrystal_I2C lcd(0x27,16,2); //khai bao man hinh

void setup() {
    lcd.init(); //khoi tao man hinh
    lcd.backlight(); //hien thi den nen
    dht.begin();
}

void loop() {
    float h = dht.readHumidity(); //doc do am
    float c = dht.readTemperature(); //doc nhiet do C
    float f = dht.readTemperature(true); //doc nhiet do F

    if (isnan(h) || isnan(c) || isnan(f)){
        lcd.print("ERROR");
        lcd.clear();
        return;
    }

    lcd.print("DOAM:");
    lcd.print(h);
    lcd.setCursor(0,1);
    lcd.print("C:");
    lcd.print(c);
    lcd.print(" F:");
    lcd.print(f);
    delay(1000);
    lcd.clear();
}