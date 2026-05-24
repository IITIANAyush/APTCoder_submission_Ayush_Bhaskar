#include <ESP32Servo.h>

#define TRIG_PIN 5
#define ECHO_PIN 18
#define SERVO_PIN 19
#define LED_PIN 2

Servo gateServo;

long duration;
float distance;

bool gateOpen = false;

// Measure distance
float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
}

// Blink LED
void blinkLED() {

  digitalWrite(LED_PIN, HIGH);
  delay(10);

  digitalWrite(LED_PIN, LOW);
  delay(10);
}

// Open gate
void openGate() {

  for (int pos = 0; pos <= 90; pos++) {

    gateServo.write(pos);

    blinkLED();
  }

  gateOpen = true;
}

// Close gate
void closeGate() {

  for (int pos = 90; pos >= 0; pos--) {

    gateServo.write(pos);

    blinkLED();
  }

  gateOpen = false;
}

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);

  gateServo.attach(SERVO_PIN);

  gateServo.write(0);
}

void loop() {

  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  // Open only once
  if (distance < 20 && !gateOpen) {

    Serial.println("Opening Gate");

    openGate();
  }

  // Close only once
  else if (distance >= 20 && gateOpen) {

    Serial.println("Closing Gate");

    closeGate();
  }

  delay(200);
}