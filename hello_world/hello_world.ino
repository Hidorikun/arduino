 int led = 11;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(led, HIGH);
  Serial.println("blink");
  delay(500);
  digitalWrite(led, LOW);
  Serial.println("stop");
  delay(500);
    
}
