#ifndef LY_S004_H
#define LY_S004_H

#include <Arduino.h>

class LY_S004 {
public:
    LY_S004(uint8_t r, uint8_t g, uint8_t b);
    void red();
    void green();
    void blue();
    void off();
    void mix(uint8_t r, uint8_t g, uint8_t b);

private:
    uint8_t _R, _G, _B;
}

LY_S004::LY_S004(uint8_t r, uint8_t g, uint8_t b){
    _R = r;
    _G = g;
    _B = b;

    pinMode(_R, OUTPUT);
    pinMode(_G, OUTPUT);
    pinMode(_B, OUTPUT);

    digitalWrite(_R, LOW);
    digitalWrite(_G, LOW);
    digitalWrite(_B, LOW);
}

void LY_S004::red(){
    digitalWrite(_R, HIGH);
    digitalWrite(_G, LOW);
    digitalWrite(_B, LOW);
}

void LY_S004::green(){
    digitalWrite(_R, LOW);
    digitalWrite(_G, HIGH);
    digitalWrite(_B, LOW);
}

void LY_S004::blue(){
    digitalWrite(_R, LOW);
    digitalWrite(_G, LOW);
    digitalWrite(_B, HIGH);
}

void LY_S004::off(){
    digitalWrite(_R, LOW);
    digitalWrite(_G, LOW);
    digitalWrite(_B, LOW);
}

void LY_S004::mix(uint8_t r, uint8_t g, uint8_t b){
    //TBD
}

#endif
