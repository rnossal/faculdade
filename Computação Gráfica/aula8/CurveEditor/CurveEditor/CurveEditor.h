#pragma once

// ========== Defines de valores de elementos fixos. ===========
#define DOT_MIDDLE_RADIUS 4
#define DOT_CIRCLE_RADIUS (DOT_MIDDLE_RADIUS + 3)
#define DOT_CIRCLE_WIDTH 2
#define DOT_RADIUS (DOT_CIRCLE_RADIUS + (DOT_CIRCLE_WIDTH / 2))
#define MAX_CURVES 2000
#define MAX_DOT_PER_CURVE 4

// ======================== Estruturas =========================
typedef struct Point
{
    double x;
    double y;
} Point;

typedef struct Dot
{
    Point location;
    int isHit(int x, int y) {
        if ((location.x + DOT_RADIUS) >= x && (location.x - DOT_RADIUS) <= x &&
            (location.y + DOT_RADIUS) >= y && (location.y - DOT_RADIUS) <= y) {
            return 1;
        }
        return 0;
    }
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
void mouseMove(int x, int y);
void reshape(int w, int h);

// ===================== Funções de apoio. =====================
void initStructures();
void drawDot(Dot *dot);
void drawDots();
void drawDotConnectionLine(Curve *curve);
void drawDotConnectionLines();
float getFloatColor(int value);
int calculeBinomialCoefficient(int n, int k);
Point calculePointBezier(double t, Curve *curve);
void drawBezier(Curve *curve);
void drawDotConnectionBeziers();
float calcCubicBezier(float t, float point0, float point1, float point2, float point3);