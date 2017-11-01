#include "globals.h"
#include "glm.h"
#include <GL/freeglut.h>
#include <GL/glut.h>

struct C camera;

GLfloat lightAmb[4] = { 0.2, 0.2, 0.2, 1.0 };

double w_window=720, h_window=480;
int txSolo, txSky, txSky2, txSky3, txSky4, txSky5, txSky6;
int txParede, txTelhado, txMadeira, txPorta, txChao , txJanelaDentro, txJanelaFora;;
GLMmodel* mesa;
GLMmodel* cama;
GLMmodel* caneca;
GLMmodel* carro;
GLuint mesaList, camaList, canecaList, carroList;
