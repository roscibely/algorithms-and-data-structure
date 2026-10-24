/*
 * inventario.c - TAD Inventario (implementação)
 * ---------------------------------------------------------------
 * Aqui, e SOMENTE aqui, a struct inventario é definida por completo.
 * Nenhum outro arquivo do programa enxerga estes campos: para o
 * resto do mundo, "Inventario" é apenas um ponteiro opaco.
 *
 * A representação escolhida é um vetor de ponteiros para Entidade
 * (igual à atividade5), mas isso é um detalhe de implementação --
 * poderia ser trocado por uma lista encadeada sem que atividade9.c
 * precisasse mudar uma linha sequer.
 */

#include <stdlib.h>
#include "inventario.h"

struct inventario {
    Entidade **vetor;      // vetor de ponteiros para Entidade, alocado dinamicamente
    int        total;
    int        capacidade;
};

Inventario *inventarioCriar(int capacidade) {
    Inventario *inv = (Inventario *)malloc(sizeof(Inventario));
    if (inv == NULL) return NULL;

    inv->vetor = (Entidade **)malloc(capacidade * sizeof(Entidade *));
    inv->total = 0;
    inv->capacidade = capacidade;
    return inv;
}

void inventarioDestruir(Inventario *inv) {
    if (inv == NULL) return;

    for (int i = 0; i < inv->total; i++) {
        free(inv->vetor[i]); // libera cada entidade
    }
    free(inv->vetor);        // libera o vetor de ponteiros
    free(inv);                // libera o próprio inventário
}

bool inventarioAdicionar(Inventario *inv, Entidade *e) {
    if (inv == NULL || e == NULL || inv->total >= inv->capacidade) return false;

    inv->vetor[inv->total] = e;
    inv->total++;
    return true;
}

void inventarioRemover(Inventario *inv, int indice) {
    if (inv == NULL || indice < 0 || indice >= inv->total) return;

    free(inv->vetor[indice]);
    inv->vetor[indice] = inv->vetor[inv->total - 1];
    inv->total--;
}

Entidade *inventarioObter(Inventario *inv, int indice) {
    if (inv == NULL || indice < 0 || indice >= inv->total) return NULL;
    return inv->vetor[indice];
}

int inventarioTotal(Inventario *inv) {
    if (inv == NULL) return 0;
    return inv->total;
}
