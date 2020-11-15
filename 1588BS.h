#ifndef 1588BS_h
#define 1588BS_h
#include "Arduino.h"
//Common Anode
class HS1588BS{
	public:
		void col(int x[]); //Cathode
		void row(int x[]); //Anode
		void display(byte x[]);
};

void HS1588BS::col(int x[]){
	
}

void HS1588BS::row(int x[]){
	
}

void HS1588BS::display(byte x[8]){
	for(int i=0;i<8;i++){
		for(int j=0;i<8;j++){
			digitalWrite(_row[j], LOW);
			digitalWrite(_col[j], HIGH);
		}
		digitalWrite(_row[i], HIGH);
		byte vec = x[i];
		for(int j = 0;j<8;j++){
			vec = (vec & ( j << 1)) ? 1 : 0;
			digitalWrite(_col[j], vec);
		}
	}
}

#endif
