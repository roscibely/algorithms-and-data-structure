// implemente a struct pilha com vetores 

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX 10

struct pilha {
    int topo;
    int dados[MAX];
};

Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void pilha_push(Pilha* p, int v) {
    if (p->topo == MAX) {
        printf("Capacidade da pilha estourou!"); 
        exit(1); // aborta programa
    }
    p->dados[p->topo] = v;
    p->topo++;
}

int pilha_pop(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia!"); 
        exit(1); // aborta programa
    }
    return p->dados[--p->topo];
}

int pilha_vazia(Pilha* p) {
    return (p->topo == 0);
}

void pilha_libera(Pilha* p) {
    free(p);
}

void pilha_imprime(Pilha* p) {
    int i;
    printf("Pilha: \" ");
    for (i = 0; i < p->topo; i++)
        printf("%d ", p->dados[i]);
    printf("\"\n");
}

