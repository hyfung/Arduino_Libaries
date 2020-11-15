#ifndef S10532_h
#define S10532_h
#include "Arduino.h"

class S10532{
	public:
		void col(int a, int b, int c, int d); //7,8,9,10
		void row(int a, int b, int c, int d); //3,4,5,6
		uint8_t getKey();
		uint8_t lastKey();
	private:
		uint8_t _lastKey;
		uint8_t _col[4];
		uint8_t _row[4];
};

uint8_t S10532::lastKey(){
	return _lastKey;
}

void S10532::col(int a, int b, int c, int d){
	_col[0] = a;
	_col[1] = b;
	_col[2] = c;
	_col[3] = d;
	for(int i=0;i<4;i++) pinMode(_col[0], INPUT_PULLUP);
}

void S10532::row(int a, int b, int c, int d){
	_row[0] = a;
	_row[1] = b;
	_row[2] = c;
	_row[3] = d;
	for(int i=0;i<4;i++) pinMode(_row[i], OUTPUT);
}

uint8_t S10532::getKey(){
	int i = 0;
	int j = 0;
	uint8_t key = 0;
	for(j=0;j<4;j++){
		//2 to 5 select = LOW
		digitalWrite(_row[0], HIGH);
		digitalWrite(_row[1], HIGH);
		digitalWrite(_row[2], HIGH);
		digitalWrite(_row[3], HIGH);
		
		digitalWrite(_row[j], LOW);
		
		//Others HIGH
		//ROW
		for(i=0;i<4;i++){
			//COL
			//7-10 input pullup
			//check 7-10 whether pulled low
			if( digitalRead(_col[i]) == LOW){
				key = 4*j + i + 1;	
				delay(40);
			}
			
		}	
	}
	_lastKey = key;
	return key;
}

#endif
