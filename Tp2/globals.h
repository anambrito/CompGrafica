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


struct C{
	GLdouble eyeX, eyeY, eyeZ;
	GLdouble xAngle, yAngle, zAngle;
};

typedef struct vetor{
    double x,y,z;
} Vetor;

extern struct C camera;

extern GLfloat lightAmb[];

extern double w_window, h_window;
//extern static float m;           //Intensidade da luz ambiente global.
//extern static int localViewer; 

extern int txSolo;
extern int txParede, txTelhado, txTijolos, txPorta;
//extern int txSky;

/*
extern float light_ambient[];
extern float  light_diffuse[];
extern float light_specular[];// = { 0.5f, 0.5f, 0.5f, 1.0f };
extern float light_position[];// = { 10.0f, 50.0f, 50.0f, 1.0f };

extern float mat_ambient[];//    = { 0.7f, 0.7f, 0.7f, 1.0f };
extern float mat_diffuse[];//    = { 0.8f, 0.8f, 0.8f, 1.0f };
extern float mat_specular[];//   = { 1.0f, 1.0f, 1.0f, 1.0f };
extern float high_shininess[];// = { 100.0f };
*/

#endif