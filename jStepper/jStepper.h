/*
Stepper Motor Library
Customized Mode
*/

#ifndef jStepper_h
#define jStepper_h

#include "Arduino.h"

class jStepper{
	public:
		// a->b->c->d IS CLOCKWISE
		jStepper(int a, int b, int c, int d,float stepAngle = 0);
		// 360/(Step per Evolution), stated by spec
		// 360 / 200 = 1.8
		//e.g. 200 Step = 1.8 Degree per rev
		//
		void setStepAngle(float stepAngle);
		//1-Rev = N Step
		void ccw(int rev);
		void cw(int rev);
		void ccw_step(int step);
		void cw_step(int step);
		void cw_step_2p(int step);
		void ccw_step_2p(int step);
		void stop();
		void setZero();
	private:
		float _stepAngle = 0; //Step angle
		int _stepPerRev = 0;
		unsigned char _arr[4] = {0}; //Control Pin
		float _currentPos = 0; //Clockwise is Positive
		/*
		unsigned char _a;
		unsigned char _b;
		unsigned char _c;
		unsigned char _d;
		*/
};

void jStepper::stop(){
	for(int i=0;i<4;i++){
		digitalWrite(_arr[i], LOW);
	}
}

void jStepper::setZero(){
	_currentPos = 0;
}

jStepper::jStepper(){
	_arr[0] = a;
	_arr[1] = b;
	_arr[2] = c;
	_arr[3] = d;
	_stepAngle = stepAngle;
	_stepPerRev = 360 / _stepAngle;
}

void jStepper::setStepAngle(float stepAngle){
	_stepAngle = stepAngle;
	_stepPerRev = 360 / _stepAngle;
}

void jStepper::ccw(int rev){
	jStepper::ccw_step(rev * _stepPerRev);
}
void jStepper::cw(int rev){
	jStepper::cw_step(rev * _stepPerRev);
}

void jStepper::ccw_step(int step){
	//Single-Phase
	for(int j=0; j < step ; j++){
		for(int i=3 ; i > -1 ; i--){
			digitalWrite(_arr[i], HIGH);
			delay(5);
			digitalWrite(_arr[i], LOW);
		}
		_currentPos -= _stepAngle;
	}	
}

void jStepper::cw_step(int step){
	//Single-Phase
	for(int j=0; j < step ; j++){
		for(int i=0 ; i < 4 ; i++){
			digitalWrite(_arr[i], HIGH);
			delay(5);
			digitalWrite(_arr[i], LOW);
		}	
		_currentPos += _stepAngle;
	}
}

void jStepper::cw_step_2p(int step){
	for(int j=0;j < step;j++){
					//1100
					digitalWrite(_arr[0], HIGH);
					digitalWrite(_arr[1], HIGH);
					digitalWrite(_arr[2], LOW);
					digitalWrite(_arr[3], LOW);
					delay(5);
					//0110
					digitalWrite(_arr[0], LOW);
					digitalWrite(_arr[2], HIGH);
					delay(5);
					//0011
					digitalWrite(_arr[1], LOW);
					digitalWrite(_arr[3], HIGH);
					delay(5);
					//1001
					digitalWrite(_arr[0], HIGH);
					digitalWrite(_arr[2], LOW);
					delay(5);
		}
	for(int i=0;i<4;i++){
		digitalWrite(_arr[i], LOW);
		}
	}
}

#endif

