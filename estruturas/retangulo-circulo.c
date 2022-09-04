#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Defina estruturas para representar retângulos (dadas a base e a altura) e círculos (dado o raio) */

typedef struct retangulo{
    float base;
    float altura;
} Ret;

typedef struct circulo{
    float raio;
} Circ;

/* Dado um círculo, crie e retorne o maior retângulo circunscrito de altura h. Considere que h é menor do
que o diâmetro do círculo*/

Ret * ret_circunscrito(Circ *c, float h){
    Ret *r= malloc(sizeof(Ret));
    r->base = 2 * sqrt(pow(c->raio, 2) - pow(h, 2));
    r->altura = h;
    return r;
}

/* Dado um retângulo, crie e retorne o maior círculo interno ao retângulo*/

Circ * circ_interno(Ret *r){
    Circ *c = malloc(sizeof(Circ));
    c->raio = sqrt(pow(r->base, 2) + pow(r->altura, 2)) / 2;
    return c;
}


int main(void){
    Circ *c = malloc(sizeof(Circ));
    c->raio = 5;
    Ret *r = ret_circunscrito(c, 3);
    printf("Base: %f ", r->base); 
    printf("Altura: %f ", r->altura);
    free(c);
    free(r);
    return 0;
}