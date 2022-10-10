#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef struct lista2 Lista2;

Lista2* lst_insere(Lista2 *l, int v);

void lst_imprime(Lista2*l);

Lista2* lst_busca(Lista2 *l, int v);

Lista2* lst_retira(Lista2 *l, int v);

#endif // LISTA_H_INCLUDED
