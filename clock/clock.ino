#include <Wire.h>
#include <LiquidCrystal.h>
#define MILLIS_OVERFLOW 34359738
unsigned long currentMillis, previousMillis, elapsedMillis;
int seconds, minutes, hours, day, month, year;
boolean am = true;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() {
  year = 2016;
  hours = 12;
  day = 1;
  month = 1;
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  currentMillis = millis();
  if (currentMillis < previousMillis){
    elapsedMillis += MILLIS_OVERFLOW - previousMillis + currentMillis;
  } else {
    elapsedMillis += currentMillis - previousMillis;
  }
  if (elapsedMillis > 999){
    seconds++;
    elapsedMillis = elapsedMillis - 1000;
  }
  if (seconds == 60){
    minutes++;
    seconds = 0;
  }
  if (minutes == 60){
    hours++;
    minutes = 0;
  }
  if (hours == 13){
    am = false;
    hours = 1;
    if (am = false) {
      day++;
    }
  }
  if (month == 13) {
    year++;
    month = 1;
  }
  if (day == 32) {
    month++;
  }
  if (day == 31) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      month++;
    }
  }
if (day == 29 && month == 2) {
  month++;
}
previousMillis = currentMillis;
  lcd.setCursor (0, 0);
  if (hours < 10) {
    lcd.print("0");
  }
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) {
    lcd.print("0");
  }
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) {
    lcd.print("0");
  }
  lcd.print(seconds);
  /*if (am = true) {
    lcd.print("am");
  }else{
    lcd.print("pm");
  }*/
  lcd.setCursor (0, 1);
  lcd.print(month);
  lcd.print("/");
  lcd.print(day);
  lcd.print("/");
  lcd.print(year);
  lcd.print("        ");
  
  if (analogRead(A0) == 0) {
    month++;
    delay(500);
  }
  if (analogRead(A1) == 0) {
    day++;
    delay(500);
  }
  if (analogRead(A2) == 0) {
    hours++;
    delay(500);
  }
  if (analogRead(A3) == 0) {
    minutes++;
    delay(500);
  }
  if (analogRead(A4) == 0) {
    seconds = 0;
  }
}
