/*
 * Enum + Struct + Alocação Dinâmica com raylib
 * ---------------------------------------------------------------
 * Um jogador (retângulo) se move pela tela coletando moedas.
 * As moedas são um VETOR DINÂMICO de struct (malloc), e cada moeda
 * tem um campo do tipo enum que define sua raridade/cor/valor.
 *
 * Conceitos praticados (evolução da atividade1):
 *   - enum para representar categorias (TipoMoeda)
 *   - struct contendo um campo enum
 *   - malloc / free de um vetor de struct
 *   - ponteiro para struct (Moeda *) passado para funções que leem
 *     e alteram o dado original (ex.: marcar moeda como coletada)
 *   - aritmética de ponteiros para percorrer o vetor
 *
 * Compilar (Linux, com raylib instalada):
 *   gcc atividade2.c -o atividade2 -lraylib -lm -lpthread -ldl -lrt -lX11
 */

#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define LARGURA_JANELA 800
#define ALTURA_JANELA  600
#define RAIO_JOGADOR   20.0f
#define TOTAL_MOEDAS   15

// enum: cada valor representa uma categoria de moeda
typedef enum {
    MOEDA_BRONZE,
    MOEDA_PRATA,
    MOEDA_OURO
} TipoMoeda;

typedef struct {
    Vector2   pos;
    float     raio;
    TipoMoeda tipo;
    int       valor;
    bool      coletada;
} Moeda;

/* devolve a cor associada a cada tipo do enum */
Color corDaMoeda(TipoMoeda tipo) {
    switch (tipo) {
        case MOEDA_BRONZE: return (Color){160, 90, 40, 255};
        case MOEDA_PRATA:  return (Color){190, 190, 190, 255};
        case MOEDA_OURO:   return GOLD;
        default:           return WHITE;
    }
}

/* devolve o valor em pontos associado a cada tipo do enum */
int valorDaMoeda(TipoMoeda tipo) {
    switch (tipo) {
        case MOEDA_BRONZE: return 5;
        case MOEDA_PRATA:  return 10;
        case MOEDA_OURO:   return 25;
        default:           return 0;
    }
}

/* cria o vetor dinâmico de moedas, sorteando tipo e posição de cada uma */
Moeda *criarMoedas(int quantidade) {
    Moeda *moedas = (Moeda *)malloc(quantidade * sizeof(Moeda));
    if (moedas == NULL) return NULL;

    for (int i = 0; i < quantidade; i++) {
        Moeda *m = (moedas + i); // ponteiro para o i-ésimo elemento
        m->pos      = (Vector2){ GetRandomValue(30, LARGURA_JANELA - 30),
                                  GetRandomValue(30, ALTURA_JANELA - 30) };
        m->raio     = 10.0f;
        m->tipo     = (TipoMoeda)GetRandomValue(MOEDA_BRONZE, MOEDA_OURO);
        m->valor    = valorDaMoeda(m->tipo);
        m->coletada = false;
    }
    return moedas;
}

/* recebe um PONTEIRO para a moeda: marca como coletada diretamente no vetor original */
bool tentarColetar(Moeda *m, Vector2 posJogador, float raioJogador) {
    if (m->coletada) return false;

    float dx = m->pos.x - posJogador.x;
    float dy = m->pos.y - posJogador.y;
    float distancia = (dx * dx + dy * dy);
    float somaRaios = (m->raio + raioJogador) * (m->raio + raioJogador);

    if (distancia <= somaRaios) {
        m->coletada = true;
        return true;
    }
    return false;
}

void desenharMoeda(Moeda *m) {
    if (m->coletada) return;
    DrawCircleV(m->pos, m->raio, corDaMoeda(m->tipo));
}

int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(LARGURA_JANELA, ALTURA_JANELA, "Atividade 2 - Enum + Struct + Alocacao Dinamica");
    SetTargetFPS(60);

    Vector2 jogador = { LARGURA_JANELA / 2.0f, ALTURA_JANELA / 2.0f };
    int pontuacao = 0;

    Moeda *moedas = criarMoedas(TOTAL_MOEDAS); // vetor dinâmico de struct

    while (!WindowShouldClose()) {

        float vel = 250.0f * GetFrameTime();
        if (IsKeyDown(KEY_RIGHT)) jogador.x += vel;
        if (IsKeyDown(KEY_LEFT))  jogador.x -= vel;
        if (IsKeyDown(KEY_UP))    jogador.y -= vel;
        if (IsKeyDown(KEY_DOWN))  jogador.y += vel;

        // percorre o vetor com aritmética de ponteiros: (moedas + i)
        for (int i = 0; i < TOTAL_MOEDAS; i++) {
            Moeda *m = (moedas + i);
            if (tentarColetar(m, jogador, RAIO_JOGADOR)) {
                pontuacao += m->valor;
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < TOTAL_MOEDAS; i++) {
                desenharMoeda(moedas + i);
            }

            DrawCircleV(jogador, RAIO_JOGADOR, BLUE);

            DrawText(TextFormat("Pontuacao: %d", pontuacao), 10, 10, 22, DARKGRAY);
            DrawText("Setas movem o jogador | ESC sai", 10, ALTURA_JANELA - 25, 16, GRAY);

        EndDrawing();
    }

    free(moedas); // libera o vetor dinâmico

    CloseWindow();
    return 0;
}
