#include <Wire.h>
#include <LiquidCrystal_I2C.h> LiquidCrystal_I2C lcd(0x27 ,16,2); //GANTI 0x3F Ke 0x27 kalau LCD ga muncul
#include <DHT.h>
DHT dht(3, DHT11); //Pin, Jenis DHT
int indikator = 13; // buat indikatorLED
int inputVout = 8; // Vout PIR
int statusPIR = 0; // status logical
int data = 0; // variabel temporary utkmenampung data PIR
int powerPin = 2; // untuk penggantiVCC/5vOLT
const int pirSensor = 13;
void setup(){
lcd.init();
// Print a message to the LCD.lcd.backlight();
// jadikan pin power sebagai outputpinMode(powerPin, OUTPUT);
// default bernilai LOW digitalWrite(powerPin, LOW);
Serial.begin(9600);
dht.begin();
lcd.print("Hello");
lcd.setCursor(0,1);
delay(1000);
lcd.print(" ");
lcd.setCursor(0,1);
lcd.print("world");
lcd.setCursor(5,1);
delay(1000);
lcd.backlight();
pinMode(pirSensor, INPUT); lcd.setCursor(0,0);
 lcd.print("tedapat sensor");
 lcd.setCursor(0,1);
 lcd.print("suhu ");
 delay(5000);
 lcd.clear();
 pinMode(indikator, OUTPUT); //set pin 13 sbg output
 pinMode(inputVout, INPUT); // set pin 2 sbg input
 Serial.begin(9600); //serial monitor
 
}
void loop(){
digitalWrite(powerPin, HIGH);
data = digitalRead(inputVout); // baca input dr Vout
if ((data == HIGH) && (statusPIR == LOW)) { // cek jika ada pergerakan
digitalWrite(indikator, HIGH); // nyalakan led indikator di board Arduino
Serial.println("gerakan terdeteksi"); //buat monitor ke laptop;
statusPIR = HIGH; //diset high spy tdk mendeteksi terus
} else {
 if ((data == LOW) && (statusPIR == HIGH)){
 digitalWrite(indikator, LOW); // matikan led indikator
 Serial.println("gerakan berehenti"); //buat monitor ke laptop
 statusPIR = LOW;
 }
}
 
float kelembapan = dht.readHumidity();
float suhu = dht.readTemperature();
Serial.print(kelembapan);
Serial.print(" ");
Serial.print("suhu: ");
Serial.println(suhu);
 lcd.setCursor(0,0);
 lcd.print("kelembapan : ");
 lcd.setCursor(11,0);
 lcd.print(kelembapan);
 lcd.setCursor(0,1);
 lcd.print("Suhu: ");
 lcd.setCursor(5,1);
 lcd.print(suhu);
 delay(100);
 
 }
