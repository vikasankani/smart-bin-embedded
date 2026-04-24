#include <Servo.h>

#define TRIG 5
#define ECHO 18
#define SERVO_PIN 19

Servo myServo;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0);

  Serial.begin(115200);
}

float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  float d = getDistance();

  if (d < 20) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }

  delay(200);
}
