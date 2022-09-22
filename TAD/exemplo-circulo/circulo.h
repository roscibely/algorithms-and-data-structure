#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
typedef struct circulo Circulo;

Circulo* circ_cria(float x, float y, float r);

void circ_libera(Circulo* C);

float circ_area(Circulo *C);

int circ_interior(Ponto *p, Circulo *C);


#endif // CIRCULO_H_INCLUDED
