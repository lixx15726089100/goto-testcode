#include <Arduino.h>
#include "BasicStepperDriver.h"
#include "OneButton.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
// X motor
#define DIR_X 10
#define STEP_X 11
// Y motor
#define DIR_Y 12
#define STEP_Y 13
// If microstepping is set externally
#define MICROSTEPS 32

//偏航和俯仰两组步进电机
BasicStepperDriver stepperX(MOTOR_STEPS, DIR_X, STEP_X);
BasicStepperDriver stepperY(MOTOR_STEPS, DIR_Y, STEP_Y);
//东西南北四个按键
OneButton buttonE(A0, true);
OneButton buttonW(A3, true);
OneButton buttonN(A2, true);
OneButton buttonS(A1, true);

// Target RPM for X axis motor
int MOTOR_X_RPM = 120;
// Target RPM for Y axis motor
int MOTOR_Y_RPM = 240;
//设定一个系数，方便用于调整速度
int SPEED = 720;

void setup() {
    Serial.begin(9600);
    
    buttonE.attachClick(clickE);
    buttonE.attachLongPressStart(longPressStartE);
    buttonE.attachLongPressStop(longPressStopE);
    buttonE.attachDuringLongPress(longPressE);
 
    buttonW.attachClick(clickW);
    buttonW.attachLongPressStart(longPressStartW);
    buttonW.attachLongPressStop(longPressStopW);
    buttonW.attachDuringLongPress(longPressW);
  
    buttonN.attachClick(clickN);
    buttonN.attachLongPressStart(longPressStartN);
    buttonN.attachLongPressStop(longPressStopN);
    buttonN.attachDuringLongPress(longPressN);
    
    buttonS.attachClick(clickS);
    buttonS.attachLongPressStart(longPressStartS);
    buttonS.attachLongPressStop(longPressStopS);
    buttonS.attachDuringLongPress(longPressS);
    
    stepperX.begin(MOTOR_X_RPM, MICROSTEPS);
    stepperY.begin(MOTOR_Y_RPM, MICROSTEPS);
}

void loop() {
    buttonE.tick();
    buttonW.tick();
    buttonN.tick();
    buttonS.tick();
}

void clickE() {
  stepperX.rotate(-0.5*SPEED);
} 
void longPressStartE() {
  stepperX.rotate(-0.5*SPEED);
} 
void longPressE() {
  stepperX.rotate(-0.5*SPEED);
} 
void longPressStopE() {
  stepperX.stop();
} 
void clickW() {
  stepperX.rotate(0.5*SPEED);
} 
void longPressStartW() {
  stepperX.rotate(0.5*SPEED);
} 
void longPressW() {
  stepperX.rotate(0.5*SPEED);
} 
void longPressStopW() {
  stepperX.stop();
} 

void clickN() {
  stepperY.rotate(-0.5*SPEED);
} 
void longPressStartN() {
  stepperY.rotate(-0.5*SPEED);
} 
void longPressN() {
  stepperY.rotate(-0.5*SPEED);
} 
void longPressStopN() {
  stepperY.stop();
} 
void clickS() {
  stepperY.rotate(0.5*SPEED);
} 
void longPressStartS() {
  stepperY.rotate(0.5*SPEED);
} 
void longPressS() {
  stepperY.rotate(0.5*SPEED);
} 
void longPressStopS() {
  stepperY.stop();
} 
