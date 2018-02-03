#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
float sec = 0;
int mi = 0;
int hour = 0;
boolean stop = true;
void setup() {
  lcd.begin(16, 2);
  lcd.print("0:00:00.00");
}

void loop() {
  delay(200);
  if (analogRead(A0) == 0){
    if (stop == true) {
      stop = false;
    }else{
      stop = true;
    }
  }
  if (analogRead(A1) == 0){
   sec = 0;
   mi = 0;
   hour = 0;
   stop = true;
   lcd.clear();
  lcd.print("0:00:00.00");
  }
  if (stop == false) {
    lcd.clear();
    lcd.print(hour);
    lcd.print(":");
    if (mi < 10) {
      lcd.print("0");
    }
    lcd.print(mi);
    lcd.print(":");
    if (sec < 10) {
      lcd.print("0");
    }
    lcd.print(sec);
    sec = sec + 0.2;
    if (sec >= 60) {
      sec = 0;
      mi = mi + 1; 
      }
    if (mi >= 60) {
      mi = 0;
      hour = hour + 1;
    }
  }
}
