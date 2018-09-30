#pragma once

// ========== Defines de valores de elementos fixos. ===========
#define DOT_MIDDLE_RADIUS 4
#define DOT_CIRCLE_RADIUS (DOT_MIDDLE_RADIUS + 3)
#define DOT_CIRCLE_WIDTH 2
#define DOT_RADIUS (DOT_CIRCLE_RADIUS + (DOT_CIRCLE_WIDTH / 2))

// ======================== Estruturas =========================
typedef struct Point
{
	int x;
	int y;
};

typedef struct Dot
{
	Point point;
};

// ==================== Handlers da janela. ====================
void initScreen();
void draw();
void mouse(int button, int state, int x, int y);
void reshape(int w, int h);

// ===================== Funções de apoio. =====================
void drawDot(int x, int y);
float getFloatColor(int value);
float calcCubicBezier(float t, float point0, float point1, float point2, float point3);
int calculeBinomialCoefficient(int n, int k);