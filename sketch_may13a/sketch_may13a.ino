#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sec = 0;
int mi = 0;
int hour = 0;
boolean pause = false;
boolean cut = true;

void setup() {
  Serial.begin(9600);
  lcd.clear();
  lcd.print("0:00:00");
}

void loop() {
if (analogRead(A0) == 0) {
  if (pause == true){
    pause = false;
  }else{
    pause = true;      
  }
}
if (analogRead(A1) == 1023) {
  if (cut == true){
    cut = false;
  }else{
    cut = true;
    delay(500);  
  }
}
if (analogRead(A2) == 1023) {
  sec = 0;
  mi = 0;
  hour = 0;
  pause = false;
  cut = true;
  lcd.clear();
  lcd.print("0:00:00");
}

delay(500);
if (pause == false && cut == false) {
  lcd.clear();
  lcd.print(hour);
  lcd.print(":");
  if (mi < 10){
    lcd.print(0);
  }
  lcd.print(mi);
  lcd.print(":");
  if (sec < 10){
    lcd.print(0);
  }
  lcd.print(sec);
}

  if (cut == false){
    delay(500);
    sec = sec + 1;
    if (sec == 60) {
      sec = 0;
      mi = mi + 1;
    }
    if (mi == 60) {
      mi = 0; 
      hour = hour + 1;
    }
  }
}
