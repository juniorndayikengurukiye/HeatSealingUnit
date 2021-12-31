#ifndef _wheelmotors_H
#define _wheelmotors_H





#define PWMpin2 10
#define PWMpin1 5
#define direc1 6
#define direc2 9



void msetup(); 

void forward(char mspeed);
void reverse(char mspeed);
void mstop();

  



#endif  // _wheelmotors_H
