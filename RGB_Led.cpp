typedef uint8_t unsigned byte;
typedef int8_t byte;

class RGB{
	public:
		RGB_LED(int r, int g, int b);
		set(int r, int g, int b);
	private:
		char _r;
		char _g;
		char _b;
};

RGB::RGB(int r, int g, int b){
	pinMode(r, 1);
	pinMode(g, 1);
	pinMode(b, 1);
	
	
}

RGB::set(int r, int g, int b){
	analogWrite(_r, r);
	analogWrite(_b, b);
	analogWrite(_g, g);
}
