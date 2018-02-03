int led = 11;
int analogPin = 1;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue  < 100){
    Serial.println("on");
    digitalWrite(led, HIGH);
  }else{
    Serial.println("off");
    digitalWrite(led, LOW);
  }
  //delay(10000); 
}
