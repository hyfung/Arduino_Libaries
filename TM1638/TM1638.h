#ifndef TM1638_h
#define TM1638_h
#include "Arduino.h"

#define	DATA_COMMAND	0X40
#define	DISP_COMMAND	0x80
#define	ADDR_COMMAND	0XC0

unsigned char tab[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                           0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned char num[8];
unsigned char ASCII[256] = {0};

/*
Class Constructor
*/
class TM1638{
	public:
		TM1638(int _STB=0, int _CLK=1, int _DIO=2);
		unsigned char Read_key(void);
		void Write_DATA(unsigned char add,unsigned char DATA);
		void TM1638_Write(unsigned char	DATA);
		void Write_COM(unsigned char cmd);
		unsigned char TM1638_Read(void);
		unsigned char Read_key(void);
		void Write_allLED(unsigned char LED_flag);
		void Write_COM(unsigned char cmd);
		//------My own function
		void writeNumber(int x);
		write_String(String string);
	private:
		int STB, CLK, DIO;
		void init_ASCII();
};

/*
Custom function:
Expects: An eight digit number to be written to display
Returns: Nothing
*/
void TM1638::writeNumber(int x){
	int addr = 0;
	for(int i=0;i<8;i++){
		//int digit = 
		//Write_DATA(i*2, );
	}
}

/*
Class Constructor
Expects: Standby pin, Clock pin, Data Input pin
Returns: Instance of class
*/
TM1638::TM1638(int _STB, int _CLK, int _DIO){
	STB = _STB;
	CLK = _CLK;
	DIO = _DIO;
	pinMode(STB,OUTPUT);
	pinMode(CLK,OUTPUT);
	pinMode(DIO,OUTPUT);
	unsigned char i;
	Write_COM(0x8b);
	Write_COM(0x40);
    digitalWrite(STB,LOW);
	TM1638_Write(0xc0);
	for(i=0;i<16;i++) TM1638_Write(0x00);
    digitalWrite(STB,HIGH);
    for(i=0;i<8;i++) Write_DATA(i<<1,tab[0]);
    init_ASCII();
}

/*
Read
*/
unsigned char TM1638::TM1638_Read(void)
{
	unsigned char i;
	unsigned char temp=0;;	
        pinMode(DIO,INPUT);
	for(i=0;i<8;i++)
	{
  	    temp>>=1;
            digitalWrite(CLK,LOW);
  	    if(digitalRead(DIO)==HIGH)
  	      temp|=0x80;
            digitalWrite(CLK,HIGH);
               
	}
	return temp;
}


unsigned char TM1638::Read_key(void)
{
	unsigned char c[4],i,key_value=0;
        digitalWrite(STB,LOW);
	TM1638_Write(0x42);
	for(i=0;i<4;i++)		
  	{
            c[i]=TM1638_Read();
        }
        digitalWrite(STB,HIGH);
	for(i=0;i<4;i++)
	{
            key_value|=c[i]<<i;
        }	
        for(i=0;i<8;i++)
        {
            if((0x01<<i)==key_value)
            break;
        }
	return i;
}

/*
Write data to onboard red LEDs
Expects: An 8-bit LED flag data
Returns: Nothing
*/
void TM1638::Write_allLED(unsigned char LED_flag)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
	    if(LED_flag&(1<<i))
	      Write_DATA(2*i+1,1);
	    else
	      Write_DATA(2*i+1,0);
        }
}

/*
This function is used to write data to Seven Segment
Address = Position * 2
Expects: Address to write, Data to write
Returns: Nothing
*/
void TM1638::Write_DATA(unsigned char add,unsigned char DATA)
{
	Write_COM(0x44);
    digitalWrite(STB,LOW);
	TM1638_Write(0xc0|add);
	TM1638_Write(DATA);
    digitalWrite(STB,HIGH);
}

/*
This function writes command to TM1638
Expects: Command opcode
Returns: Nothing
*/
void TM1638::Write_COM(unsigned char cmd) //Send command
{
    digitalWrite(STB,LOW);
	TM1638_Write(cmd);
    digitalWrite(STB,HIGH);
}

/*

Expects:
Returns:
*/
void TM1638::TM1638_Write(unsigned char	DATA)
{
	unsigned char i;
        pinMode(DIO,OUTPUT);
	for(i=0;i<8;i++)
	{
            digitalWrite(CLK,LOW);
	    if(DATA&0X01)
               digitalWrite(DIO,HIGH);
	    else
               digitalWrite(DIO,LOW);
	    DATA>>=1;
            digitalWrite(CLK,HIGH);
	}
}

void TM1638::write_String(String string) {
  for (int i = 0; i < string.length(); i++) {
    Write_DATA(i << 1, ASCII[ string[i] ] );
  }
}

/*
This function creates an ASCII charmap
Expects: Nothing
Returns: Nothing
*/
void TM1638::init_ASCII() {
  ASCII['A'] = 0x77;
  ASCII['B'] = 0x7D;
  ASCII['C'] = 0x39;
  ASCII['E'] = 0x79;
  ASCII['F'] = 0x71;
  ASCII['G'] = 0x3d;
  ASCII['H'] = 0x76;
  ASCII['I'] = 0x30;
  ASCII['L'] = 0x38;
  ASCII['N'] = 0x37;
  ASCII['O'] = 0x3f;
  ASCII['P'] = 0x73;
  ASCII['S'] = 0x6d;
  ASCII['T'] = 0x31;
  ASCII['U'] = 0x3e;
  ASCII['a'] = 0x5f;
  ASCII['c'] = 0x58;
  ASCII['d'] = 0x5e;
  ASCII['e'] = 0x7a;
  ASCII['n'] = 0x54;
  ASCII['o'] = 0x5c;
  ASCII['t'] = 0x78;
  ASCII['u'] = 0x1c;
}
#endif
