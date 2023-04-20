#define N 10
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

typedef struct lista{
    float info;
    struct lista * prox;
}Lista;

struct pilha{
	Lista * prim;
};

Pilha * pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push(Pilha* p, float v){
    Lista * t = (Lista*) malloc(sizeof(Lista));
    t->info = v;
    t->prox= p->prim;
    p->prim =t;
}

float pilha_pop(Pilha* p){
    if(pilha_vazia(p)){
        printf("Pilha vazia\n");
        exit(1);
    }
     Lista * t;
     float v;
     t = p->prim;
     v = t->info;
     p->prim = t->prox;
     free(t);
     return v;
}

int pilha_vazia(Pilha *p){
    return (p->prim ==NULL);
}

void pilha_libera(Pilha*p){
    Lista* q= p->prim;
    Lista* t;
    while (q != NULL) {
        t = q->prox;
        free(q);
        q = t;

    }
    free(p);
}

float topo(Pilha* p){
    Lista*t =(Lista*) malloc(sizeof(Lista));
    t =p->prim;
    float v = t->info;
    return v;

}

void imprime(Pilha*l){
	Lista*p;
	for(p=l->prim; p!=NULL; p=p->prox){
		printf(" Info = %.2f \n", p->info);
	}

}

void concatena(Pilha * p1, Pilha *p2){
    Lista*aux = NULL;
    while(p2->prim!=NULL){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
	    novo->info = pilha_pop(p2);
	    novo->prox = aux;
        aux= novo;
    }
    while(aux!=NULL){
        pilha_push(p1, aux->info);
        aux = aux->prox;
    }
}

Pilha* copia_pilha(Pilha* p){
    Pilha * copia = pilha_cria();
    copia =p;
    return copia;
}

