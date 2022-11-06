#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

int main(){
     Fila *f = fila_cria();
    fila_insere(f,4.0);
    fila_insere(f,5.0);
    fila_insere(f,6.0);
    fila_insere(f,8.0);
    fila_insere(f,2.0);
    float v = fila_retira(f);
    float g = fila_retira(f);
    float h = fila_retira(f);
    fila_fura(f, 7.0);
    fila_insere(f,6.0);
    fila_insere(f,4.0);
    fila_insere(f,5.0);
    inv(f);
    fila_imprime(f);
    return 0;
}
