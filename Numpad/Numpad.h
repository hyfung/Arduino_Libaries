/*		Col 1 Col 2 Col 3
Row 1	1	2	3
Row 2	4	5	6
Row 3	7	8	9
Row 4	*	0	#

*/
#ifndef Numpad_h
#define Numpad_h
#include "Arduino.h"

/*
Class Numpad, initialized by:
Numpad myNumpad;
*/
class Numpad{
	public:
		//Numpad();
		void col(int x, int y, int z);
		void row(int w, int x, int y, int z);
		unsigned char getKey();
	private:
		unsigned char _col[3];
		unsigned char _row[4];
		unsigned char _key;
		unsigned long _ms;
		unsigned long _Threshold = 500;
};

/*
Set columns of matrix
Example
numpad.col(1,2,3)
*/
void Numpad::col(int x, int y, int z){
	_col[0] = x;
	_col[1] = y;
	_col[2] = z;
	for(int i=0;i<3;i++) pinMode(_col[i], INPUT_PULLUP);
}

/*
Set columns of matrix
Example
numpad.row(4,5,6,7)
*/
void Numpad::row(int w, int x, int y, int z){
	_row[0] = w;
	_row[1] = x;
	_row[2] = y;
	_row[3] = z;
	for(int i=0;i<4;i++) pinMode(_row[i], OUTPUT);
}

unsigned char Numpad::getKey(){
	unsigned char _keymap[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'}
	_key = 0;
	unsigned long new_ms = millis();
	if((new_ms - _ms) < _Threshold) return _key;
	// else _ms = new_ms;

	for(int i=0;i<4;i++){
		digitalWrite(_row[0], HIGH);
		digitalWrite(_row[1], HIGH);
		digitalWrite(_row[2], HIGH);
		digitalWrite(_row[3], HIGH);
		
		digitalWrite(_row[i], LOW);
		for(int j=0;j<3;j++){
			if(digitalRead(_col[j]) == 0){
				_key = _keymap[4*i+j];
				// _key = (3*i) + j + 1;
				_ms = millis();
			}
		}
	}
	return _key;
}

#endif
