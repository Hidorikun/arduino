/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-servo-motor
 */

#include <Servo.h>
#include <ezButton.h>

// constants won't change
const int LED_PIN = 6; // Arduino pin connected to button's pin
const int SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin

Servo servo;                 // create servo object to control a servo

// variables will change:
int angle = 0; // the current angle of servo motor
int intensity = 0;

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void setup() {
  Serial.begin(9600);         // initialize serial
  servo.attach(SERVO_PIN);    // attaches the servo on pin 9 to the servo object

  pinMode(LED_PIN, OUTPUT);
  
  servo.write(angle);
}

int analogValue = 0;
void loop() {
 
  analogValue = analogRead(A0);
  angle = map(analogValue, 0, 1023, 0, 180);
  intensity = map(analogValue, 0, 1023, 0, 255);
  
  Serial.println(angle);
  analogWrite(LED_PIN, intensity);
  servo.write(angle);

  delay(100);

}
