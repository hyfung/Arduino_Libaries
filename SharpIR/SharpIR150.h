#ifndef SharpIR150_h
#define SharpIR150_h
#include "Arduino.h"

/*
Sharp 150cm range detector library

*/


/*
Class constructor
Usage: SharpIR150 mySensor(ADC_PIN);
*/
class SharpIR150{
	public:
		SharpIR150(unsigned char PIN);
		float getDist();
	private:
		unsigned char _PIN;
};

SharpIR150::SharpIR150(unsigned char PIN){
	_PIN = PIN;
	pinMode(PIN, INPUT);
}

/*
Read analog input, returns a distance in cm
Expects: Nothing
Returns: Distance in cm
*/
float SharpIR::getDist(){
	const ratio = 5/1024;
	//Map ADC value to distance
	//Assume at least 15cm
	int adc;
	int dist;
	adc = analogRead(_PIN);
	return ADCtoDist(adc); 
}

/*
Function to convert 10-bit ADC value to distance
Expects: ADC value from Sharp Sensor
Returns: Distance in cm
*/
float ADCtoDist(int x){
	int adc = x;
	//Assume max distance
	if(adc < 0.4/5*1024){
		return 150;
	}
	//Below 2V
	if(adc < 2/5*1024){
		return 150 - (adc-81.92)/327.68 * 120;
	}
	//Below 2.55V
	if(adc < 2.55/5*1024){
		return 30 - (adc-409.6)/112.64 *10;
	}
	//Below 2.75V
	if(adc < 2.755/5*1024){
		return 15 - (adc-522.24)/40.96*5;
	}
}
#endif
