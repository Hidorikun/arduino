#include <ezButton.h>

const int vrx = A0;
const int vry = A1;
const int middle = 520;
const int sw = 8;
const int left = 13;
const int right = 12;
const int up = 11;

ezButton button(sw);

int x = 0;
int y = 0;
int treshold = 50;

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(50);
  
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);

  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
}
void turnOffLeds() {
    digitalWrite(left, LOW);
    digitalWrite(right, LOW);
    digitalWrite(up, LOW);
    digitalWrite(down, LOW);
}
void loop() {
  turnOffLeds();
  
  button.loop();

  if (button.isPressed()) {
    Serial.println("The button is pressed");
    // TODO do something here
  }

  if (button.isReleased()) {
    Serial.println("The button is released");
    // TODO do something here
  }
  
  x = analogRead(vrx);
  y = analogRead(vry);
  
  if ( x < middle - treshold ) {
    Serial.print("LEFT ");
    digitalWrite(left, HIGH);
  } else if ( x > middle + treshold) {
    Serial.print("RIGHT ");
    digitalWrite(right, HIGH);
  }

  if ( y > middle + treshold ) {
    Serial.print("UP ");
    digitalWrite(up, HIGH);
  } else if ( y < middle - treshold ) {
    Serial.print("DOWN ");
    digitalWrite(down, HIGH);
  }

  Serial.println();
}
