#include "Arduino.h"
#include "PWM.h"
#include "Wheel_motors.h"
#include "SAMD51_InterruptTimer.h"




void setup() {
  // put your setup code here, to run once:
  msetup();
  attachInterrupt(digitalPinToInterrupt(ENC1A),readEncoder, RISING);

  TC.startTimer(10, myISR); // 10 usec is 100 KHz interrupt rate
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1){
    motor1desiredposition(90);
    while(flag!=1){
      ;
    }
    
    
  }

    }



    
