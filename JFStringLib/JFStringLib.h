#ifndef JFString_h
#define JFString_h
#include "Arduino.h"

#define BIT0 0x1
#define BIT1 0x2
#define BIT2 0x4
#define BIT3 0x8
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80
#define isDigit(x) ((x>=48) && (x<=57))
int pow(int x, int y){
	int ret = x;
	if(y == 0) return 1;
	else for(int i = 0;i<y;i++){
		ret *= x;
	}
	return x;
}

String Pad(int input, int places){
	String output = "";
	if(input < 0) return output;
	String foo = (String)input;
	for(int i=0;i<places - foo.length() ;i++){
		output+= "0";
	}
	output += (String)foo;
	return output;
}

int HexToInt(String input){
	int Hex = 0;
	int Base = 0;
	for(int i = 0; i<strlen(input); i++){
		int radix = strlen(input) - i;
		if( isDigit(input[i]) ){
			Hex += (input[i] - 48) * pow(16, radix);
		}
		else{
		switch(input[i]){
			case 'A': //A:65 a:97
				Base = 10;
				break;
			case 'B':
				Base = 11;
				break;
			case 'C':
				base = 12;
				break;
			case 'D':
				Base = 13;
				break;
			case 'E':
				Base = 14;
				break;
			case 'F':
				Base = 15;
				break;
		}
		Hex += pow(Base, radix);	
		} 
	}
	return Hex;
}

#endif
