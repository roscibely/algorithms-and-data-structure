/*
 * Módulos em C com raylib
 * ---------------------------------------------------------------
 * Evolução da atividade7: o tipo Entidade e suas operações básicas
 * (criar, colidir, desenhar, aplicar dano) foram extraídos para um
 * MÓDULO separado (entidade.h + entidade.c). Este arquivo (o
 * programa principal) apenas INCLUI o cabeçalho e usa a interface
 * pública do módulo -- ele não precisa saber COMO essas funções são
 * implementadas, apenas O QUE elas fazem.
 *
 * A coleção de entidades (o vetor de ponteiros e as funções que o
 * gerenciam) continua aqui no programa principal, pois é uma regra
 * específica DESTE jogo, e não do módulo genérico de Entidade.
 *
 * Conceitos praticados:
 *   - separação de um programa em múltiplos arquivos (.h e .c)
 *   - compilação separada + linkagem (cada .c vira um .o)
 *   - reuso de um módulo por diferentes programas
 *   - vetor de ponteiros para struct, enum, union e alocação
 *     dinâmica (revisão das atividades anteriores)
 *
 * Compilar (Linux, com raylib instalada):
 *   gcc atividade8.c entidade.c -o atividade8 -lraylib -lm -lpthread -ldl -lrt -lX11
 */

#include "raylib.h"
#include "entidade.h"
#include <stdlib.h>
#include <time.h>

#define LARGURA_JANELA  800
#define ALTURA_JANELA   600
#define MAX_ENTIDADES   30
#define TOTAL_INIMIGOS  5
#define TOTAL_ITENS     6
#define DANO_TIRO       20

Entidade *vetorEntidades[MAX_ENTIDADES];
int totalEntidades = 0;

void adicionarEntidade(Entidade *e) {
    if (e == NULL || totalEntidades >= MAX_ENTIDADES) return;
    vetorEntidades[totalEntidades] = e;
    totalEntidades++;
}

void removerEntidade(int indice) {
    if (indice < 0 || indice >= totalEntidades) return;
    free(vetorEntidades[indice]);
    vetorEntidades[indice] = vetorEntidades[totalEntidades - 1];
    totalEntidades--;
}

int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(LARGURA_JANELA, ALTURA_JANELA, "Atividade 8 - Modulos em C");
    SetTargetFPS(60);

    // todas as chamadas abaixo usam apenas a interface pública do módulo entidade.h
    Entidade *jogador = entidadeCriar(ENTIDADE_JOGADOR,
                                      (Vector2){ LARGURA_JANELA / 2.0f, ALTURA_JANELA / 2.0f });
    adicionarEntidade(jogador);

    for (int i = 0; i < TOTAL_INIMIGOS; i++) {
        Vector2 pos = { GetRandomValue(30, LARGURA_JANELA - 30), GetRandomValue(30, ALTURA_JANELA - 30) };
        adicionarEntidade(entidadeCriar(ENTIDADE_INIMIGO, pos));
    }
    for (int i = 0; i < TOTAL_ITENS; i++) {
        Vector2 pos = { GetRandomValue(30, LARGURA_JANELA - 30), GetRandomValue(30, ALTURA_JANELA - 30) };
        adicionarEntidade(entidadeCriar(ENTIDADE_ITEM, pos));
    }

    int pontuacao = 0;

    while (!WindowShouldClose()) {

        float vel = 250.0f * GetFrameTime();
        if (IsKeyDown(KEY_RIGHT)) jogador->pos.x += vel;
        if (IsKeyDown(KEY_LEFT))  jogador->pos.x -= vel;
        if (IsKeyDown(KEY_UP))    jogador->pos.y -= vel;
        if (IsKeyDown(KEY_DOWN))  jogador->pos.y += vel;

        for (int i = 1; i < totalEntidades; i++) {
            Entidade *e = vetorEntidades[i];
            if (!entidadeColidiu(jogador, e)) continue;

            if (e->tipo == ENTIDADE_ITEM) {
                pontuacao += e->extra.valor;
                removerEntidade(i);
                i--;
            } else if (e->tipo == ENTIDADE_INIMIGO) {
                entidadeAplicarDano(jogador, e->extra.dano);
            }
        }

        if (IsKeyPressed(KEY_SPACE)) {
            for (int i = 1; i < totalEntidades; i++) {
                Entidade *e = vetorEntidades[i];
                if (e->tipo != ENTIDADE_INIMIGO) continue;
                if (!entidadeColidiu(jogador, e)) {
                    entidadeAplicarDano(e, DANO_TIRO);
                    if (e->vida <= 0) removerEntidade(i);
                    break;
                }
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < totalEntidades; i++) {
                entidadeDesenhar(vetorEntidades[i]);
            }

            DrawText(TextFormat("Vida: %d   Pontuacao: %d", jogador->vida, pontuacao), 10, 10, 22, DARKGRAY);
            DrawText("Setas movem | ESPACO atira | ESC sai", 10, ALTURA_JANELA - 25, 16, GRAY);

        EndDrawing();
    }

    for (int i = 0; i < totalEntidades; i++) free(vetorEntidades[i]);

    CloseWindow();
    return 0;
}
