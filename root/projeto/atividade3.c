/*
 * Union + Enum + Struct + Alocação Dinâmica com raylib
 * ---------------------------------------------------------------
 * Evolução da atividade2: agora os itens coletáveis podem ser de
 * dois tipos bem diferentes (uma ARMA ou uma POÇÃO) e usam uma
 * UNION para guardar, no mesmo espaço de memória, o dado específico
 * de cada tipo. O campo enum funciona como "tag" que diz qual campo
 * da union deve ser lido (padrão conhecido como "tagged union").
 *
 * Conceitos praticados:
 *   - union (DadosItem): arma e poção nunca existem ao mesmo tempo,
 *     então compartilham o mesmo espaço de memória
 *   - enum (TipoItem) usado como "tag" para saber qual campo da
 *     union é válido naquele momento
 *   - struct que combina enum + union + outros campos
 *   - malloc / free de um vetor dinâmico de struct
 *   - ponteiro para struct (Item *, Jogador *) passado para funções
 *     que alteram o dado original
 *
 * Compilar (Linux, com raylib instalada):
 *   gcc atividade3.c -o atividade3 -lraylib -lm -lpthread -ldl -lrt -lX11
 */

#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define LARGURA_JANELA 800
#define ALTURA_JANELA  600
#define RAIO_JOGADOR   20.0f
#define TOTAL_ITENS    10

typedef enum {
    ITEM_ARMA,
    ITEM_POCAO
} TipoItem;

typedef struct {
    float dano;
    int   alcance;
} DadosArma;

typedef struct {
    int cura;
} DadosPocao;

/* union: em cada Item só um destes dois campos é válido por vez,
 * e isso é decidido pelo campo "tipo" (enum) da struct Item */
typedef union {
    DadosArma  arma;
    DadosPocao pocao;
} DadosItem;

typedef struct {
    Vector2   pos;
    float     raio;
    TipoItem  tipo;
    DadosItem dados;
    bool      coletado;
} Item;

typedef struct {
    Vector2 pos;
    float   raio;
    int     vida;
    float   dano;
} Jogador;

/* cria o vetor dinâmico de itens sorteando tipo e preenchendo a
 * union de acordo com o tipo sorteado */
Item *criarItens(int quantidade) {
    Item *itens = (Item *)malloc(quantidade * sizeof(Item));
    if (itens == NULL) return NULL;

    for (int i = 0; i < quantidade; i++) {
        Item *it = (itens + i);
        it->pos      = (Vector2){ GetRandomValue(30, LARGURA_JANELA - 30),
                                   GetRandomValue(30, ALTURA_JANELA - 30) };
        it->raio     = 12.0f;
        it->coletado = false;
        it->tipo     = (TipoItem)GetRandomValue(ITEM_ARMA, ITEM_POCAO);

        if (it->tipo == ITEM_ARMA) {
            it->dados.arma.dano    = (float)GetRandomValue(2, 8);
            it->dados.arma.alcance = GetRandomValue(1, 3);
        } else {
            it->dados.pocao.cura = GetRandomValue(10, 30);
        }
    }
    return itens;
}

/* recebe PONTEIROS para o jogador e para o item: aplica o efeito do
 * item lendo o campo correto da union de acordo com o enum "tipo" */
void aplicarItem(Jogador *j, Item *item) {
    switch (item->tipo) {
        case ITEM_ARMA:
            j->dano += item->dados.arma.dano;
            break;
        case ITEM_POCAO:
            j->vida += item->dados.pocao.cura;
            break;
    }
    item->coletado = true;
}

bool colidiu(Vector2 a, float raioA, Vector2 b, float raioB) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float distancia2 = dx * dx + dy * dy;
    float somaRaios2 = (raioA + raioB) * (raioA + raioB);
    return distancia2 <= somaRaios2;
}

void desenharItem(Item *item) {
    if (item->coletado) return;
    Color cor = (item->tipo == ITEM_ARMA) ? RED : GREEN;
    DrawCircleV(item->pos, item->raio, cor);
}

int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(LARGURA_JANELA, ALTURA_JANELA, "Atividade 3 - Union + Enum + Struct");
    SetTargetFPS(60);

    Jogador jogador = { { LARGURA_JANELA / 2.0f, ALTURA_JANELA / 2.0f }, RAIO_JOGADOR, 100, 5.0f };
    Item *itens = criarItens(TOTAL_ITENS); // vetor dinâmico de struct com union

    while (!WindowShouldClose()) {

        float vel = 250.0f * GetFrameTime();
        if (IsKeyDown(KEY_RIGHT)) jogador.pos.x += vel;
        if (IsKeyDown(KEY_LEFT))  jogador.pos.x -= vel;
        if (IsKeyDown(KEY_UP))    jogador.pos.y -= vel;
        if (IsKeyDown(KEY_DOWN))  jogador.pos.y += vel;

        for (int i = 0; i < TOTAL_ITENS; i++) {
            Item *it = (itens + i);
            if (!it->coletado && colidiu(jogador.pos, jogador.raio, it->pos, it->raio)) {
                aplicarItem(&jogador, it); // &jogador: ponteiro para struct
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < TOTAL_ITENS; i++) {
                desenharItem(itens + i);
            }

            DrawCircleV(jogador.pos, jogador.raio, BLUE);

            DrawText(TextFormat("Vida: %d   Dano: %.1f", jogador.vida, jogador.dano), 10, 10, 22, DARKGRAY);
            DrawText("Vermelho = arma (aumenta dano) | Verde = pocao (cura)", 10, 34, 18, GRAY);
            DrawText("Setas movem o jogador | ESC sai", 10, ALTURA_JANELA - 25, 16, GRAY);

        EndDrawing();
    }

    free(itens); // libera o vetor dinâmico

    CloseWindow();
    return 0;
}
