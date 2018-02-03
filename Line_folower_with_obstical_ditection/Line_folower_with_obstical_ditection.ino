#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

void setup()
{
  leftMotor.attach(12);
  rightMotor.attach(13);
    Serial.begin(9600);
}

void loop() {
  int line = analogRead(A1);
  int distance = analogRead(A0);
  if (distance  <  300) {
    if (line < 30) {
      leftMotor.write(153);
      rightMotor.write(93);
      Serial.println("less than 30");
    }else{
      leftMotor.write(93);
      rightMotor.write(33);
      Serial.println("more than 30");
    }
  }else{      
    leftMotor.write(63);
    rightMotor.write(3);
  }
    Serial.println(distance);
    delay(100);
}
