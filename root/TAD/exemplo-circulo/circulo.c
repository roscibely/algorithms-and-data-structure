#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
#include "circulo.h"
#define PI 3.14

struct circulo{
    Ponto* c;
    float r;

};

Circulo* circ_cria(float x, float y, float R){
    Ponto * p = cria(x,y);
    Circulo*C = (Circulo *) malloc(sizeof(Circulo));
    if(C == NULL){
        exit(1);
    }
    C->c = p;
    C->r = R;
    return C;
}

void circ_libera(Circulo* C){
    libera(C->c);
    free(C);
}


float circ_area(Circulo *C){
	float a = (C->r)*(C->r)*PI;
	return a;
}

int circ_interior(Ponto *p, Circulo *C){
    float dist = distancia(p,C->c);
    return dist<C->r?1:0;
}
