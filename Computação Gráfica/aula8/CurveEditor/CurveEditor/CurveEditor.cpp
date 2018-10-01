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

void drawBezier() {
	float t;
	glColor3f(getFloatColor(244), getFloatColor(67), getFloatColor(54));

	glBegin(GL_POINTS);
	for (t = 0.f; t <= 1.f; t += 0.0002) {

		glVertex2d(
			calcCubicBezier(t, dots[0].location.x, dots[1].location.x, dots[2].location.x, dots[3].location.x),
			calcCubicBezier(t, dots[0].location.y, dots[1].location.y, dots[2].location.y, dots[3].location.y)
		);
	}
	glEnd();

	glFlush();
}



void testThings() {
	dots[0].location = { 200, 150 };
	dots[1].location = { 250, 150 };
	dots[2].location = { 250, 50 };
	dots[3].location = { 300, 50 };

	drawBezier();
}
//==========================================================================================================

// ========== Variáveis globais. ===========
Curve *curves = NULL;
int curvesLimit = INITIAL_ALOC;
int currentCurve = 0;

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

	drawDotConnectionLines();
	drawDots();
	drawDotConnectionBeziers();

	testThings();
}
/**
	Função que cuida das capturas de mouse.
*/
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		curves[currentCurve].currentDot++;
		curves[currentCurve].dots[curves[currentCurve].currentDot].location.x = x;
		curves[currentCurve].dots[curves[currentCurve].currentDot].location.y = y;

		draw();
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
	Inicia as estruturas e variáveis básicas para o funcionamento.
*/
void initStructures() {
	int i;

	curves = (Curve *)malloc(INITIAL_ALOC * sizeof(Curve));

	for (i = 0; i < INITIAL_ALOC; i++) {
		curves[i].dots = NULL;
		curves[i].dotsLimit = INITIAL_ALOC;
		curves[i].currentDot = -1;
	}

	curves[0].dots = (Dot *)malloc(INITIAL_ALOC * sizeof(Dot));
	for (i = 0; i < INITIAL_ALOC; i++) {
		curves[0].dots[i].location.x = 0;
		curves[0].dots[i].location.y = 0;
	}

	curves[0].dots[0].location.x = 250;
	curves[0].dots[0].location.y = 150;

	curves[0].dots[1].location.x = 300;
	curves[0].dots[1].location.y = 150;

	curves[0].dots[2].location.x = 300;
	curves[0].dots[2].location.y = 50;

	curves[0].dots[3].location.x = 350;
	curves[0].dots[3].location.y = 50;

	curves[0].currentDot = 3;
}
/**
	Desenha um ponto vazado na tela.
	@param x Posição x.
	@param y Posição y.
*/
void drawDot(Dot *dot) {
	int i = 0,
		numberLines = DOT_RADIUS * 2;

	glColor3f(getFloatColor(2), getFloatColor(136), getFloatColor(209));
	glLineWidth(DOT_CIRCLE_WIDTH);

	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i < numberLines; i++) {
		glVertex2f(dot->location.x + (DOT_MIDDLE_RADIUS * cos(i * 2.f * M_PI / numberLines)), dot->location.y + (DOT_MIDDLE_RADIUS * sin(i * 2.f * M_PI / numberLines)));
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (i = 0; i < numberLines; i++) {
		glVertex2f(dot->location.x + (DOT_CIRCLE_RADIUS * cos(i * 2.f * M_PI / numberLines)), dot->location.y + (DOT_CIRCLE_RADIUS * sin(i * 2.f * M_PI / numberLines)));
	}
	glEnd();

	glFlush();
}
/**
	Desenha todos os pontos que estão armazenados no programa.
*/
void drawDots() {
	int i, j;
	for (i = 0; i <= currentCurve; i++) {
		for (j = 0; j <= curves[i].currentDot; j++) {
			drawDot(&curves[i].dots[j]);
		}
	}
}
/**
	Desenha as linhas de conexão dos pontos de uma curva.
*/
void drawDotConnectionLine(Curve *curve) {
	int i;

	glColor3f(getFloatColor(21), getFloatColor(101), getFloatColor(192));
	glLineWidth(2.f);

	glBegin(GL_LINE_STRIP);

	for (i = 0; i <= curve->currentDot; i++) {
		glVertex2d(curve->dots[i].location.x, curve->dots[i].location.y);
	}

	glEnd();

	glFlush();
}
/**
	Desenha todas as linhas de conexão de todas as curvas que estão armazenados no programa.
*/
void drawDotConnectionLines() {
	int i;

	for (i = 0; i <= currentCurve; i++) {
		drawDotConnectionLine(&curves[i]);
	}
}
/**
	Converte o range de RGB decimal (0 a 255) em float para as funções do OpenGL que tem parâmetros de cor.
*/
float getFloatColor(int value) {
	return value / 255.f;
}
/**
	Faz o cálculo do coeficiente binomial que é usado no cálculo de curva Bezier.
	@param n "Parte de cima" do cálculo.
	@param k "Parte de baixo" do cálculo.
*/
int calculeBinomialCoefficient(int n, int k) {
	int res = 1;

	if (k > n - k) k = n - k;

	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}
/**
	Faz o cálculo de curva Bezier dos pontos usando o calculo de triângulo de Pascal para fugir de ser somente uma curva cúbica.
	@param t Valor de parametrização.
	@param curve Curva a serem pegos os pontos para ser calculado.
*/
Point calculePointBezier(float t, Curve *curve) {
	Point point;
	int i;
	float tDiff = 1 - t;

	point.x = 0;
	point.y = 0;
	for (i = 0; i <= curve->currentDot; i++) {
		point.x += calculeBinomialCoefficient(curve->currentDot, i) * pow(tDiff, curve->currentDot - i) * pow(t, i) * curve->dots[i].location.x;
		point.y += calculeBinomialCoefficient(curve->currentDot, i) * pow(tDiff, curve->currentDot - i) * pow(t, i) * curve->dots[i].location.y;
	}

	return point;
}
/**
	Desenha a curva Bezier de uma Determinada curva.
*/
void drawBezier(Curve *curve) {
	int i;
	float t;
	glColor3f(getFloatColor(244), getFloatColor(67), getFloatColor(54));

	if (curve->currentDot > 1) {
		glBegin(GL_POINTS);
		for (t = 0.f; t <= 1.f; t += 0.0002) {
			Point point = calculePointBezier(t, curve);

			glVertex2d(
				point.x,
				point.y
			);
		}
		glEnd();
	}

	glFlush();
}
/**
	Desenha todas as curvar Bezier de todas as curvas que estão armazenados no programa.
*/
void drawDotConnectionBeziers() {
	int i;

	for (i = 0; i <= currentCurve; i++) {
		drawBezier(&curves[i]);
	}
}
/**
	Faz o cálculo da curva Bezier para quatro pontos (Aqui só a nível de histórico da fórmula).
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


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Cálculo Curva");
	glutDisplayFunc(draw);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	initStructures();
	initScreen();
	glutMainLoop();

	return 0;
}

// https://forum.processing.org/two/discussion/19164/make-a-bezier-curve-with-more-than-2-control-points
// https://en.wikipedia.org/wiki/Binomial_coefficient
// https://www.geeksforgeeks.org/pascal-triangle/
// http://www.mathwords.com/b/binomial_coefficients.htm