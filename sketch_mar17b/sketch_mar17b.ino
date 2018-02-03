int bright = 0;
int led = 11;
int count = 200;

void setup(){
    pinMode(11, OUTPUT);
}

void loop() {
  if (count > 100){
    bright = bright + 1;
  }
  if (count < 100){
    bright = bright - 1;
  }
  if (count == 0){
  count = 200;
  }
  delay(10);
  count = count - 1;
  analogWrite(led, bright);
}
