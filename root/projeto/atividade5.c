/*
 * Vetor de Ponteiros para Struct com raylib
 * ---------------------------------------------------------------
 * Atividade final: reúne todos os conceitos das atividades
 * anteriores em um pequeno "sistema de entidades" (jogador,
 * inimigos e itens).
 *
 * A diferença central para a atividade4 é a forma como a coleção é
 * guardada: em vez de um vetor de struct (bloco contíguo), aqui
 * temos um VETOR DE PONTEIROS PARA STRUCT (Entidade *vetor[N]).
 * Cada posição do vetor guarda apenas um ENDEREÇO; a struct em si
 * fica em um bloco de memória alocado individualmente com malloc.
 * Isso permite, por exemplo, remover uma entidade "no meio" do
 * vetor apenas trocando ponteiros (rápido), sem precisar mover
 * structs inteiras na memória.
 *
 * Conceitos praticados (revisão de todas as atividades):
 *   - ponteiros e aritmética de ponteiros
 *   - alocação dinâmica (malloc/free) de cada struct individual
 *   - struct (Entidade) com campos variados
 *   - enum (TipoEntidade) para diferenciar jogador/inimigo/item
 *   - union (ExtraEntidade) para guardar, no mesmo espaço, o dano
 *     de um inimigo OU o valor de um item, conforme o TipoEntidade
 *   - ponteiro para struct (Entidade *) manipulado por funções
 *   - vetor de ponteiros para struct (Entidade *vetor[N])
 *
 * Compilar (Linux, com raylib instalada):
 *   gcc atividade5.c -o atividade5 -lraylib -lm -lpthread -ldl -lrt -lX11
 */

#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LARGURA_JANELA  800
#define ALTURA_JANELA   600
#define RAIO_JOGADOR    20.0f
#define MAX_ENTIDADES   30
#define TOTAL_INIMIGOS  5
#define TOTAL_ITENS     6

typedef enum {
    ENTIDADE_JOGADOR,
    ENTIDADE_INIMIGO,
    ENTIDADE_ITEM
} TipoEntidade;

/* union: só um destes campos faz sentido por vez, dependendo do tipo */
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

// vetor de PONTEIROS para struct: cada posição aponta para um bloco
// alocado individualmente com malloc (não é um bloco contíguo único)
Entidade *vetorEntidades[MAX_ENTIDADES];
int totalEntidades = 0;

/* aloca UMA entidade individualmente e devolve o ponteiro para ela */
Entidade *criarEntidade(TipoEntidade tipo, Vector2 pos) {
    Entidade *e = (Entidade *)malloc(sizeof(Entidade));
    if (e == NULL) return NULL;

    e->tipo  = tipo;
    e->pos   = pos;
    e->raio  = (tipo == ENTIDADE_JOGADOR) ? RAIO_JOGADOR
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

/* adiciona um ponteiro de entidade no vetor de ponteiros */
void adicionarEntidade(Entidade *e) {
    if (e == NULL || totalEntidades >= MAX_ENTIDADES) return;
    vetorEntidades[totalEntidades] = e;
    totalEntidades++;
}

/* remove a entidade do índice informado: libera a memória dela e
 * substitui a posição vaga pelo ÚLTIMO ponteiro do vetor. Como o
 * vetor guarda apenas ponteiros, isso é apenas uma troca de
 * endereços -- nenhuma struct precisa ser copiada ou movida. */
void removerEntidade(int indice) {
    if (indice < 0 || indice >= totalEntidades) return;

    free(vetorEntidades[indice]);              // libera o bloco alocado
    vetorEntidades[indice] = vetorEntidades[totalEntidades - 1];
    totalEntidades--;
}

bool colidiu(Entidade *a, Entidade *b) {
    float dx = a->pos.x - b->pos.x;
    float dy = a->pos.y - b->pos.y;
    float distancia = sqrtf(dx * dx + dy * dy);
    return distancia <= (a->raio + b->raio);
}

void desenharEntidade(Entidade *e) {
    DrawCircleV(e->pos, e->raio, e->cor);
    if (e->tipo == ENTIDADE_INIMIGO) {
        DrawText(TextFormat("%d", e->vida), e->pos.x - 8, e->pos.y - 26, 14, BLACK);
    }
}

int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(LARGURA_JANELA, ALTURA_JANELA, "Atividade 5 - Vetor de Ponteiros para Struct");
    SetTargetFPS(60);

    // índice 0 do vetor de ponteiros é sempre o jogador
    Entidade *jogador = criarEntidade(ENTIDADE_JOGADOR,
                                      (Vector2){ LARGURA_JANELA / 2.0f, ALTURA_JANELA / 2.0f });
    adicionarEntidade(jogador);

    for (int i = 0; i < TOTAL_INIMIGOS; i++) {
        Vector2 pos = { GetRandomValue(30, LARGURA_JANELA - 30), GetRandomValue(30, ALTURA_JANELA - 30) };
        adicionarEntidade(criarEntidade(ENTIDADE_INIMIGO, pos));
    }
    for (int i = 0; i < TOTAL_ITENS; i++) {
        Vector2 pos = { GetRandomValue(30, LARGURA_JANELA - 30), GetRandomValue(30, ALTURA_JANELA - 30) };
        adicionarEntidade(criarEntidade(ENTIDADE_ITEM, pos));
    }

    int pontuacao = 0;

    while (!WindowShouldClose()) {

        float vel = 250.0f * GetFrameTime();
        if (IsKeyDown(KEY_RIGHT)) jogador->pos.x += vel;
        if (IsKeyDown(KEY_LEFT))  jogador->pos.x -= vel;
        if (IsKeyDown(KEY_UP))    jogador->pos.y -= vel;
        if (IsKeyDown(KEY_DOWN))  jogador->pos.y += vel;

        // percorre o vetor de ponteiros: cada vetorEntidades[i] já é um "Entidade *"
        for (int i = 1; i < totalEntidades; i++) {
            Entidade *e = vetorEntidades[i];
            if (!colidiu(jogador, e)) continue;

            if (e->tipo == ENTIDADE_ITEM) {
                pontuacao += e->extra.valor;
                removerEntidade(i);
                i--; // a posição i agora tem outra entidade (a que veio do final)
            } else if (e->tipo == ENTIDADE_INIMIGO) {
                jogador->vida -= e->extra.dano;
                if (jogador->vida < 0) jogador->vida = 0;
            }
        }

        if (IsKeyPressed(KEY_SPACE)) {
            // atira no primeiro inimigo vivo encontrado no vetor de ponteiros
            for (int i = 1; i < totalEntidades; i++) {
                Entidade *e = vetorEntidades[i];
                if (e->tipo != ENTIDADE_INIMIGO) continue;
                if (!colidiu(jogador, e) && e->raio > 0) {
                    e->vida -= 20;
                    if (e->vida <= 0) {
                        removerEntidade(i);
                    }
                    break;
                }
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < totalEntidades; i++) {
                desenharEntidade(vetorEntidades[i]);
            }

            DrawText(TextFormat("Vida: %d   Pontuacao: %d", jogador->vida, pontuacao), 10, 10, 22, DARKGRAY);
            DrawText(TextFormat("Entidades ativas: %d", totalEntidades), 10, 34, 18, GRAY);
            DrawText("Setas movem | ESPACO atira | ESC sai", 10, ALTURA_JANELA - 25, 16, GRAY);

        EndDrawing();
    }

    // libera cada bloco alocado individualmente (cada ponteiro do vetor)
    for (int i = 0; i < totalEntidades; i++) {
        free(vetorEntidades[i]);
    }

    CloseWindow();
    return 0;
}
