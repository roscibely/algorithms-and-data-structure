# Estrutura de dados para filas 

## O que é uma fila?

Uma fila é uma estrutura de dados que segue o princípio FIFO (First In First Out), ou seja, o primeiro elemento a entrar é o primeiro a sair.

## Como funciona?

A fila é uma estrutura de dados que funciona como uma fila de banco, onde o primeiro a chegar é o primeiro a ser atendido.

## Exemplo

```c 

#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;

struct fila {
    int info;
    Fila *prox;
};

Fila *cria_fila() {
    return NULL;
}

int fila_vazia(Fila *f) {
    return (f == NULL);
}       

Fila *insere(Fila *f, int i) {
    Fila *novo = (Fila *) malloc(sizeof(Fila));
    novo->info = i;
    novo->prox = NULL;
    if (fila_vazia(f)) {
        return novo;
    }
    Fila *aux = f;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return f;
}

Fila *retira(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        return NULL;
    }
    Fila *aux = f;
    f = f->prox;
    free(aux);
    return f;
}

void imprime(Fila *f) {
    Fila *aux = f;
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

int main() {
    Fila *f = cria_fila();
    f = insere(f, 1);
    f = insere(f, 2);
    f = insere(f, 3);
    f = insere(f, 4);
    f = insere(f, 5);
    f = insere(f, 6);
    f = insere(f, 7);
    f = insere(f, 8);
    f = insere(f, 9);
    f = insere(f, 10);
    imprime(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    f = retira(f);
    imprime(f);
    return 0;
}

```
