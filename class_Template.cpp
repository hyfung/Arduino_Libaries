#include "Arduino.h"
#include "class_Template.h"

const byte SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0X80, 0X90};
const byte SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};

SevenSeg::SevenSeg(int DS, int CLK, int LATCH){
	pinMode(DS, OUTPUT);
	pinMode(CLK, OUTPUT);
	pinMode(LATCH, OUTPUT);
	_DS = DS;
	_CLK = CLK;
	_LATCH = LATCH;
}

void SevenSeg::writeInt(int Number){
  WriteNumberToSegment(0 , Number / 1000);
  WriteNumberToSegment(1 , (Number / 100) % 10);
  WriteNumberToSegment(2 , (Number / 10) % 10);
  WriteNumberToSegment(3 , Number % 10);
}

void SevenSeg::WriteNumberToSegment(byte Segment, byte Value){
	digitalWrite(_LATCH, LOW);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_MAP[Value]);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_SELECT[Segment] );
	digitalWrite(_LATCH, HIGH);
}
