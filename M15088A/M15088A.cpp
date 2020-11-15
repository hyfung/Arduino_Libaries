#include "Arduino.h"
#include "M15088A.h"
class M15088A{
	public:
		void setCol(int col[8]);
		void setRow(int row[8]);
		void display(unsigned char dis[8]);
	private:
		void zero();
		unsigned char _row[8];
		unsigned char _col[8];
};

M15088A::setCol(int col[8]){
	for(int i=0;i<8;i++){
		_col[i] = col[i];
		pinMode(_col[i]) = 0;
		digitalWrite(_col[i], HIGH);
	}
}

M15088A::setRow(int row[8]){
	for(int i=0;i<8;i++){
		_row[i] = row[i];
		pinMode(_row[i]) = 0;
		digitalWrite(_row[i], LOW);
	}
}

M15088A::zero(){
	for(int i=0;i<8;i++){
		digitalWrite(_row[i], LOW);
		digitalWrite(_col[i], HIGH);
	}
}

M15088A::display(unsigned char dis[8]){
	for(int i=0;i<8;i++){
		zero();
		digitalWrite(_row[i], HIGH);
		for(int j=0;j<7;j++){
			//
			digitalWrite(_col[j], (dis[j] >> j) & 0x1);
		}
	}
}
