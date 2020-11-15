#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H
#include <Arduino.h>

/*
Class Description:

*/
class ShiftRegister{
public:
    ShiftRegister(unsigned char data, unsigned char clock, unsigned char latch, unsigned char mode);
    void write(unsigned char data);
private:
    unsigned char _data, _clk, _latch, _mode;
};

/*
Class constructor
Expects:
Returns: Nothing
*/
ShiftRegister::ShiftRegister(unsigned char data, unsigned char clock, unsigned char latch, unsigned char mode){
    _data = data;
    pinMode(_data, OUTPUT);
    _clk = clock;
    pinMode(_clk, OUTPUT);
    _latch = latch;
    pinMode(_latch, OUTPUT);
    _mode = mode;
}

/*
Expects:
Returns: 
*/
void ShiftRegister::write(unsigned char data){
    digitalWrite(_latch, LOW);
    shiftOut(_data, _clk, _mode, data)
    digitalWrite(_latch, HIGH);
}

#endif