#include <stdio.h>
#include <stdlib.h>
#include "..\listasEncadeadas\lista.c" // Inclui o arquivo lista.c onde consta a TAD listas



Lista* retira(Lista* l, int v) {
    Lista* ant = NULL;
    Lista* p = l;
    do{
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
        return l;

    if (ant == NULL)
        l = p->prox;

    else
        ant->prox = p->prox;
    free(p);
    p = l;
    }while(p!=NULL);
    return l;
}


int main(void){
    Lista * l = NULL;
    l =lst_insere(l, 6);
    l =lst_insere(l, 6);
    l =lst_insere(l, 5);
    l =lst_insere(l, 3);
    l =lst_insere(l, 6);
    l = retira(l, 6);
    lst_imprime(l);
    return 0;
}
