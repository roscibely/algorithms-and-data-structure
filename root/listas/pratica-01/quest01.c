#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

int maiores(Lista* l, int n){
    Lista * p;
    int k =0;
    for(p=l; p!=NULL; p=p->prox){
            if(p->info>n)
                k++;
    }
    return k;
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
    l =insere(l, 4);
    l = insere(l, 4);
    l = insere(l, 3);
    l = insere(l, 0);
    int b = 0;
    int a = maiores(l, b);
    printf("Existem %d elementos maiores que  %d \n", a, b);
    return 0;
}
