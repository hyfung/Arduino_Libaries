#ifndef LevelMeter_h
#define LevelMeter_h
#include "Arduino.h"

class LevelMeter{
	public:
		LevelMeter(int x[10]);
		void set(int x);
	private:
		int mapping[10];
};

LevelMeter::LevelMeter(int x[10]){
	for(int i = 0;i<10;i++){
		mapping[i] = x[i];
		pinMode(x[i], OUTPUT);
		digitalWrite(x[i]), LOW;
	}
}

void LevelMeter::set(int x){
	for(int i=0;i<10;i++){
		if(i<x) digitalWrite(mapping[i], HIGH);
		else digitalWrite(mapping[i], LOW);
	}
}

#endif
