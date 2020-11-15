#ifndef SEVENSEG_H
#define SEVENSEG_H
#include "Arduino.h"
#include "SevenSeg.h"

/*
Predefined value for Multi-function slide
*/
#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

//Common Anode MSB:dp LSB:A
//Character Map
const byte SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0X80, 0X90};
//Selector Map
const byte SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};

/*
Class constructor with default values
*/
SevenSeg::SevenSeg(int DS = 8, int CLK = 7, int LATCH = 4){
	pinMode(DS, OUTPUT);
	pinMode(CLK, OUTPUT);
	pinMode(LATCH, OUTPUT);
	_DS = DS;
	_CLK = CLK;
	_LATCH = LATCH;
}

SevenSeg::SevenSeg(){
	int DS = 8;
	int CLK = 7;
	int LATCH = 4;
	pinMode(DS, OUTPUT);
	pinMode(CLK, OUTPUT);
	pinMode(LATCH, OUTPUT);
	_DS = DS;
	_CLK = CLK;
	_LATCH = LATCH;
}

/*
Write a 4-digit number on seven segment
*/
void SevenSeg::writeNumber(int Number){
  WriteNumberToSegment(0 , Number / 1000);
  WriteNumberToSegment(1 , (Number / 100) % 10);
  WriteNumberToSegment(2 , (Number / 10) % 10);
  WriteNumberToSegment(3 , Number % 10);
  digitalWrite(_LATCH, LOW);
  shiftOut(_DS, _CLK, MSBFIRST, 0xff);
  shiftOut(_DS, _CLK, MSBFIRST, 0xff);
  digitalWrite(_LATCH, HIGH);
}

/*
Write a single digit to seven segment
First we shiftout a digit
Then we shiftout a segment select
*/
void SevenSeg::WriteNumberToSegment(byte Segment, byte Value){
	digitalWrite(_LATCH, LOW);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_MAP[Value]);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_SELECT[Segment] );
	digitalWrite(_LATCH, HIGH);
}

/*
Shows the word ADC on seven segment
*/
void SevenSeg::showADC(){
	digitalWrite(_LATCH, LOW);
	shiftOut(_DS, _CLK, MSBFIRST, 0b10001000);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_SELECT[0] );
	digitalWrite(_LATCH, HIGH);
	
	digitalWrite(_LATCH, LOW);
	shiftOut(_DS, _CLK, MSBFIRST, 0b10100001);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_SELECT[1] );
	digitalWrite(_LATCH, HIGH);
	
	digitalWrite(_LATCH, LOW);
	shiftOut(_DS, _CLK, MSBFIRST, 0b10100111);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_SELECT[2] );
	digitalWrite(_LATCH, HIGH);
	
	digitalWrite(_LATCH, LOW);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_MAP[5]);
	shiftOut(_DS, _CLK, MSBFIRST, SEGMENT_SELECT[3] );
	digitalWrite(_LATCH, HIGH);
}
#endif