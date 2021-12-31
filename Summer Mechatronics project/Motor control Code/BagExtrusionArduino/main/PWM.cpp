#include "PWM.h"
#include "Arduino.h"

void PWM(int pin, char PWMv) {
  pinMode(pin, OUTPUT); //intializes pin as output
  analogWrite(pin, PWMv); //creates the PWM
}
