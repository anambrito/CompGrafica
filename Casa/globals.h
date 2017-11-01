#ifndef GLOBALS_H
#define GLOBALS_H

#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <GL/glut.h>
#include "glm.h"

struct C{
	GLdouble eyeX, eyeY, eyeZ;
	GLdouble xAngle, yAngle, zAngle;
};

typedef struct vetor{
    double x,y,z;
} Vetor;

extern struct C camera;

extern GLfloat lightAmb[];
extern GLMmodel* mesa;
extern GLMmodel* cama;
extern GLMmodel* caneca;
extern GLMmodel* carro;
extern GLuint mesaList, camaList, canecaList, carroList;
extern double w_window, h_window;

extern int txSolo, txSky, txSky2, txSky3, txSky4, txSky5, txSky6;
extern int txParede, txTelhado, txMadeira, txPorta,txChao, txJanelaDentro, txJanelaFora;

#endif
