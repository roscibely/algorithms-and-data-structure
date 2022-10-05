#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	int info;
	struct lista*prox;
};


Lista* lst_cria(void){
	return NULL;
}

Lista* lst_insere(Lista* l, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = l;
	return novo;

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */

}

int lst_vazia(Lista *l){
	return (l==NULL);
}

void lst_imprime(Lista*l){

	Lista*p;
	for(p=l; p!=NULL; p=p->prox){
		printf(" Info = %d \n", p->info);
	}

}

Lista * lst_busca(int elemento, Lista* l){
	Lista * p;
	for(p=l; p!=NULL; p=p->prox){
		if(p->prox ==elemento)
			return p;
	}

	return NULL;

}

Lista * lst_retira(Lista*l, int v){
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while(p->info!=v){
    	if (p==NULL)
        	return l; /* não achou: retorna lista original */
        ant = p;
        p = p->prox;
            /* verifica se achou elemento */

    }
    /* retira elemento */
    if (ant==NULL)
    /* retira elemento do inicio */
        l = p->prox;
    else
    /* retira elemento do meio da lista */
        ant->prox = p->prox;
    free(p);
    return l;
}

void lst_libera(Lista* l){
    Lista* p = l;
    Lista* t;
    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;

    }
}



Lista* lst_insere_ordenada(Lista * l, int v){
	Lista * novo;
	Lista * ant = NULL;
	Lista * p =l;
	while(p!=NULL && p->info<v){
		ant = p;
		p = p->prox;

	}
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	if(ant ==NULL){
		novo->prox = l;
		l = novo;
	}
	else {
		novo->prox = ant-> prox;
		ant->prox = novo;
	}
	return l;
}


void lst_imprime_recursiva(Lista*l){

	if(l!=NULL){
		printf("Info = %d \n", l->info);
		lst_imprime_recursiva(l->prox);
	}
}

void lst_libera_recursiva(Lista* l){
    if(l!=NULL){
	   lst_libera_recursiva(l->prox);
	   free(l);
	}
}

Lista * lst_retira_recursiva(Lista*l, int v){

	if(l!=NULL){
	if(l->info==v){
        Lista * p = l;
        l=l->prox;
		free(p);
	}
	else
		l->prox = lst_retira_recursiva(l->prox, v);
	}
	return l;
}


