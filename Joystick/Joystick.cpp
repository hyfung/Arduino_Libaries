#include "Joystick.h"
#include "Arduino.h"
Joystick::Joystick(int x, int y){
	pinMode(x, 0);
	pinMode(y, 0);
	_x = x;
	_y = y;
	_button = -255;
}

Joystick::Joystick(int x, int y, int button){
	pinMode(x, 0);
	pinMode(y, 0);
	pinMode(button, INPUT_PULLUP);
	_x = x;
	_y = y;
	_button = button;
}

int Joystick::X(){
	return analogRead(_x);
}

int Joystick::Y(){
	return analogRead(_Y);
}

int Joystick::buttonPressed(){
	if(_button != -255)
		return digitalRead(_button);
	else return -1;
}
