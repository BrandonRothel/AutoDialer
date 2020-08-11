
#include <Servo.h>
int stepPin = D5;
int dirPin = D6;
int delayAmount = 1;
int currentNumber = 0;
int numTicks = 40;
Servo myservo;

int firstNum = 37;
int secondNum = 19;
int thirdNum = 9;

//Combo is 37, 19, 13
void setup() { 
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  myservo.attach(D7);
  myservo.write(155);
  delay(5000);
}

void loop() {
  inputCombo(firstNum, secondNum, thirdNum);
  tryShackle();
  delay(1000);
  rotateTo(true, 0);
  delay(1000);
  thirdNum = thirdNum+2;
}

void inputCombo(int firstNum, int secondNum, int thirdNum){
  clearCombo();
  rotateTo(true, firstNum);
  rotateOnce(false);
  rotateTo(false, secondNum);
  rotateTo(true, thirdNum);
}

void tryShackle(){
  myservo.write(100);
  delay(500);
  myservo.write(135);
  delay(200);
}

void clearCombo(){
  rotateOnce(true);
  rotateOnce(true);
  rotateOnce(true);
}

void rotateOnce(bool direction){
  moveDial(direction, numTicks);
}

void rotateTo(bool direction, int desiredNumber){
  int numberOfSteps;
  if (direction){
    numberOfSteps = currentNumber - desiredNumber;    
  } else {
    numberOfSteps = desiredNumber - currentNumber;
  }
  if (numberOfSteps < 0){
    numberOfSteps = numberOfSteps+numTicks;
  }
  moveDial(direction, numberOfSteps);
  currentNumber = desiredNumber;
}

void moveDial(bool direction, int numberOfSteps){
  digitalWrite(dirPin, direction);
  for(int i = 0; i<numberOfSteps; i++){
      stepOnce();
  }
}

void stepOnce(){
  for(int i = 0; i<5; i++){
    digitalWrite(stepPin, 1);
    delay(delayAmount);
    digitalWrite(stepPin, 0);
    delay(delayAmount);
  }
}

/*
  digitalWrite(dirPin, 1);
  for(int i = 0; i<200; i++){
    for(int j = 0; j<5; j++){
      stepOnce();
    }
    delay(500);
  }
  delay(1000);
  digitalWrite(dirPin, 0);
  for(int i = 0; i<200; i++){
    stepOnce();
  }
  delay(1000);
 */
