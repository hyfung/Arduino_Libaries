/*
Seven Segment Library
*/

#ifndef SevenSeg_h
#define SevenSeg_h

#include "Arduino.h"

class SevenSeg{
	public:
	SevenSeg(int DS,int CLK,int LATCH);
	void writeInt(int numbers);
	private:
	void WriteNumberToSegment(byte Segment, byte Value);
	int _DS, _CLK, _LATCH;
};

#endif
