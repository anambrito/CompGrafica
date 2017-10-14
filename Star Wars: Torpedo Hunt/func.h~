#ifndef FUNC_H
#define FUNC_H

#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

typedef struct pt{
    float x, y;
}pontos;

typedef struct tam{
    float largura, altura;
}tamanho;

typedef struct Torpedo {
    float larg;
	float alt;
	float x;
	float y;
	float rotacao;
}torp;

extern torp squad[];
extern pontos posicaoQuadrado;
extern tamanho tamanhoQuadrado;

extern pontos posicaoObj;
extern tamanho tamanhoObj;

extern float posicaoAnteriorX;
extern float posicaoAnteriorY;

extern float velocidade;
extern float velocidadeInicial; 
extern float telaLimite;

extern int angulo;
extern float rotacao;
extern char tecla;

extern int tamSquad;

extern GLuint texturaMenu;
extern GLuint texturaControls;
extern GLuint texturaCredits;
extern GLuint texturaNaveWASD;
extern GLuint texturaNaveAD;
extern GLuint texturaSpaceWASD;
extern GLuint texturaSpaceAD;
extern GLuint texturaObj;
extern GLuint texturaPause;	
extern GLuint texturaReinicia;
extern GLuint texturaGameOver;
extern GLuint texturaESC;


extern GLfloat posicaoNaveX, posicaoNaveY;
extern GLfloat pause;
extern GLfloat pause2;
extern GLfloat speed;

extern int ModoDeJogo;
extern int tipoMusica;

extern GLfloat velocidadeAngular;
extern GLfloat velocidadeTangencial;

extern Mix_Music *musicMenu;
extern Mix_Music *musica;
extern Mix_Chunk *somObj;
extern Mix_Chunk *somPortal;
extern Mix_Chunk *somMenu;
extern Mix_Chunk *somMais;
extern Mix_Chunk *somMenos;

extern int telaMenu;
extern int telaComandos;
extern int telaCreditos;
extern int telaPause;
extern int telaReinicia;
extern int telaGameOver;
extern int telaESC;


#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

#endif 
