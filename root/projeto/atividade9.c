/*
 * TAD - Tipo Abstrato de Dados com raylib
 * ---------------------------------------------------------------
 * Atividade final: evolução da atividade8. A coleção de entidades,
 * que na atividade8 era um vetor de ponteiros manipulado diretamente
 * pelo programa principal (`vetorEntidades[i]`, `totalEntidades--`),
 * agora é um TAD opaco: Inventario (inventario.h + inventario.c).
 *
 * Este arquivo NUNCA acessa a struct interna do Inventario -- só
 * conhece o ponteiro opaco `Inventario *` e as funções da sua
 * interface pública (inventarioCriar, inventarioAdicionar, ...).
 * Se amanhã a professora reimplementar o Inventario por dentro
 * (trocar o vetor por uma lista encadeada, por exemplo), este
 * arquivo continua compilando e funcionando sem nenhuma alteração.
 *
 * Conceitos praticados:
 *   - TAD (Tipo Abstrato de Dados): struct opaca + funções públicas
 *   - encapsulamento / ocultação de informação
 *   - diferença entre um MÓDULO comum (entidade.h, struct visível)
 *     e um TAD de verdade (inventario.h, struct escondida)
 *   - revisão geral: ponteiros, alocação dinâmica, struct, enum,
 *     union e vetor de ponteiros para struct (agora escondido)
 *
 * Compilar (Linux, com raylib instalada):
 *   gcc atividade9.c entidade.c inventario.c -o atividade9 -lraylib -lm -lpthread -ldl -lrt -lX11
 */

#include "raylib.h"
#include "entidade.h"
#include "inventario.h"
#include <stdlib.h>
#include <time.h>

#define LARGURA_JANELA  800
#define ALTURA_JANELA   600
#define MAX_ENTIDADES   30
#define TOTAL_INIMIGOS  5
#define TOTAL_ITENS     6
#define DANO_TIRO       20

int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(LARGURA_JANELA, ALTURA_JANELA, "Atividade 9 - TAD (Tipo Abstrato de Dados)");
    SetTargetFPS(60);

    Inventario *inventario = inventarioCriar(MAX_ENTIDADES);

    // índice 0 do inventário é sempre o jogador
    Entidade *jogador = entidadeCriar(ENTIDADE_JOGADOR,
                                      (Vector2){ LARGURA_JANELA / 2.0f, ALTURA_JANELA / 2.0f });
    inventarioAdicionar(inventario, jogador);

    for (int i = 0; i < TOTAL_INIMIGOS; i++) {
        Vector2 pos = { GetRandomValue(30, LARGURA_JANELA - 30), GetRandomValue(30, ALTURA_JANELA - 30) };
        inventarioAdicionar(inventario, entidadeCriar(ENTIDADE_INIMIGO, pos));
    }
    for (int i = 0; i < TOTAL_ITENS; i++) {
        Vector2 pos = { GetRandomValue(30, LARGURA_JANELA - 30), GetRandomValue(30, ALTURA_JANELA - 30) };
        inventarioAdicionar(inventario, entidadeCriar(ENTIDADE_ITEM, pos));
    }

    int pontuacao = 0;

    while (!WindowShouldClose()) {

        float vel = 250.0f * GetFrameTime();
        if (IsKeyDown(KEY_RIGHT)) jogador->pos.x += vel;
        if (IsKeyDown(KEY_LEFT))  jogador->pos.x -= vel;
        if (IsKeyDown(KEY_UP))    jogador->pos.y -= vel;
        if (IsKeyDown(KEY_DOWN))  jogador->pos.y += vel;

        // percorre o inventário só através da sua interface pública
        for (int i = 1; i < inventarioTotal(inventario); i++) {
            Entidade *e = inventarioObter(inventario, i);
            if (!entidadeColidiu(jogador, e)) continue;

            if (e->tipo == ENTIDADE_ITEM) {
                pontuacao += e->extra.valor;
                inventarioRemover(inventario, i);
                i--;
            } else if (e->tipo == ENTIDADE_INIMIGO) {
                entidadeAplicarDano(jogador, e->extra.dano);
            }
        }

        if (IsKeyPressed(KEY_SPACE)) {
            for (int i = 1; i < inventarioTotal(inventario); i++) {
                Entidade *e = inventarioObter(inventario, i);
                if (e->tipo != ENTIDADE_INIMIGO) continue;
                if (!entidadeColidiu(jogador, e)) {
                    entidadeAplicarDano(e, DANO_TIRO);
                    if (e->vida <= 0) inventarioRemover(inventario, i);
                    break;
                }
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < inventarioTotal(inventario); i++) {
                entidadeDesenhar(inventarioObter(inventario, i));
            }

            DrawText(TextFormat("Vida: %d   Pontuacao: %d", jogador->vida, pontuacao), 10, 10, 22, DARKGRAY);
            DrawText(TextFormat("Entidades no inventario: %d", inventarioTotal(inventario)), 10, 34, 18, GRAY);
            DrawText("Setas movem | ESPACO atira | ESC sai", 10, ALTURA_JANELA - 25, 16, GRAY);

        EndDrawing();
    }

    inventarioDestruir(inventario); // uma única chamada libera tudo (entidades + vetor interno + struct)

    CloseWindow();
    return 0;
}
