int pushButton = 7;
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println(digitalRead(pushButton));
  if (digitalRead(pushButton) == 1) {
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
  delay(1);
}



