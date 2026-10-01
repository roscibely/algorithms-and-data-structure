/*
 * entidade.c - Módulo de Entidade (implementação)
 * ---------------------------------------------------------------
 * Implementa as funções declaradas em entidade.h. Este arquivo é
 * compilado separadamente e depois LINKADO ao programa principal:
 *
 *   gcc atividade8.c entidade.c -o atividade8 -lraylib -lm ...
 *
 * Cada arquivo .c é compilado para um .o (unidade de compilação);
 * o linker junta os .o's e resolve as chamadas de função entre eles.
 */

#include <stdlib.h>
#include <math.h>
#include "entidade.h"

Entidade *entidadeCriar(TipoEntidade tipo, Vector2 pos) {
    Entidade *e = (Entidade *)malloc(sizeof(Entidade));
    if (e == NULL) return NULL;

    e->tipo = tipo;
    e->pos  = pos;
    e->raio = (tipo == ENTIDADE_JOGADOR) ? 20.0f
            : (tipo == ENTIDADE_INIMIGO) ? 15.0f : 8.0f;

    switch (tipo) {
        case ENTIDADE_JOGADOR:
            e->vida = 100;
            e->cor  = BLUE;
            break;
        case ENTIDADE_INIMIGO:
            e->vida       = 40;
            e->cor        = MAROON;
            e->extra.dano = GetRandomValue(5, 15);
            break;
        case ENTIDADE_ITEM:
            e->vida        = 1;
            e->cor         = GOLD;
            e->extra.valor = GetRandomValue(5, 20);
            break;
    }
    return e;
}

bool entidadeColidiu(Entidade *a, Entidade *b) {
    float dx = a->pos.x - b->pos.x;
    float dy = a->pos.y - b->pos.y;
    float distancia = sqrtf(dx * dx + dy * dy);
    return distancia <= (a->raio + b->raio);
}

void entidadeDesenhar(Entidade *e) {
    DrawCircleV(e->pos, e->raio, e->cor);
    if (e->tipo == ENTIDADE_INIMIGO) {
        DrawText(TextFormat("%d", e->vida), e->pos.x - 8, e->pos.y - 26, 14, BLACK);
    }
}

void entidadeAplicarDano(Entidade *e, int dano) {
    if (e == NULL) return;

    e->vida -= dano;
    if (e->vida < 0) e->vida = 0;
}
