#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


typedef struct lista{
    float info;
    struct lista *prox;
}Lista;

struct fila{
    Lista *ini;
    Lista *fim;
};

Fila* fila_cria(void){
    Fila * f = (Fila*) malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void fila_insere(Fila * f, float v){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = NULL;
    if(f->fim!=NULL)
        f->fim->prox = novo;
    else{
       	f->ini= novo;
    }
    f->fim = novo;

}

float fila_retira(Fila *f){
    if (f->ini==NULL){
        printf("Fila vazia.\n");
        exit(1);
    }
    float v = f->ini->info;
    f->ini= f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    return v;
}
/*
ou
 Lista *t
 float v;
 t= f->ini;
 v=t->info;
 f->ini = t->prox;
 if(f->ini==NULL)
    f->fim=NULL;
 free(t);
 return v;
 */

int fila_vaiza(Fila *f){
	return (f->ini==NULL);
}

void fila_imprime(Fila *f){
	Lista *p;
	for(p=f->ini; p!=NULL; p=p->prox){
		printf(" Info = %.2f \n", p->info);
	}
}

void fila_libera(Fila *f){
	Lista *p = f->ini;
	while(p!=NULL){
		Lista* t = p->prox;
		free(p);
		p = t;
	}
	free(f);
}

void fila_fura(Fila *f, float v){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = f->ini;
    f->ini = novo;
}

void inv(Fila* x){
    Lista* t, *y, *r;
    r = NULL;
    y = x->ini;
    while (y!=NULL) {
       t = y->prox;
       y->prox = r;
       r = y;
       y = t;
    }
    x->ini = r;
}
