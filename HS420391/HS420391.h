#ifndef HS422391_h
#define HS422391_h
#include "Arduino.h"

/*
Library used to drive 4-digit seven segment
Common Anode

HS420391 sevenSeg;
*/

class HS420391{
	public:
		void setDigit(int x[]);
		void setSegment(int x[]);
		void writeNumber(int Number);
	private:
		unsigned char _Segment[7];
		unsigned char _Digit[4];
		void WriteNumberToSegment(int x, int number);
};

void HS420391::writeNumber(int Number){
	WriteNumberToSegment(0 , Number / 1000);
	WriteNumberToSegment(1 , (Number / 100) % 10);
	WriteNumberToSegment(2 , (Number / 10) % 10);
	WriteNumberToSegment(3 , Number % 10);
}

void HS420391::WriteNumberToSegment(int x, int number){
	//Pull selected LOW
	digitalWrite(_Digit[x], LOW);
}

/*
Set 4 pin of Anode (Digit places)
sevenSeg.setDigit(1,2,3,4)
*/
void HS420391::setDigit(int x[4]){
	for(int i=0;i<4;i++){
		pinMode(x[i], OUTPUT);
		digitalWrite(x[i], HIGH);
	}
}

/*
Set 7 pin of Cathode (Segments)
sevenSeg.setSegment(1,2,3,4,5,6,7)
*/
void HS420391::setSegment(int x[7]){
	for(int i=0;i<8;i++){
		pinMode(x[i], OUTPUT);
		digitalWrite(x[i], LOW);
	}
}

#endif
