    void setup() {
  // put your setup code here, to run once:
  Serial.begin(9800);
  pinMode(0, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(0, LOW);
  digitalWrite(12, LOW);
  delay(500);
  Serial.println("hello");
}
