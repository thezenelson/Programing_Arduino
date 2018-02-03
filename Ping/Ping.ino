const int pingPin = 7;
int noise = 12;
boolean change = true;
boolean alarm = false;
int distance = 0;
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(noise, OUTPUT);
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
  digitalWrite(noise, LOW);
  change = false;
}

if(distance > inches){
  alarm = true;
}

if(alarm == true){
  Serial.println();
  digitalWrite(noise, HIGH);
  Serial.print("introter   ");
  digitalWrite(led, LOW);
  delay(50);
  digitalWrite(led, HIGH);
}
  Serial.println(distance);  
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
