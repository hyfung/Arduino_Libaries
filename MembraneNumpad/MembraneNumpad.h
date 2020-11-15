/*	(4)   (3)   (2)   (1)
	Col1 Col2 Col 3 Col 4
(8)Row 1	1	2	3	A
(7)Row 2	4	5	6	B
(6)Row 3	7	8	9	C
(5)Row 4	*	0	#	D

*/
#ifndef Numpad_h
#define Numpad_h
#include "Arduino.h"

/*
Class Numpad, initialized by:
Numpad myNumpad;
*/
class MembraneNumpad{
	public:
		//Numpad();
		void col(int w, int x, int y, int z);
		void row(int w, int x, int y, int z);
		unsigned char getKey();
	private:
		unsigned char _col[4] = {0};
		unsigned char _row[4] = {0};
		unsigned char _key = 0;
		unsigned long _ms = 0;
		unsigned long _Threshold = 200;
};

/*
Set columns of matrix
Example
numpad.col(1,2,3,4)
*/
void MembraneNumpad::col(int w, int x, int y, int z){
	_col[0] = w;
	_col[1] = x;
	_col[2] = y;
	_col[3] = z;
	for(int i=0;i<4;i++) pinMode(_col[i], INPUT_PULLUP);
}

/*
Set columns of matrix
Example
numpad.row(4,5,6,7)
*/
void MembraneNumpad::row(int w, int x, int y, int z){
	_row[0] = w;
	_row[1] = x;
	_row[2] = y;
	_row[3] = z;
	for(int i=0;i<4;i++) pinMode(_row[i], OUTPUT);
}

unsigned char MembraneNumpad::getKey(){
	unsigned char _keymap[] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C','*', '0', '#', 'D',};
	_key = 0;
	/*
	If immediately called twice, return last value
	Example:
	if(pad.getKey) char c = pad.getKey();
	*/
	unsigned long new_ms = millis();
	if((new_ms - _ms) < _Threshold) return _key;
	// else _ms = new_ms;

	for(int i=0;i<4;i++){
		digitalWrite(_row[0], HIGH);
		digitalWrite(_row[1], HIGH);
		digitalWrite(_row[2], HIGH);
		digitalWrite(_row[3], HIGH);
		
		digitalWrite(_row[i], LOW);
		for(int j=0;j<4;j++){
			if(digitalRead(_col[j]) == 0){
				unsigned char index = (4*i) + j;
				_key = _keymap[index];
                _ms = millis();
			}
		}
	}
	return _key;
}

#endif
