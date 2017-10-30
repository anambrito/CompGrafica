#ifndef DESENHAR_H
#define DESENHAR_H

#include "globals.h"

int carregaTextura(char*);
void inicializarTexturas(void);
void desenhaTelhado();
void desenhaPorta(double);
void desenhaPiramide(double);
void desenhaPlano(double, double, double, int);
void desenhaCubo(double, int);

#endif