
#include <math.h>
#include <vector>
#include <GL\glut.h>
#include <iostream>

void display();
void reshape(GLint x, GLint y);
void mouse(GLint button, GLint state, GLint x, GLint y);
void motion(GLint x, GLint y);
void initialize();
void bezier();
int combinatorics(int n, int r);

// Coord attributes
GLint const COORD_POINT_SIZE = 10;
GLint const COORD_POINT_THRESHOLD_SIZE = 8;

struct Coord {
    GLdouble x;
    GLdouble y;

    bool isThis(GLdouble cX, GLdouble cY) {
        return (x <= cX + COORD_POINT_SIZE && x >= cX - COORD_POINT_SIZE
            && y <= cY + COORD_POINT_SIZE && y >= cY - COORD_POINT_SIZE) ? true : false;
    }

    bool itsClose(GLdouble cX, GLdouble cY) {
        return (x <= cX + COORD_POINT_SIZE + COORD_POINT_THRESHOLD_SIZE
            && x >= cX - COORD_POINT_SIZE - COORD_POINT_THRESHOLD_SIZE
            && y <= cY + COORD_POINT_SIZE + COORD_POINT_THRESHOLD_SIZE
            && y >= cY - COORD_POINT_SIZE - COORD_POINT_THRESHOLD_SIZE) ? true : false;
    }
};

// Bezier points
int const COORDS_MAX = 34;
Coord coords[COORDS_MAX];
int coordIndex = 0;

// Bezier attributes
int combinatoricValues[COORDS_MAX];
int lastPointsAmount = 0;
double interval = 0.001;

///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(300, 100);

    glutCreateWindow("Bezier Curve - pedro00dk");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    initialize();

    glutMainLoop();
}
///////////////////////////////////////////////////////////////////////////////

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3d(0.8, 0.3, 0.3);
    glBegin(GL_POINTS);
    for (int i = 0; i < coordIndex; i++) {
        glVertex2d(coords[i].x, coords[i].y);
    }
    glEnd();

    glColor3d(0.8, 0.6, 0.6);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < coordIndex; i++) {
        glVertex2d(coords[i].x, coords[i].y);
    }
    glEnd();

    glColor3d(0.1, 0.1, 0.1);
    bezier();

    glFlush();
}

void reshape(GLint width, GLint height) {

    if (width == 0) {
        width = 1;
    }
    if (height == 0) {
        height = 1;
    }

    glViewport(0, 0, width, height);
    glOrtho(0.0, width, -height, 0.0, -1.0, 1.0);
}

void mouse(GLint button, GLint state, GLint x, GLint y) {
    y = -y;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && coordIndex < COORDS_MAX) {
        bool exists = false;

        for (int i = 0; i < coordIndex && exists == false; i++) {
            exists = coords[i].isThis(x, y);
        }

        if (!exists) {
            Coord point;
            point.x = x;
            point.y = y;
            coords[coordIndex++] = point;
            glutPostRedisplay();
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        for (int i = 0; i < coordIndex; i++) {
            if ((coords[i].isThis(x, y))) {
                for (int j = i; j < coordIndex - 1; j++) {
                    coords[j] = coords[j + 1];
                }
                coordIndex--;
                glutPostRedisplay();
                return;
            }
        }
    }
}

void motion(GLint x, GLint y) {
    y = -y;
    for (int i = 0; i < coordIndex; i++) {
        if ((coords[i].isThis(x, y))) {
            coords[i].x = x;
            coords[i].y = y;

            // Desenha a tela novamente
            glutPostRedisplay();
            break;
        }
    }
}

void initialize() {
    glClearColor(0.9, 0.9, 1.0, 1.0);
    glPointSize(COORD_POINT_SIZE);
}

// Bezier draw
void bezier() {

    // Draw if has more than one point
    if (coordIndex > 1) {

        // Verify if the combinatoric recalculation is nescessary
        if (coordIndex != lastPointsAmount) {
            int n = coordIndex - 1;
            for (int i = 0, j = n; i <= j; i++, j--) {
                combinatoricValues[i] = combinatoricValues[j] = combinatorics(n, i);
            }
        }
        lastPointsAmount = coordIndex;

        // Start bezier curve draw
        glBegin(GL_LINE_STRIP);
        int n = coordIndex - 1;
        for (double t = 0; t <= 1; t = t + interval) {
            GLdouble tX = 0.0f;
            GLdouble tY = 0.0f;
            for (int i = 0; i <= n; i++) {
                double coeficient = combinatoricValues[i] * pow(1 - t, n - i) * pow(t, i);
                tX += coeficient * coords[i].x;
                tY += coeficient * coords[i].y;
            }
            glVertex2d(tX, tY);
        }
        glEnd();
    }
}

int combinatorics(int n, int r) {
    long double result = 1;
    for (int n_r = n - r; n > 1; n--, r--, n_r--) {
        result *= n;
        if (r > 1) result /= r;
        if (n_r > 1) result /= n_r;
    }
    return (int)result + 0.5;
}