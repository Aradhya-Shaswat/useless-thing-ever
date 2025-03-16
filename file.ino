#include <Servo.h>

Servo myServo;

const int sensorPin = 2; // Wire connected to pin D2
const int servoPin = 9;

void setup() {
  pinMode(sensorPin, INPUT_PULLUP); // Use internal pull-up resistor
  myServo.attach(servoPin);
  myServo.write(0); // Start servo at 0 degrees
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(sensorPin) == LOW) { // When wires touch (signal detected)
    Serial.println("Sensation Detected!");
    myServo.write(90); // Move servo to press taser
  } else {
    myServo.write(0); // Release when wires disconnect
  }
}
