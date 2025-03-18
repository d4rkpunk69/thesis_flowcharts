#include <Arduino.h>
const int trigPin = 7;
const int echoPin = 6;
int err = 0;
int timeout = 30000;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLUP);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, timeout);
  float distance =(duration/2) * 0.034;
  if (distance != 0) {
  Serial.printf("Distance: %f mm -- tested: %i\n", distance, err);
  } else {
    err++;
    // Serial.printf("error: %i\n",err);
  }
  delayMicroseconds(1000);
}