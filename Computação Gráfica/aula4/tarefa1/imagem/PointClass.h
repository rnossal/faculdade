
class PointClass
{
	public:
		int X,Y;

		PointClass () { X = 0; Y = 0; };
		PointClass (int a, int b) 
		{ 
			X = a; Y = b; 
		};
		Set(int a, int b);
		
};

PointClass::Set(int a, int b) 
{ 
	X = a; Y = b; 
}




