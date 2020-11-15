#ifndef L293D_h
#define L293D_h
#include "Arduino.h"

class L293D{
	public:
		L293D(int en, int a, int b);
		void forward();
		unsigned char forward(int pwm);
		void backward();
		unsigned char backward(int pwm);
		void stop();
	private:
		unsigned char _en, _a, _b;
};

#endif
