#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <GL/glut.h>

#include "CurveEditor.h"

//==========================================================================================================
int dotQuantity = 4;
Dot dots[4];
void drawDotConnectionLine() {
	int i;

	glColor3f(getFloatColor(21), getFloatColor(101), getFloatColor(192));
	glLineWidth(2.f);

	glBegin(GL_LINE_STRIP);
	for (i = 0; i < dotQuantity; i++) {
		glVertex2d(dots[i].point.x, dots[i].point.y);
	}
	glEnd();

	glFlush();
}
void drawDots() {
	int i;
	for (i = 0; i < dotQuantity; i++) {
		drawDot(dots[i].point.x, dots[i].point.y);
	}
}

void drawBezier() {
	float t;
	glColor3f(getFloatColor(244), getFloatColor(67), getFloatColor(54));

	glBegin(GL_POINTS);
	for (t = 0.f; t <= 1.f; t += 0.0002) {

		glVertex2d(
			calcCubicBezier(t, dots[0].point.x, dots[1].point.x, dots[2].point.x, dots[3].point.x),
			calcCubicBezier(t, dots[0].point.y, dots[1].point.y, dots[2].point.y, dots[3].point.y)
		);
	}
	glEnd();

	glFlush();
}

void testThings() {
	dots[0].point = { 200, 150 };
	dots[1].point = { 250, 150 };
	dots[2].point = { 250, 50 };
	dots[3].point = { 300, 50 };

	drawDotConnectionLine();
	drawDots();
	drawBezier();

	dots[0].point = { 300, 50 };
	dots[1].point = { 350, 50 };
	dots[2].point = { 350, 150 };
	dots[3].point = { 400, 150 };

	drawDotConnectionLine();
	drawDots();
	drawBezier();
}
//==========================================================================================================

// ========== Handlers da janela. ==========
/**
	Inicializa a tela.
*/
void initScreen() {
	glClearColor(getFloatColor(176), getFloatColor(190), getFloatColor(197), 1.f);
	glColor3f(0.0, 0.0, 0.0);
}
/**
	Função de callback da tela para quando ela precisar ser desenhada.
*/
void draw() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();

	testThings();
}
/**
	Função que cuida das capturas de mouse.
*/
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		drawDot(x, y);
	}
}
/**
	Função para quando for a janela for "remodelada" (mudar de tamanho).
	@param w Largura da janela.
	@param h Altura da janela.
*/
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(1.f, -1.f, 1.f);
	gluOrtho2D(0.0, w, 0.0, h);
}

// ========== Funções de apoio. ==========
/**
	Desenha um ponto vazado na tela.
	@param x Posição x.
	@param y Posição y.
*/
void drawDot(int x, int y) {
	int i = 0,
		numberLines = DOT_RADIUS * 2;

	glColor3f(getFloatColor(2), getFloatColor(136), getFloatColor(209));
	glLineWidth(DOT_CIRCLE_WIDTH);

	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i < numberLines; i++) {
		glVertex2f(x + (DOT_MIDDLE_RADIUS * cos(i * 2.f * M_PI / numberLines)), y + (DOT_MIDDLE_RADIUS * sin(i * 2.f * M_PI / numberLines)));
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (i = 0; i < numberLines; i++) {
		glVertex2f(x + (DOT_CIRCLE_RADIUS * cos(i * 2.f * M_PI / numberLines)), y + (DOT_CIRCLE_RADIUS * sin(i * 2.f * M_PI / numberLines)));
	}
	glEnd();

	glFlush();
}
/**
	Converte o range de RGB decimal (0 a 255) em float para as funções do OpenGL que tem parâmetros de cor.
*/
float getFloatColor(int value) {
	return value / 255.f;
}
/**
	Faz o cálculo da curva Bezier para quatro pontos.
	@param t Valor de parametrização.
	@param point0 Primeiro ponto.
	@param point1 Segundo ponto.
	@param point2 Terceiro ponto.
	@param point3 Quarto ponto.
*/
float calcCubicBezier(float t, float point0, float point1, float point2, float point3) {
	float tDiff = 1 - t;

	return (pow(tDiff, 3) * point0) + (3 * t * pow(tDiff, 2) * point1) + (3 * pow(t, 2) * tDiff * point2) + (pow(t, 3) * point3);
}
/**
	Faz o cálculo do coeficiente binomial que é usado no cálculo de curva Bezier.
	@param n "Parte de cima" do cálculo.
	@param k "Parte de baixo" do cálculo.
*/
int calculeBinomialCoefficient(int n, int k)
{
	int res = 1;

	if (k > n - k) k = n - k;

	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Cálculo Curva");
	glutDisplayFunc(draw);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	initScreen();
	glutMainLoop();

	return 0;
}

// https://forum.processing.org/two/discussion/19164/make-a-bezier-curve-with-more-than-2-control-points
// https://en.wikipedia.org/wiki/Binomial_coefficient
// https://www.geeksforgeeks.org/pascal-triangle/
// http://www.mathwords.com/b/binomial_coefficients.htm