class RotaryEncoder{
	//LY-S0024
	public:
		RotaryEncoder(int a, int b, int key);
		void setZero();
		void set(int x);
		void event();
		int value();
		void attachToInterrupt();
	private:
		volatile int _counter = 0;
		char getState();
		char _a;
		char _b;
		char _key;
		char last_a;
		char last_b;
};

RotaryEncoder::RotaryEncoder(int a, int b, int key){
	pinMode(a, INPUT);
	pinMode(b, INPUT);
	pinMode(key, INPUT);
	_a = a;
	_b = b;
	_key = key;
}

void RotaryEncoder::event(){
	int n = digitalRead(_a);
  	if ( (last_a == LOW) && (n == HIGH)) {
    	if (digitalRead(_b) == LOW) {
      		_counter++;
    		} else {
      			_counter--;
    			}
  		}
  	last_a = n;
}

void RotaryEncoder::setZero(){
	_count = 0;
}

int RotaryEncoder::value(){
	return _counter;
}

void RotaryEncoder::set(int x){
	_counter = x;
}

RotaryEncoder::getState(){
	int a = digitalRead(_a);
	int b = digitalRead(_b) << 1;
	return a&b; //BA
}

/*
void RotaryEncoder::attachToInterrupt(){
	//Use PCINT to catch change in state
}
*/
