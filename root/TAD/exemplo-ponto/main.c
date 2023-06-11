#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"


int main(void){

    Ponto* p = cria(2.0,1.0);
    Ponto* q = cria(3.4,2.1);
    float d = distancia(p,q);
    printf("Distancia entre pontos: %.1f\n",d);
    libera(q);
    libera(p);

    return 0;
}
