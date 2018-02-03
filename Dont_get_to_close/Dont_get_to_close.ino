const int pingPin = 7;
int led = 13;
int led1 = 11;
int analogPin = 1;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  pinMode(led1, OUTPUT);   
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
  if(inches < 34){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  
  if(analogRead(A0)  < 100){
    Serial.println("on");
    digitalWrite(led1, HIGH);
  }else{
    Serial.println("off");
    digitalWrite(led1, LOW);
  }
  
  delay(1000);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
