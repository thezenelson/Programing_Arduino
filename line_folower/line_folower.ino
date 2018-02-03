#include <Servo.h>
Servo leftMotor;
Servo rightMotor;

void setup() {
  leftMotor.attach(12);
  rightMotor.attach(13);
    Serial.begin(9600);
}

void loop() {
  int color = analogRead(A1);
  if (color < 500) {
  leftMotor.write(93);
  rightMotor.write(3);
  }else{
    leftMotor.write(183);
    rightMotor.write(93);
  }
  Serial.println(color);
}
