#ifndef SR04_h
#define SR04_h
#include "Arduino.h"

/*
ALL CALCULATION BASED ON ROUND TRIP
Default timeout is 1 second = 100,000uS
1 second = 340.3 / 2 = ~170cm (round trip)
~588.2uS cm^-1 Round-trip
Timeout Reference Chart:
170cm = 100,000Us
17cm = 10,000Us
*/

/*
Class Definition
*/
class SR04{
	public:
		SR04(int echo,int trig,int timeout);
		unsigned long getDistance(int timeout);
		unsigned long getTime(int timeout)
	private:
		int _echo, _trig, _timeout;
};

/*
Constructor
SR04 myRadar(ECHO_PIN, TRIGGER_PIN);
*/
SR04::SR04(int echo, int trig, int timeout = 0){
	pinMode(echo, INPUT);
	pinMode(trig, OUTPUT);
	_echo = echo;
	_trig = trig;
	_timeout = timeout; // / 340.3 * 2 * 1000000; //Max time allowed, in microsecond
}

/*
Get the distance of a radar
Expects:
Returns: Distance sensed in cm
*/
unsigned long SR04::getDistance(int timeout = 0){
	if(timeout) _timeout = timeout;
	unsigned long distance;
	unsigned long duration;
	digitalWrite(_echo, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(_trig, HIGH);
	delayMicroseconds(5);
	digitalWrite(_trig, LOW);
	duration = pulseIn(_echo, HIGH, _timeout); // Reads the echoPin, returns the sound wave travel time in microseconds	
	distance = duration * 0.034 / 2 ; //In cm
	return distance;
}

/*
Expects:
Returns: Echo time in microseconds
*/
unsigned long SR04::getTime(int timeout = 0){
	int distance;
	unsigned long duration;
	digitalWrite(_echo, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(_trig, HIGH);
	delayMicroseconds(5);
	digitalWrite(_trig, LOW);
	duration = pulseIn(_echo, HIGH, timeout);
	return duration; //In microseconds
}

#endif
