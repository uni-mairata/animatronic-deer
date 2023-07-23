#include <Servo.h>

// https://docs.google.com/document/d/1_4tuXZZ5_G_912kXA4GW_KMbHo_X2EBuh6BexnRfb7Q/edit#
// for Arduino Nano Every

// Servos
Servo headServo;
Servo legServoFront;
Servo legServoBack;

// Servo positions idle:
int frontIdlePos = 150;
int backIdlePos = 130;

int frontWalkPos1 = 150;
int backWalkPos1 = 30;

int frontWalkPos2 = 40;
int backWalkPos2 = 130;

int frontJumpPos = 30;
int backJumpPos = 20;

int headIdlePos = 0;
int headTurnedPos = 62;

// pin constants
const int buttonPin = 7;
const int ledPin = 2;
const int headServoPin = 3;
const int legServoFrontPin = 5;
const int legServoBackPin = 6;
const int butterflyPneumaticPin = 8;

int buttonState = 0; // variable for reading the button status

void setup() {
  // put your setup code here, to run once:
  headServo.attach(headServoPin);
  legServoFront.attach(legServoFrontPin);
  legServoBack.attach(legServoBackPin);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the button pin as an input pullup:
  pinMode(buttonPin, INPUT_PULLUP); // HIGH = not pressed, LOW = pressed
  // initialize the pneumatic pin as an output:
  pinMode(butterflyPneumaticPin, OUTPUT);

  // init servo positions
  headServo.write(headIdlePos);
  legServoFront.write(frontIdlePos);
  legServoBack.write(backIdlePos);
  
  digitalWrite(butterflyPneumaticPin, LOW);
}

void loop() {
  // wait in loop and check the state of the button
  // when pressed, break out of loop
  while (digitalRead(buttonPin) == HIGH) {
    continue;
  }

  // "Welcome to the creature exhibit at..."
  digitalWrite(ledPin, HIGH); // turn LED on

  delay(6500); // pause 6.5 seconds

  // "As you travel further into Georgia..."
  deerWalk(4);
  deerStop();

  delay(1300); // pause 1.3 seconds

  deerWalk(2);
  deerStop();

  delay(300); // pause 0.3 seconds

  // "The white-tailed deer is considered..."
  headServo.write(headTurnedPos);
  delay(3000); // pause 3 seconds
  headServo.write(headIdlePos);
  deerWalk(4);
  deerStop();

  delay(1500); // pause 1.5 seconds

  deerWalk(1);
  deerStop();
  delay(1000); // pause 1 second
  deerWalk(2);
  deerStop();

  // delay(18000); // pause 18 seconds
  headServo.write(headTurnedPos);
  deerWalk(4);
  deerStop();
  headServo.write(headIdlePos);
  deerWalk(6);
  deerStop();

  delay(7000); // pause 7 seconds

  deerRun(3);
  deerStop();

  delay(500); // pause 0.5 seconds

  deerJump(3);
  deerStop();

  delay(4000); // pause 4 seconds

  // start butterfly section

  digitalWrite(butterflyPneumaticPin, HIGH);
  headServo.write(headTurnedPos);
  delay(10000); // pause 10 seconds
  digitalWrite(butterflyPneumaticPin, LOW);
  headServo.write(headIdlePos);

  deerWalk(10);
  deerStop();
  
  digitalWrite(butterflyPneumaticPin, HIGH);
  headServo.write(headTurnedPos);
  delay(4000); // pause 4 seconds
  headServo.write(headIdlePos);
  delay(2500); // pause 2.5 seconds
  deerWalk(1);
  deerStop();
  digitalWrite(butterflyPneumaticPin, LOW);
  headServo.write(headTurnedPos);
  delay(3000); // pause 3 seconds
  headServo.write(headIdlePos);

  deerWalk(5);
  deerStop();
  
  digitalWrite(butterflyPneumaticPin, HIGH);
  headServo.write(headTurnedPos);
  delay(4000); // pause 4 seconds
  digitalWrite(butterflyPneumaticPin, LOW);
  delay(500); // pause 0.5 seconds
  headServo.write(headIdlePos);
  delay(2500); // pause 2.5 seconds
  
  deerWalk(3);
  deerStop();

  digitalWrite(butterflyPneumaticPin, HIGH);
  headServo.write(headTurnedPos);
  delay(8000); // pause 8 seconds
  digitalWrite(butterflyPneumaticPin, LOW);
  delay(1000); // pause 1 second
  headServo.write(headIdlePos);

  // reset motors back to idle positions
  headServo.write(headIdlePos);
  legServoFront.write(frontIdlePos);
  legServoBack.write(backIdlePos);
  digitalWrite(ledPin, LOW); // turn LED off
}

void deerWalk(int timesRepeated) {
  for (int i = 0; i < timesRepeated; i++) {
    legServoFront.write(frontWalkPos1);
    legServoBack.write(backWalkPos1);

    delay(550); // pause 0.55 seconds

    legServoFront.write(frontWalkPos2);
    legServoBack.write(backWalkPos2);
    
    delay(550); // pause 0.55 seconds
  }
}

void deerRun(int timesRepeated) {
  for (int i = 0; i < timesRepeated; i++) {
    legServoFront.write(frontWalkPos1);
    legServoBack.write(backWalkPos1);

    delay(220); // pause 0.22 seconds

    legServoFront.write(frontWalkPos2);
    legServoBack.write(backWalkPos2);
    
    delay(220); // pause 0.22 seconds
  }
}

void deerJump(int timesRepeated) {
  for (int i = 0; i < timesRepeated; i++) {
    legServoFront.write(frontJumpPos);
    legServoBack.write(backJumpPos);

    delay(250); // pause 0.25 seconds

    legServoFront.write(frontIdlePos);
    legServoBack.write(backIdlePos);
    
    delay(250); // pause 0.25 seconds
  }
}

void deerStop() {
  legServoFront.write(frontIdlePos);
  legServoBack.write(backIdlePos);
}