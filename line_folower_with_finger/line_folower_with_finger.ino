#include <Servo.h>
Servo leftMotor;
Servo rightMotor;
Servo finger;

void setup() {
  finger.attach(10);
  leftMotor.attach(12);
  rightMotor.attach(13);
  Serial.begin(9600);
}

void loop() {
  int color = analogRead(A1);
  int distance = (A0);
  
  if (distance > 300){
    finger.write(0);
    if (color < 500) {
      leftMotor.write(93);
      rightMotor.write(3);
    }else{
      leftMotor.write(183);
      rightMotor.write(93);
    }
  }else{
    finger.write(0);
  }
}
