#include "Arduino.h"
#include "PWM.h"
#include "Wheel_motors.h"

  int goodforwardspeed=70;
  int goodreversespeed=200;
  int goodextrusiontime=2000; //in milliseconds


void setup() {
  // put your setup code here, to run once:
  msetup();
  

}

void loop() {
  while(1){
   Serial.println("New Bag (1), Hold (0), retract bag (2)");
  while (Serial.available() == 0) {
}

int x = Serial.parseInt();
if (x==1){
  forward(goodforwardspeed);
  delay(goodextrusiontime);
  mstop();
  Serial.println("New Bag moved");
}
if (x==0){
  mstop();
  Serial.println("Bag not moved");
}
if (x==2){
  reverse(goodreversespeed);
  delay(goodextrusiontime);
  mstop();
  Serial.println("Bag retracted");
}
  }
    }
    



    
