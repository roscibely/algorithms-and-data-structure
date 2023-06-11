#ifndef FILA_LISTA_H_INCLUDED
#define FILA_LISTA_H_INCLUDED

typedef struct fila Fila;

Fila* fila_cria(void);

void fila_insere(Fila * f, float v);

float fila_retira(Fila *f);

int fila_vaiza(Fila *f);

void fila_libera(Fila *f);

void fila_imprime(Fila *f);

void inv(Fila* x);


#endif // FILA_LISTA_H_INCLUDED
