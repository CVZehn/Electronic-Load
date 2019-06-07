#ifndef _KEY_H_
#define _KEY_H_

#include "gpio.h"
#include "delay.h"

unsigned char Get_keynum();
unsigned char Get_Keyvalue();
extern unsigned char keyvalue[3];

#endif