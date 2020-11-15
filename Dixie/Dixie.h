#ifndef Dixie_h
#define Dixie_h
#include "Arduino.h"
#include "string.h"
class Dixie{
	public:
		Dixie(unsigned char x[]);
	private:
		unsigned char _seg[10] = {-255};
};

Dixie::Dixie(unsigned char x[]){
	unsigned char length = strlen(x);
	for(int i=0;i<length;i++){
		pinMode(x[i], OUTPUT);
	}
}
#endif
