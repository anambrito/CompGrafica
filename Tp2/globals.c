#include "globals.h"

struct C camera;

GLfloat lightAmb[4] = { 0.2, 0.2, 0.2, 1.0 };

double w_window=720, h_window=480;
//static float m = 0.2;           //Intensidade da luz ambiente global.
//static int localViewer = 0; 

int txSolo;
int txParede, txTelhado, txTijolos, txPorta;
//int txSky;
/*
float light_ambient[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
float light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
float light_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
float light_position[] = { 10.0f, 50.0f, 50.0f, 1.0f };

float mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
float mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
float mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
float high_shininess[] = { 100.0f };*/