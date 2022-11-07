#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX 3

struct fila {
    int inicio;
    int fim;
    int numero_elementos;
    int dados[MAX];
};

Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->numero_elementos = 0;
    return f;
}

void fila_insere(Fila* f, int v) {
    if (fila_cheia(f)) {
        printf("Capacidade da fila estourou!"); 
        exit(1); // aborta programa
    }
    f->dados[f->fim] = v;
    f->fim = incrementa(f->fim);
    f->numero_elementos++;
}

int fila_remove(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia!"); 
        exit(1); // aborta programa
    }
    int elemento = f->dados[f->inicio];
    f->inicio = incrementa(f->inicio);
    f->numero_elementos--;
    return elemento;
}   

int fila_vazia(Fila* f) {
    return (f->inicio == f->numero_elementos);
}

int fila_cheia(Fila* f) {
    return (f->numero_elementos == MAX);
}

void fila_libera(Fila* f) {
    free(f);
}

void fila_imprime(Fila* f) {
    int i;
    printf("Fila: \" ");
    for (i =0; i<f->numero_elementos; i++)
        printf("%d ", f->dados[incrementa(i)]);
    printf("\"\n");
}

int incrementa(int i) {
    return (i + 1) % MAX;
}



