#ifndef PISO
#define PISO

#include <Arduino.h>

class PISO{
public:
    PISO(unsigned char data, unsigned char clk, unsigned char latch);
    uint8_t  read();

private:
    unsigned char _data;
    unsigned char _clk;
    unsigned char _latch;
}

PISO::PISO(unsigned char data, unsigned char clk, unsigned char latch){
    _data = data;
    pinMode(_data, INPUT);

    _clk = clk;
    pinMode(_clk, OUTPUT);
    digitalWrite(_clk, LOW);
    
    _latch = latch;
    pinMode(_latch, OUTPUT);
    digitalWrite(_latch, HIGH);
}

uint8_t PISO::read(){
    //MSB First
    //HGFEDCBA
    uint8_t input = 0x00;

    //Latch input
    digitalWrite(_latch, LOW);
    delay(1);
    digitalWrite(_latch, HIGH);

    for(int i=7;i!=0;i--){
        
        if(digitalRead(_data) == HIGH) {
            input |= (1 << i)
        };

        digitalWrite(_clk, HIGH);
        delay(1);
        digitalWrite(_clk, LOW);

    }
    return input;
}

#endif