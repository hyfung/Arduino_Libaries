/*
This is a Tone Generation Program for ATTiny85 (Only)
Pin 0: OC0A
Pin 1: OC0B/OC1A
Pin 3: OC
Pin 4: OC1B
*/

#define MasterClock 8000000
#define PrescalerToBit(i) i+5
int AvailablePrescaler[] = {1,2,4,8,16,32,64,128,256,512,1024}; //Timer1

//Using OC1B
void Tiny85_Tone(int Frequency){
	int DesiredPrescaler = 1;
	TCCR1 = 0;
//-------Prescaler Determination---------
	for(int i=0;i<sizeof(AvailablePrescaler) / sizeof(int);i++){
		if( (Frequency * AvailablePrescaler[i] * 2 / MasterClock) < 256 ){
			DesiredPrescaler = AvailablePrescaler[i];
//-------Update Prescaler Register---------
			TCCR1 = PrescalerToBit(i);
			break;
		}
	}
//---------Config TCCR1
	TCCR1 |= CTC1 << 1; //CTC Mode
	GTTCR = 0;
	GTTCR |= COM1B0 << 1; //Toggle OC1B on Match
//--------Compare Register
	

}
