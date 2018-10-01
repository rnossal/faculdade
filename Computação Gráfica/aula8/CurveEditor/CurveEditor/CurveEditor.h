#pragma once

// ========== Defines de valores de elementos fixos. ===========
#define DOT_MIDDLE_RADIUS 4
#define DOT_CIRCLE_RADIUS (DOT_MIDDLE_RADIUS + 3)
#define DOT_CIRCLE_WIDTH 2
#define DOT_RADIUS (DOT_CIRCLE_RADIUS + (DOT_CIRCLE_WIDTH / 2))
#define INITIAL_ALOC 20

// ======================== Estruturas =========================
typedef struct Point
{
	float x;
	float y;
} Point;

typedef struct Dot
{
	Point location;
} Dot;

typedef struct Curve
{
	Dot *dots;
	int dotsLimit;
	int currentDot;

} Curve;

// ==================== Handlers da janela. ====================
void initScreen();
void draw();
void mouse(int button, int state, int x, int y);
void reshape(int w, int h);

// ===================== Funções de apoio. =====================
void initStructures();
void drawDot(Dot *dot);
void drawDots();
void drawDotConnectionLine(Curve *curve);
void drawDotConnectionLines();
float getFloatColor(int value);
int calculeBinomialCoefficient(int n, int k);
Point calculePointBezier(float t, Curve *curve);
void drawBezier(Curve *curve);
void drawDotConnectionBeziers();
float calcCubicBezier(float t, float point0, float point1, float point2, float point3);