#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *ant;
    struct lista *prox;
}Lista;

Lista * insere(Lista *l, int v){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;
    novo->ant = l->ant;
    l->ant->prox = novo;
    return novo;
}

void imprime(Lista*l){
    Lista *p=l;
    if(p!=NULL) do{
        printf("%d \n", p->info);
        p=p->prox;
    }while(p!=l);
}
Lista* busca(Lista *l, int v){

    Lista *p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->info ==v)
			return p;
    }
    return NULL;

}
Lista* retira(Lista *l, int v){
    Lista* p = busca(l,v);
    if(p==NULL) return l;
    if(p==l){ /*Inicio*/
        l=p->prox;
        l->ant->prox=l;
    }
    else{
        p->ant->prox = p->prox;
        p->prox->ant=p->ant;}
    printf("%d \n", p->info);
    free(p);
    return l;
}


int main (void){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l = insere(l,5);
    l = insere(l,4);
    l = insere(l,8);
    l = insere(l,0);
    l = retira(l, 0);

  /* Lista *p =l;
    do{
             printf("%d \n", p->info);
             p=p->prox;
             }while(p!=l);*/




return 0;
}
