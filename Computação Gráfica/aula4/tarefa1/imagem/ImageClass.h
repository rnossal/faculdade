// *****************************************************************************************
//  ImageClass.cpp
//
//
// *****************************************************************************************

class ImageClass
{
	// Constructors
	public:
	ImageClass(void);
	ImageClass(int sizeX, int sizeY);


	int Load(char *);
	void Display(void);
	void Delete(void);
	void DrawPixel(GLint x, GLint y, unsigned char r, unsigned char g, unsigned char b);
	void DrawLineH(int y, int x1, int x2, unsigned char r, unsigned char g, unsigned char b);
	void DrawLineV(int x, int y1, int y2,unsigned char r, unsigned char g, unsigned char b );
	void ReadPixel(GLint x, GLint y, unsigned char &r, unsigned char &g, unsigned char &b);
	int GetPointIntensity(int x, int y);
	int SizeX() { return Image->sizeX; };
	int SizeY() { return Image->sizeY; };
	void CopyTo(ImageClass *i);
	void Clear();

	void SetPos(int X, int Y);

	private:
	// Create a place to store the texture
	AUX_RGBImageRec *Image;
	int PosX, PosY;
	
};

