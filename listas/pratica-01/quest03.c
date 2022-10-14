#include <stdio.h>
#include <stdlib.h>
#include "..\listasEncadeadas\lista.c" // Inclui o arquivo lista.c onde consta a TAD listas


Lista* contatena(Lista* l1, Lista* l2){
        Lista * ant = NULL;
        Lista *p = l1;
        while(p!=NULL){
            ant = p;
            p=p->prox;
        }
        ant->prox = l2;
        return ant;
}

Lista * insere(Lista *l, int v){
    Lista * novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;
    return novo;
}

int main(void){
    Lista * l = NULL;
    l =insere(l, 6);
    Lista *L = insere(L, 0);
    L = contatena(l, L);
    lst_imprime(L);

    return 0;
}
