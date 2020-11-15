#ifndef IRARRAY_H
#define IRARRAY_H
#include "Arduino.h"

/*

*/
class IRArray{
public:
    IRArray(unsigned char w, unsigned char x, unsigned char y, unsigned char z);
    unsigned char state(unsigned char index);
    unsigned char getStates();
    unsigned char lastStates();
    void updateLastStates();
    unsigned char isBlocked(unsigned char index);
    unsigned char stateChanged();

private:
    unsigned char _sensor[4];
    unsigned char _lastStates = 0;
};

IRArray::IRArray(unsigned char w, unsigned char x, unsigned char y, unsigned char z){
    _sensor[0] = w;
    _sensor[1] = x;
    _sensor[2] = y;
    _sensor[3] = z;
    for(int i=0;i<4;i++){        
        pinMode(_sensor[i], INPUT_PULLUP);
    }
}

/*
A function to check whether any sensor has flipped
Expects:
Returns: 0 if states aren't changed and 1 if changed
*/
unsigned char IRArray::stateChanged(){
    unsigned char lastStates = _lastStates;
    unsigned char currentStates = this->getStates();
    return lastStates ^ currentStates;
}

/*

*/
unsigned char IRArray::getStates(){
    this->updateLastStates();
    return _lastStates;
}

/*
Expects: Nothing
Returns: An 8-bit value of last state
*/
unsigned char IRArray::lastStates(){
    return _lastStates;
}

/*
Poll all channels and bitbang an uint8_t to store _lastStates
Expects: Nothing
Returns: Nothing
*/
void IRArray::updateLastStates(){
    _lastStates = 0;
    for(int i=0;i<4;i++){
        _lastStates |= digitalRead(_sensor[i]) << i;
    }
}

/*
Poll the chosen sensor to see if its blocked
Expects: An index
Returns: 0 if not blocked, 1 if blocked
*/
unsigned char IRArray::isBlocked(unsigned char index){
    return this->state(index);
}

/*
Poll the chosen sensor to see if its blocked
Expects: An index
Returns: 0 if not blocked, 1 if blocked
*/
unsigned char IRArray::state(unsigned char index){
    return digitalRead(_sensor[index]);
}

#endif