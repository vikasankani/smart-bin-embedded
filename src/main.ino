#include <Servo.h>
#include <SoftwareSerial.h>

// Pins
#define TRIG_OUT 9
#define ECHO_OUT 10

#define TRIG_IN 7
#define ECHO_IN 8

#define SERVO_PIN 6

// Bluetooth
SoftwareSerial BT(2, 3); // RX, TX

Servo myServo;

float BIN_HEIGHT = 30; // cm (measure your bin)

// Function to get distance
float getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  pinMode(TRIG_OUT, OUTPUT);
  pinMode(ECHO_OUT, INPUT);

  pinMode(TRIG_IN, OUTPUT);
  pinMode(ECHO_IN, INPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(0);

  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {

  // Read outer sensor (lid control)
  float outerDist = getDistance(TRIG_OUT, ECHO_OUT);
  delay(50);

  // Read inner sensor (fill level)
  float innerDist = getDistance(TRIG_IN, ECHO_IN);

  float fillLevel = BIN_HEIGHT - innerDist;

  // Print debug
  Serial.print("Outer: ");
  Serial.print(outerDist);
  Serial.print(" | Inner: ");
  Serial.print(innerDist);
  Serial.print(" | Fill: ");
  Serial.println(fillLevel);

  // Lid control
  if (outerDist < 20) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }

  // Fill alert
  if (fillLevel > 25) {
    Serial.println("Bin FULL");
    BT.println("Bin is FULL");
  }

  delay(500);
}
