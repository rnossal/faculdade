#pragma once

// ========== Handlers da janela. ==========
void init();
void draw();
void mouse(int button, int state, int x, int y);
void reshape(int w, int h);
// ========== Fun��es de apoio. ==========
void drawDot(int x, int y);
float getFloatColor(int value);