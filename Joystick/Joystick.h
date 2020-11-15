#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"
class Joystick{
	public:
		Joystick(int x, int y);
		Joystick(int x, int y, int button);
		int X();
		int Y();
		int buttonPressed();
	private:
	int _x;
	int _y;
	int _button;
};

#endif
