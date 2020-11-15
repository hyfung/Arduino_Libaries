#ifndef Max7219_7seg_
#define Max7219_7seg_

#include "Arduino.h"

#define MAX7219_OFF (0x0)
#define MAX7219_ON  (0x1)
#define MAX7219_DECODE_REG      (0x09)
#define MAX7219_DIGIT_REG(pos)  ((pos) + 1)
#define MAX7219_INTENSITY_REG   (0x0A)
#define MAX7219_SCANLIMIT_REG   (0x0B)
#define MAX7219_SHUTDOWN_REG    (0X0C)
#define MAX7219_DISPLAYTEST_REG (0x0F)

class Max7219_7seg{
public:
    Max7219_7seg(uint8_t DIN, uint8_t CS, uint8_t CLK);
    void on();
    void off();
    void show_integer(uint32_t value, uint8_t mask=8);
    void test(uint8_t t);
    void BCD_Mode(uint8_t t);
private:
    void set_register(byte address, byte value);
    uint8_t _CS, _DIN, _CLK;

};

Max7219_7seg::Max7219_7seg(uint8_t DIN, uint8_t CS, uint8_t CLK){
    pinMode(DIN, OUTPUT);
    _DIN = DIN;
    pinMode(CS, OUTPUT);
    _CS = CS;
    pinMode(CLK, OUTPUT);
    _CLK = CLK;
}

void Max7219_7seg::on(){
    set_register(MAX7219_SHUTDOWN_REG, MAX7219_ON);
}

void Max7219_7seg::off(){
    set_register(MAX7219_SHUTDOWN_REG, MAX7219_OFF);
}

void Max7219_7seg::show_integer(uint32_t value, uint8_t mask=8){
    set_register(MAX7219_SCANLIMIT_REG, mask-1);
    set_register(0x1, value % 10);
    set_register(0x2, value % 100 / 10);
    set_register(0x3, value % 1000 / 100);
    set_register(0x4, value % 10000 / 1000);
    set_register(0x5, value % 100000 / 10000);
    set_register(0x6, value % 1000000 / 100000);
    set_register(0x7, value % 10000000 / 1000000);
    set_register(0x8, value % 100000000 / 10000000);
}

void Max7219_7seg::test(uint8_t t){
    if(t){
        set_register(MAX7219_DISPLAYTEST_REG, MAX7219_ON);
    }

    else{
        set_register(MAX7219_DISPLAYTEST_REG, MAX7219_OFF);
    }

}

void Max7219_7seg::BCD_Mode(uint8_t t){
    if(t){
        set_register(0x09, 0xFF);
    }
    else{
        set_register(0x09, 0x0);
    }
}

void Max7219_7seg::set_register(byte address, byte value){
  digitalWrite(_CS, LOW);
  shiftOut(_DIN, _CLK, MSBFIRST, address);
  shiftOut(_DIN, _CLK, MSBFIRST, value);
  digitalWrite(_CS, HIGH);
}

#endif
