//#define _USE_MATH_DEFINES
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//#include <GL/glut.h>
//
//#include "Curves.h"
//
//// ========== Handlers da janela. ==========
///**
//    Inicializa a tela.
//*/
//void init() {
//    glClearColor(getFloatColor(176), getFloatColor(190), getFloatColor(197), 1.0f);
//    glColor3f(0.0, 0.0, 0.0);
//    glPointSize(3);
//}
///**
//    Função de callback da tela para quando ela precisar ser redesenhada.
//*/
//void draw() {
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glClear(GL_COLOR_BUFFER_BIT);
//    glFlush();
//}
///**
//    Função que cuida das capturas de mouse.
//*/
//void mouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        drawDot(x, y);
//    }
//}
///**
//    Função para quando for a janela for "remodelada" (mudar de tamanho).
//    @param w Largura da janela.
//    @param h Altura da janela.
//*/
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glScalef(1.f, -1.f, 1.f);
//    gluOrtho2D(0.0, w, 0.0, h);
//}
//
//// ========== Funções de apoio. ==========
///**
//    Desenha um ponto vazado na tela.
//    @param x Posição x.
//    @param y Posição y.
//*/
//void drawDot(int x, int y) {
//    int i = 0,
//        numberLines = 10;
//    float radius = 4;
//
//    glColor3f(getFloatColor(2), getFloatColor(136), getFloatColor(209));
//    glLineWidth(2.3);
//
//    glBegin(GL_TRIANGLE_FAN);
//    for (i = 0; i < numberLines; i++) {
//        glVertex2f(x + (radius * cos(i *  2.0f * M_PI / numberLines)), y + (radius * sin(i * 2.0f * M_PI / numberLines)));
//    }
//    glEnd();
//
//    glBegin(GL_LINE_LOOP);
//    for (i = 0; i < numberLines; i++) {
//        glVertex2f(x + ((radius + 3) * cos(i *  2.0f * M_PI / numberLines)), y + ((radius + 3) * sin(i * 2.0f * M_PI / numberLines)));
//    }
//    glEnd();
//
//    glFlush();
//}
//
///**
//    Converte o range de RGB decimal (0 a 255) em float para as funções do OpenGL que tem parâmetros de cor.
//*/
//float getFloatColor(int value) {
//    return value / 255.0;
//}
//
//int main(int argc, char *argv[]) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutInitWindowPosition(10, 10);
//    glutCreateWindow("Cálculo Curva");
//    glutDisplayFunc(draw);
//    glutMouseFunc(mouse);
//    glutReshapeFunc(reshape);
//    init();
//    glutMainLoop();
//
//    return 0;
//}