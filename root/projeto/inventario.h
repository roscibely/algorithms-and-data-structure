/*
 * inventario.h - TAD Inventario (interface opaca)
 * ---------------------------------------------------------------
 * Diferente de entidade.h (um módulo comum, onde a struct Entidade
 * é visível para quem inclui o cabeçalho), aqui o tipo Inventario é
 * um TIPO ABSTRATO DE DADOS (TAD): sua struct é declarada apenas
 * como um tipo INCOMPLETO ("typedef struct inventario Inventario;"),
 * sem nenhum campo visível neste arquivo.
 *
 * Quem usa este cabeçalho só enxerga um "Inventario *" e só pode
 * manipulá-lo através das funções abaixo -- nunca acessando campos
 * diretamente (nem poderia: o compilador não conhece o tamanho nem
 * os campos da struct fora de inventario.c). Isso é ENCAPSULAMENTO:
 * a representação interna (hoje um vetor de ponteiros) pode mudar
 * no futuro (por exemplo, para uma lista encadeada) sem que nenhum
 * programa que usa este TAD precise ser alterado.
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "entidade.h"

typedef struct inventario Inventario; // tipo opaco: struct definida só em inventario.c

Inventario *inventarioCriar(int capacidade);
void        inventarioDestruir(Inventario *inv);

bool        inventarioAdicionar(Inventario *inv, Entidade *e);
void        inventarioRemover(Inventario *inv, int indice);

Entidade   *inventarioObter(Inventario *inv, int indice);
int         inventarioTotal(Inventario *inv);

#endif
