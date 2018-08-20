
#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
#include <windows.h>
#endif

#include <GL\gl.h>
#include <GL\glaux.h>
#include "glut.h"

#include "ImageClass.h"



// **********************************************************************
//
//	Constructor
// **********************************************************************
ImageClass::ImageClass()
{
		// Set the pointer to NULL
	Image = NULL;
	PosX = PosY = 0;
}


// **********************************************************************
//
//	Constructor
// **********************************************************************
ImageClass::ImageClass(int sizeX, int sizeY)
{
	unsigned int tam;

	// Aloca área para o apontador
	Image = new(AUX_RGBImageRec);
	Image->sizeX = sizeX;
	Image->sizeY = sizeY;
	
	tam = sizeof(unsigned char) * sizeX * sizeY *3;
	Image->data = (unsigned char *) malloc (tam);
	memset(Image->data,255,tam);

	PosX = PosY = 0;

}

// **********************************************************************
//
//
// **********************************************************************
void ImageClass::SetPos(int X, int Y)
{
	PosX = X;
	PosY = Y;
}

// **********************************************************************
//
//
// **********************************************************************
int ImageClass::Load(char * nome)
{

	if (!Image)
	{
	// Load the bitmap and assign our pointer to it
	Image = auxDIBImageLoad(nome);
	return 1;
	}
	
	printf ("ImageClass:Imagem inexistente !\n"); 
	return 0;
}

// **********************************************************************
//
//
// **********************************************************************
void ImageClass::Display()
{
	glPixelZoom(1,1);
	glRasterPos2i(PosX, PosY);
	glDrawPixels(Image->sizeX, Image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, Image->data);
}


// **********************************************************************
//
//
// **********************************************************************
void ImageClass::Delete()
{
	// Cleanup
	if (Image)
	{
		if (Image->data)
			free(Image->data);

		free(Image);
	}

}
// **********************************************************************
//
//
// **********************************************************************
void ImageClass::DrawPixel(GLint x, GLint y, unsigned char r, unsigned char g, unsigned char b)
{
	GLint addr;

	addr = y * (Image->sizeX)*3 + x * 3;
	Image->data[addr++] = r;
	Image->data[addr++] = g;
	Image->data[addr] = b;	
}
// **********************************************************************
//
//
//
// **********************************************************************
void ImageClass::DrawLineH(int y, int x1, int x2,unsigned char r, unsigned char g, unsigned char b )
{
	int x;
	for (x = x1; x<=x2; x++)
	{
		DrawPixel(x,y,r,g,b);	
	}
}
// **********************************************************************
//
//
//
// **********************************************************************
void ImageClass::DrawLineV(int x, int y1, int y2,unsigned char r, unsigned char g, unsigned char b )
{
	int y;
	for (y = y1; y<=y2; y++)
	{
		DrawPixel(x,y,r,g,b);	
	}
}

// **********************************************************************
//
//
// **********************************************************************
void ImageClass::ReadPixel(GLint x, GLint y, unsigned char &r, unsigned char &g, unsigned char &b)
{
	GLint addr;

	addr = y * (Image->sizeX)*3 + x * 3;
	r = Image->data[addr++];
	g = Image->data[addr++];
	b = Image->data[addr];
}


// **********************************************************************
//
//
//
// **********************************************************************
int ImageClass::GetPointIntensity(int x, int y)
{
	unsigned char r,g,b;
	int i;

	ReadPixel(x,y,r,g,b);
	i = (int) ( 0.3 * r + 0.59 * g + 0.11 * b );
	return i;
}

// **********************************************************************
//
//
//
// **********************************************************************
void ImageClass::CopyTo(ImageClass *i)
{

	unsigned int tam;

    tam = sizeof(unsigned char) * Image->sizeX * Image->sizeY *3;
	memcpy(i->Image->data, Image->data,tam);

}

// **********************************************************************
//
//
//
// **********************************************************************
void ImageClass::Clear()
{
	unsigned int tam;
	tam = sizeof(unsigned char) * SizeX() * SizeY() *3;
	memset(Image->data,255,tam);

}
