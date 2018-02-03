#include <Servo.h>
Servo leftMotor;
Servo rightMotor;
long duration;

void setup() {
  leftMotor.attach(12);
  rightMotor.attach(13);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (analogRead(A0) == 0) {
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);
    delayMicroseconds(2);
    digitalWrite(2, HIGH);
    delayMicroseconds(5);
    digitalWrite(2, LOW);
    pinMode(3, INPUT);
    duration = pulseIn(3, HIGH);
    Serial.println(duration);
    if (duration > 500) {
      leftMotor.write(60);
      rightMotor.write(120);
      delay(1000);
    }else{
      leftMotor.write(120);
      rightMotor.write(60);      
    }
  }else{
    if (analogRead(A1) > 450) {
      leftMotor.write(60);
      rightMotor.write(60);
      delay(100);
    }else{
      leftMotor.write(120);
      rightMotor.write(60);      
    }
  }
}
