const int flashlight =  12;
const int pump =  13;

void setup() {
  Serial.begin(9600);
   pinMode(flashlight, OUTPUT);
  pinMode(pump, OUTPUT);
}

void loop() {
  int water = analogRead(A0);
  int light = analogRead(A1);
  
  if (light < 180) {
    digitalWrite(flashlight, HIGH);
  }else{
    digitalWrite(flashlight, LOW);
  }

  if (water < 150) {
    digitalWrite(pump, HIGH);
  }else{
    digitalWrite(pump, LOW);
  }
}
