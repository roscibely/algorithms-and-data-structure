#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
    int info;
    struct lista *prox;
}Lista;


Lista * ultimo(Lista *l){
    Lista * ultimo = NULL;
    Lista * p = l;
    while(p!=NULL){
        ultimo = p;
        p=p->prox;
    }
    return ultimo;
}

Lista * insere(Lista *l, int v){
    Lista * novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->info = v;
    novo->prox = l;
    return novo;
}

int main(void){
    Lista * l = NULL;
    l =insere(l, 6);
    l = insere(l, 4);
    l = insere(l, 3);
    l = insere(l, 0);
    l =ultimo(l);
    printf(" Valor do ultimo elemento da lista: %d \n", l->info);
    return 0;
}
