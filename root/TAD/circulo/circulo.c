#include <stdio.h> 
#include <stdlib.h>
#include "circulo.h"

struct circulo
{
    float x,y; // Coordenadas do centro
    float raio; // raio 
};


Circulo* cria_circulo() {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    if(c==NULL){
        exit(1);
    }
    else{
        printf("Digite a coordenada x: ");
        scanf("%f", &c->x); 
        printf("\nDigite a coordenada y: ");
        scanf("%f", &c->y); 
        printf("\nDigite  o raio: ");
        scanf("%f", &c->raio); 
    }
    return c;
}


float area_circulo(Circulo* c) {
    return 3.14 * c->raio * c->raio;
}


void move_circulo(Circulo* c, float novo_x, float novo_y) {
    c->x = novo_x;
    c->y = novo_y;
}