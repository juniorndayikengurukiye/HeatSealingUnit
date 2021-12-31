#include "Arduino.h"
#include "Wheel_motors.h"
#include "PWM.h"


void msetup(){
  pinMode(direc1, OUTPUT);
//  pinMode(ENC1A, INPUT);
//  pinMode(ENC1B, INPUT);
}



void reverse(char mspeed){
  digitalWrite(direc1, 1);
  digitalWrite(direc2, 0);
  PWM(PWMpin1, mspeed); 
  PWM(PWMpin2, mspeed);
}

void forward(char mspeed){
  digitalWrite(direc1, 0);
  digitalWrite(direc2, 1);
  PWM(PWMpin1, mspeed); 
  PWM(PWMpin2, mspeed); 
}

void mstop(){
  PWM(PWMpin1, 0); 
  PWM(PWMpin2, 0);
}
