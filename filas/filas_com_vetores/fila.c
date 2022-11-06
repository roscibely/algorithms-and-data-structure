#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX 10

struct fila {
    int inicio;
    int fim;
    int dados[MAX];
};

Fila* fila_cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    return f;
}

void fila_insere(Fila* f, int v) {
    if (fila_cheia(f)) {
        printf("Capacidade da fila estourou!"); 
        exit(1); // aborta programa
    }
    f->dados[f->fim] = v;
    f->fim++;
}

int fila_remove(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia!"); 
        exit(1); // aborta programa
    }
    return f->dados[f->inicio++];
}   

int fila_vazia(Fila* f) {
    return (f->inicio == f->fim);
}

int fila_cheia(Fila* f) {
    return (f->fim == MAX);
}

void fila_libera(Fila* f) {
    free(f);
}

void fila_imprime(Fila* f) {
    int i;
    printf("Fila: \" ");
    for (i = f->inicio; i < f->fim; i++)
        printf("%d ", f->dados[i]);
    printf("\"\n");
}




