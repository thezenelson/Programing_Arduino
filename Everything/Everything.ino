boolean change = true;
int pingPin = 7;
int distance = 0;
int alarm = 13;
int light = 12;

void setup() {
  Serial.begin(9600);
  pinMode(alarm, OUTPUT);
  pinMode(light, OUTPUT);
}

void loop()
{
  long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  if(change == true){
    distance = inches - 1;
    change = false;
  }
  
  if(distance > inches){
  Serial.print("Intruder");
  digitalWrite(alarm, HIGH);
  delay(20);
  digitalWrite(alarm, LOW);
  }
  
  if(analogRead(A0) < 125){
    digitalWrite(light, HIGH);
    Serial.print("on");
  }else{
    digitalWrite(light, LOW);
    Serial.print("off");
  }
  Serial.print(analogRead(A0));
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
