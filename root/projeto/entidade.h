/*
 * entidade.h - Módulo de Entidade (interface)
 * ---------------------------------------------------------------
 * Arquivo de CABEÇALHO: declara os tipos (enum, union, struct) e os
 * protótipos das funções do módulo "entidade". Qualquer arquivo .c
 * que precisar usar uma Entidade só precisa dar #include "entidade.h".
 *
 * Nesta atividade a struct Entidade ainda é visível para quem inclui
 * o cabeçalho (módulo comum) -- a diferença para um TAD (atividade9)
 * é que lá a struct fica ESCONDIDA, só acessível através de funções.
 */

#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "raylib.h"

typedef enum {
    ENTIDADE_JOGADOR,
    ENTIDADE_INIMIGO,
    ENTIDADE_ITEM
} TipoEntidade;

typedef union {
    int dano;   // usado quando tipo == ENTIDADE_INIMIGO
    int valor;  // usado quando tipo == ENTIDADE_ITEM
} ExtraEntidade;

typedef struct {
    TipoEntidade  tipo;
    Vector2       pos;
    float         raio;
    int           vida;
    Color         cor;
    ExtraEntidade extra;
} Entidade;

Entidade *entidadeCriar(TipoEntidade tipo, Vector2 pos);
bool      entidadeColidiu(Entidade *a, Entidade *b);
void      entidadeDesenhar(Entidade *e);
void      entidadeAplicarDano(Entidade *e, int dano);

#endif
