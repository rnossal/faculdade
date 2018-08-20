// **********************************************************************
//	
//
// Programa de testes para manipulação de Imagens
//
//
//		Este programa deve ser compilado junto com a classe "ImageClass", 
//		que está implementada no arquivo "ImageClass.cpp"	
//
//		- para compilar no Visual C ou Visual Studio acrescente as seguintes
//        bibliotecas:
//					 opengl32.lib glu32.lib glaux.lib glut32.lib 
//
//		- para compilar no DEVCPP (ou no g++) acrescente as seguintes
//        bibliotecas:
//		      -lopengl32 -lglut32 -lglu32 -lglaux
//
//		- para alterar a imagem que é carregada pelo programa, olhe a 
//		  rotina 'init' e altere a linha:
//							r = Image->Load("B.BMP");
//
//	Programa Desenvolvido por Marcio Serolli Pinho
// **********************************************************************


#include <stdio.h>
#include <math.h>

#include <windows.h>

#include <GL\gl.h>
#include <GL\glaux.h>

#include "glut.h"

#include "ImageClass.h"


ImageClass *Image, *NovaImagem;


#define LIMIAR 10


// **********************************************************************
//  void ConvertBlackAndWhite()
//
//
// **********************************************************************
void ConvertBlackAndWhite()
{
    // Tarefa 1:
    //		Mude o valor do LIMIAR para números pequenos como 5 ou 10
    //      Experimente executar usando as imagens b.bmp e eagle.bmp.

    // Tarefa 2:
    //		Mude o valor do LIMIAR para um número que represente a média
    //      entre os valores de densidade máximo e mínimo encontrados
    //      Experimente executar usando as imagens b.bmp e eagle.bmp.

    int x, y;

    for (x = 0; x < Image->SizeX(); x++)
    {
        for (y = 0; y < Image->SizeY(); y++)
        {
            if (Image->GetPointIntensity(x, y) < LIMIAR)
            {
                NovaImagem->DrawPixel(x, y, 0, 0, 0);
            }
        }
    }

}


// **********************************************************************
// void ConvertToGrayScale()
//   
//
// **********************************************************************
void ConvertToGrayScale()
{
    // Tarefa 3:
    //		Gerar uma imagem em tons de cinza 
    //		Use os métodos 
    //			'ReadPixel' e 'DrawPixel' da classe 'ImageClass'
    //      Experimente executar usando as imagens b.bmp e eagle.bmp.	

       //Image->ReadPixel(GLint x, GLint y, unsigned char &r, unsigned char &g, unsigned char &b)
       // Obtém os valores R,G,B de um ponto X,Y da image

       //Image->DrawPixel(GLint x, GLint y, unsigned char r, unsigned char g, unsigned char b)
       // Exibe na coordenada X,Y um ponto com a cor R,G,B na image 

    int x, y, i;
    for (x = 0; x < Image->SizeX(); x++)
    {
        for (y = 0; y < Image->SizeY(); y++)
        {
            i = Image->GetPointIntensity(x, y);
            NovaImagem->DrawPixel(x, y, i, i, i);
        }
    }
}


// **********************************************************************
// void ConvertToHalftone()
//   
//
// **********************************************************************
void ConvertToHalftone()
{
    // Tarefa 4:
    //		Gerar uma imagem em duas cores usando o método de Halftone 
    //	com uma matriz 2x2.
    //
    //		Use o método 
    //			'GetPointIntensity' da classe 'ImageClass'
    //
    //		Voce irá precisar ampliar o tamanho da NovaImagem. Para tanto,
    //	olhe a rotina 'init' abaixo.

    //      Experimente executar usando as imagens b.bmp e eagle.bmp.

    //		Para alterar o tamanho da janela olhe a função 'main()'

    int x, y, i;
    int matrixX = 0;
    int matrixY = 0;

    for (x = 0; x < Image->SizeX(); x++)
    {
        matrixY = 0;

        for (y = 0; y < Image->SizeY(); y++)
        {
            i = Image->GetPointIntensity(x, y);

            if (i >= 0 && i <= 49) {
                NovaImagem->DrawPixel(matrixX, matrixY, 0, 0, 0);
                NovaImagem->DrawPixel(matrixX + 1, matrixY, 0, 0, 0);
                NovaImagem->DrawPixel(matrixX, matrixY + 1, 0, 0, 0);
                NovaImagem->DrawPixel(matrixX + 1, matrixY + 1, 0, 0, 0);
            }
            else if (i >= 50 && i <= 101) {
                NovaImagem->DrawPixel(matrixX, matrixY, i, i, i);
                NovaImagem->DrawPixel(matrixX + 1, matrixY, 0, 0, 0);
                NovaImagem->DrawPixel(matrixX, matrixY + 1, 0, 0, 0);
                NovaImagem->DrawPixel(matrixX + 1, matrixY + 1, 0, 0, 0);
            }
            else if (i >= 102 && i <= 153) {
                NovaImagem->DrawPixel(matrixX, matrixY, i, i, i);
                NovaImagem->DrawPixel(matrixX + 1, matrixY, 0, 0, 0);
                NovaImagem->DrawPixel(matrixX, matrixY + 1, 0, 0, 0);
                NovaImagem->DrawPixel(matrixX + 1, matrixY + 1, i, i, i);
            }
            else if (i >= 154 && i <= 205) {
                NovaImagem->DrawPixel(matrixX, matrixY, i, i, i);
                NovaImagem->DrawPixel(matrixX + 1, matrixY, i, i, i);
                NovaImagem->DrawPixel(matrixX, matrixY + 1, 0, 0, 0);
                NovaImagem->DrawPixel(matrixX + 1, matrixY + 1, i, i, i);
            }
            else {
                NovaImagem->DrawPixel(matrixX, matrixY, i, i, i);
                NovaImagem->DrawPixel(matrixX + 1, matrixY, i, i, i);
                NovaImagem->DrawPixel(matrixX, matrixY + 1, i, i, i);
                NovaImagem->DrawPixel(matrixX + 1, matrixY + 1, i, i, i);
            }

            matrixY += 2;
        }

        matrixX += 2;
    }
}







// **********************************************************************
// void AplicaMediana()

// **********************************************************************
//  void init(void)
//		Inicializa os parâmetros globais de OpenGL
//
// **********************************************************************
void init(void)
{
    Image = new ImageClass();
    int r;

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Fundo de tela preto

    r = Image->Load((char *)"eagle.BMP");

    if (!r)
        exit(1);

    // Instacia o objeto que irá exibor a nova imagem 
    // Caso precise alterar o tamanho da nova imagem, mude os parâmetros
    // da construtura, na chamada abaixo
    NovaImagem = new ImageClass(Image->SizeX() * 2, Image->SizeY() * 2);

    // posiciona a imagem nova ao lado da antiga
    NovaImagem->SetPos(Image->SizeX() + 10, 0);

}


// **********************************************************************
//  void reshape( int w, int h )
//		trata o redimensionamento da janela OpenGL
//
// **********************************************************************
void reshape(int w, int h)
{

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    gluOrtho2D(0, w, 0, h);

    // Set the clipping volume
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


// **********************************************************************
//  void display( void )
//
//
// **********************************************************************
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    Image->Display();
    //ConvertBlackAndWhite();
    //ConvertToGrayScale();
    ConvertToHalftone();
    NovaImagem->Display();

    glutSwapBuffers();
}


// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
//
//
// **********************************************************************
void keyboard(unsigned char key, int x, int y)
{
    // Pode chamar aqui os métodos que fazem o processamento da imagem 
    // (defina novas entradas de dados para cada operação)  

    switch (key)
    {
    case 27:        // Termina o programa qdo
        exit(0);   // a tecla ESC for pressionada
        break;
    case '2':
        NovaImagem->Clear();
        ConvertBlackAndWhite();
        glutPostRedisplay();    // obrigratório para redesenhar a tela
        break;
    default:
        break;
    }
}


// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )  
//
//
// **********************************************************************
void arrow_keys(int a_keys, int x, int y)
{
    switch (a_keys)
    {
    case GLUT_KEY_UP:       // When Up Arrow Is Pressed...
        glutFullScreen(); // Go Into Full Screen Mode
        break;
    case GLUT_KEY_DOWN:     // When Down Arrow Is Pressed...
        glutInitWindowSize(700, 500);
        break;
    default:
        break;
    }
}


// **********************************************************************
//  void main ( int argc, char** argv )
//
//
// **********************************************************************
void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowPosition(0, 0);

    // Define o tamanho da janela gráfica do programa
    glutInitWindowSize(1000, 500);
    glutCreateWindow("Image Border");

    init();
    //	glutFullScreen();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrow_keys);
    glutIdleFunc(display);

    glutMainLoop();
}


