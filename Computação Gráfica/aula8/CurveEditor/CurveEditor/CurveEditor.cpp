#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <GL/glut.h>

#include "CurveEditor.h"

// ========== Vari�veis globais. ===========
int pressedButton = -1;
int dragging = 0;
Dot *draggingDot = NULL;
Curve *curves = NULL;
int curvesLimit = MAX_CURVES;
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
    Fun��o de callback da tela para quando ela precisar ser desenhada.
*/
void draw() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    drawDotConnectionLines();
    drawDots();
    drawDotConnectionBeziers();

    glFlush();
}
/**
    Fun��o que cuida das capturas de mouse.
    @param button C�digo do bot�o que foi pressionado.
    @param x Posi��o x do cursor.
    @param y Posi��o y do cursor.
*/
void mouse(int button, int state, int x, int y) {
    int i, j, k;

    pressedButton = button;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        if (!dragging) {
            if (curves[currentCurve].currentDot + 1 >= MAX_DOT_PER_CURVE) {
                currentCurve++;

                curves[currentCurve].dots = (Dot *)malloc(MAX_DOT_PER_CURVE * sizeof(Dot));
                for (i = 0; i < MAX_DOT_PER_CURVE; i++) {
                    curves[currentCurve].dots[i].location.x = 0;
                    curves[currentCurve].dots[i].location.y = 0;
                }
            }

            curves[currentCurve].currentDot++;
            curves[currentCurve].dots[curves[currentCurve].currentDot].location.x = x;
            curves[currentCurve].dots[curves[currentCurve].currentDot].location.y = y;

            glutPostRedisplay();
        }

        dragging = 0;
        draggingDot = NULL;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        for (i = 0; i <= currentCurve; i++) {
            for (j = 0; j <= curves[i].currentDot; j++) {
                if (curves[i].dots[j].isHit(x, y)) {
                    for (k = j; k < curves[i].currentDot; k++) {
                        curves[i].dots[k] = curves[i].dots[k + 1];
                    }
                    curves[i].currentDot--;
                    break;
                }
            }
        }

        glutPostRedisplay();
    }

    if (state == GLUT_UP) {
        pressedButton = -1;
    }
}
/**
    Fun��o disparada quando o cursor se move pela tela e algum bot�o do mouse est� pressionado.
    @param x Posi��o x do cursor.
    @param y Posi��o y do cursor.
*/
void mouseMove(int x, int y) {
    if (dragging) {
        draggingDot->location.x = x;
        draggingDot->location.y = y;

        glutPostRedisplay();
    }
    else {
        if (pressedButton == GLUT_LEFT_BUTTON) {
            int i, j;
            for (i = 0; i <= currentCurve; i++) {
                for (j = 0; j <= curves[i].currentDot; j++) {
                    if (curves[i].dots[j].isHit(x, y)) {
                        dragging = 1;
                        draggingDot = &curves[i].dots[j];
                    }
                }
            }
        }
    }
};
/**
    Fun��o para quando for a janela for "remodelada" (mudar de tamanho).
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

// ========== Fun��es de apoio. ==========
/**
    Inicia as estruturas e vari�veis b�sicas para o funcionamento.
*/
void initStructures() {
    int i;

    curves = (Curve *)malloc(MAX_CURVES * sizeof(Curve));

    for (i = 0; i < MAX_CURVES; i++) {
        curves[i].dots = NULL;
        curves[i].dotsLimit = MAX_DOT_PER_CURVE;
        curves[i].currentDot = -1;
    }

    curves[0].dots = (Dot *)malloc(MAX_DOT_PER_CURVE * sizeof(Dot));
    for (i = 0; i < MAX_DOT_PER_CURVE; i++) {
        curves[0].dots[i].location.x = 0;
        curves[0].dots[i].location.y = 0;
    }
}
/**
    Desenha um ponto vazado na tela.
    @param x Posi��o x.
    @param y Posi��o y.
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
}
/**
    Desenha todos os pontos que est�o armazenados no programa.
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
    Desenha as linhas de conex�o dos pontos de uma curva.
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
}
/**
    Desenha todas as linhas de conex�o de todas as curvas que est�o armazenados no programa.
*/
void drawDotConnectionLines() {
    int i;

    for (i = 0; i <= currentCurve; i++) {
        drawDotConnectionLine(&curves[i]);
    }
}
/**
    Converte o range de RGB decimal (0 a 255) em float para as fun��es do OpenGL que tem par�metros de cor.
*/
float getFloatColor(int value) {
    return value / 255.f;
}
/**
    Faz o c�lculo do coeficiente binomial que � usado no c�lculo de curva Bezier.
    @param n "Parte de cima" do c�lculo.
    @param k "Parte de baixo" do c�lculo.
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
    Faz o c�lculo de curva Bezier dos pontos usando o calculo de tri�ngulo de Pascal para fugir de ser somente uma curva c�bica.
    @param t Valor de parametriza��o.
    @param curve Curva a serem pegos os pontos para ser calculado.
*/
Point calculePointBezier(double t, Curve *curve) {
    Point point;
    int i;
    double tDiff = 1 - t;

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
    double t;
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
}
/**
    Desenha todas as curvar Bezier de todas as curvas que est�o armazenados no programa.
*/
void drawDotConnectionBeziers() {
    int i;

    for (i = 0; i <= currentCurve; i++) {
        drawBezier(&curves[i]);
    }
}
/**
    Faz o c�lculo da curva Bezier para quatro pontos (Aqui s� a n�vel de hist�rico da f�rmula).
    @param t Valor de parametriza��o.
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
    glutCreateWindow("C�lculo Curva");
    glutDisplayFunc(draw);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(reshape);
    initStructures();
    initScreen();
    glutMainLoop();

    return 0;
}
