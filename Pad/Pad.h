#ifndef Pad_h
#define Pad_h
#include "Arduino.h"
/*
this library only accepts positive int as argument
*/
String pad(int input, int places){
	String output = "";
	if(input < 0) return output;
	String foo = (String)input;
	for(int i=0;i<places - foo.length() ;i++){
		output+= "0";
	}
	output += (String)foo;
	return output;
}
#endif
