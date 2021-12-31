#include "Arduino.h"
#include "Wheel_motors.h"
#include "PWM.h"


extern volatile int mposition1 = 0; 

extern volatile int mdegrees1 = 0;




volatile int error;
int Kp=2;
int newPWM;
int desiredpos=250;//in degrees

void msetup(){
  pinMode(direc1, OUTPUT);
  pinMode(ENC1A, INPUT);
  pinMode(ENC1B, INPUT);
}

void readEncoder(){
  if (digitalRead(direc1)==0){
    mposition1--;
  }
  else{
    mposition1++;
  }
}

void forward(char mspeed){
  digitalWrite(direc1, 1);
  digitalWrite(direc2, 0);
  PWM(PWMpin, mspeed); 
}

void reverse(char mspeed){
  digitalWrite(direc1, 0);
  digitalWrite(direc2, 1);
  PWM(PWMpin, mspeed); 
}

void mstop(){
  PWM(PWMpin, 0);
}

int getDegrees(){
  mdegrees1=mposition1*(360/312.5);
  return(mdegrees1);
}

void myISR(){
  error=desiredpos-getDegrees();
  newPWM=Kp*abs(error);
  if (newPWM>250){
    newPWM=250;    //make sure motor doesnt go over max speed
  }
  
  if (error<-1){
    reverse(newPWM);
  } else if (error>1){
    forward(newPWM);
  } else {
    mstop();
    mposition1=0;
  }
}

void motor1desiredposition(int desired){
  if (PWMpin==0){
    desiredpos=desired;
  }
}
