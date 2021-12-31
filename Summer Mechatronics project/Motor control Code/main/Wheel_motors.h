#ifndef _wheelmotors_H
#define _wheelmotors_H





#define ENC1A 10
#define ENC1B 11
#define PWMpin 5
#define direc1 6
#define direc2 9



void msetup(); 
void readEncoder();
void forward(char mspeed);
void reverse(char mspeed);
void mstop();
int getDegrees();
void myISR();
void motor1desiredposition(int desired);
  



#endif  // _wheelmotors_H
