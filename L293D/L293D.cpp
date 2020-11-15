#include "Arduino.h"
#include "L293D.h"

L293D::L293D(int en, int a, int b){
	pinMode(en, 1);
	pinMode(a, 1);
	pinMode(b,1 );
	_en = en;
	_a = a;
	_b = b;
}

void L293D::forward(){
	digitalWrite(_en, 1);
	digitalWrite(_a, 1);
	digitalWrite(_b, 0);
}

unsigned char L293D::forward(int pwm){
	analogWrite(_en, pwm);
	digitalWrite(_a, 1);
	digitalWrite(_b, 0);
	return(pwm);
}

void L293D::backward(){
	digitalWrite(_en, 1);
	digitalWrite(_a, 0);
	digitalWrite(_b, 1);
}

unsigned char L293D::backward(int pwm){
	analogWrite(_en, pwm);
	digitalWrite(_a, 0);
	digitalWrite(_b, 0);
	return(pwm);
}

void L293D::stop(){
	digitalWrite(_en, 1);
	digitalWrite(_a, 0);
	digitalWrite(_b, 1);
}
