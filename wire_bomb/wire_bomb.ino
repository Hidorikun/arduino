int greenPin = 12;
int redPin = 13;

int wire1 = 7;
int wire2 = 8;
int wire3 = 9;
int wire4 = 10;
int wire5 = 11;

boolean lose = false;
boolean win = false;

boolean isAliveWire1;
boolean isAliveWire2;
boolean isAliveWire3;
boolean isAliveWire4;
boolean isAliveWire5;
boolean allAlive;

void setup() {
  Serial.begin(9600);
  
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);  
  
  pinMode(wire1, INPUT);
  pinMode(wire2, INPUT);
  pinMode(wire3, INPUT);
  pinMode(wire4, INPUT);
  pinMode(wire5, INPUT);  
}

void loop() {

  win = false;
  lose = false;
  
  isAliveWire1 = digitalRead(wire1);
  isAliveWire2 = digitalRead(wire2);
  isAliveWire3 = digitalRead(wire3);
  isAliveWire4 = digitalRead(wire4);
  isAliveWire5 = digitalRead(wire5);

  allAlive = (isAliveWire1 && isAliveWire2 && isAliveWire3 && isAliveWire4 && isAliveWire5);

  Serial.print("allAlive ");
  Serial.println(allAlive);
  
  if (!allAlive) {
    if (!isAliveWire1) {
      win = true;
    } else {
      lose = true;
    }
  }
  
  if (win) {   
    digitalWrite(greenPin, HIGH);
  }

  if (lose) {
    digitalWrite(redPin, HIGH);
  }
    
  delay(500);
}
