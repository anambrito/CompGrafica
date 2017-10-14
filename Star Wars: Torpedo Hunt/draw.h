#ifndef DRAW_H
#define DRAW_H

#include "texturas.h"
#include "movimento.h"
#include "func.h"
#include "callbacksGerais.h"

void Draw(float tamanho1, float tamanho2, GLfloat);
void DrawObj();
void DrawNave(GLuint);
void drawTorp(torp);
void DrawObstacle(float x, float x1, float y, float y1);
void newTorpedo();
void colisao();
void desenhaCena(void);

#endif
