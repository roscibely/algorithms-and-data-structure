/*
 * Complexidade de Algoritmos: Busca e Ordenação com raylib
 * ---------------------------------------------------------------
 * Evolução da atividade6: agora o programa mantém um vetor dinâmico
 * de placares (struct Placar) e permite comparar, na prática, o
 * CUSTO (número de comparações) de diferentes algoritmos de busca
 * e ordenação -- o conceito central de complexidade de algoritmos.
 *
 * O vetor de placares é desenhado como barras verticais (altura =
 * pontuação), permitindo enxergar visualmente o efeito da ordenação.
 *
 * Conceitos praticados:
 *   - complexidade de algoritmos (contagem de comparações/trocas)
 *   - ordenação: bubble sort, O(n²) no pior caso
 *   - busca sequencial, O(n), funciona em vetor desordenado
 *   - busca binária, O(log n), exige o vetor ordenado
 *   - reaproveita ponteiros, alocação dinâmica e struct das
 *     atividades anteriores
 *
 * Compilar (Linux, com raylib instalada):
 *   gcc atividade7.c -o atividade7 -lraylib -lm -lpthread -ldl -lrt -lX11
 */

#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define LARGURA_JANELA  800
#define ALTURA_JANELA   600
#define TOTAL_PLACARES  15
#define PONTUACAO_MAX   100

typedef struct {
    char nome[16];
    int  pontuacao;
} Placar;

Placar *criarPlacares(int quantidade) {
    Placar *placares = (Placar *)malloc(quantidade * sizeof(Placar));
    if (placares == NULL) return NULL;

    for (int i = 0; i < quantidade; i++) {
        Placar *p = (placares + i);
        TextCopy(p->nome, TextFormat("J%02d", i + 1));
        p->pontuacao = GetRandomValue(10, PONTUACAO_MAX);
    }
    return placares;
}

/* ---- ordenação: bubble sort contando comparações e trocas ---- */
void ordenarBubbleSort(Placar *vetor, int n, long *comparacoes, long *trocas) {
    *comparacoes = 0;
    *trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            (*comparacoes)++;
            if (vetor[j].pontuacao > vetor[j + 1].pontuacao) {
                Placar temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

/* ---- busca sequencial: O(n), funciona em qualquer ordem ---- */
int buscaSequencial(Placar *vetor, int n, int alvo, long *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (vetor[i].pontuacao == alvo) return i;
    }
    return -1;
}

/* ---- busca binária: O(log n), exige vetor ordenado ---- */
int buscaBinaria(Placar *vetor, int n, int alvo, long *comparacoes) {
    *comparacoes = 0;
    int inicio = 0, fim = n - 1;

    while (inicio <= fim) {
        (*comparacoes)++;
        int meio = (inicio + fim) / 2;

        if (vetor[meio].pontuacao == alvo) return meio;
        if (vetor[meio].pontuacao < alvo) inicio = meio + 1;
        else                              fim = meio - 1;
    }
    return -1;
}

void desenharBarras(Placar *vetor, int n, int indiceDestacado) {
    int larguraBarra = LARGURA_JANELA / n;

    for (int i = 0; i < n; i++) {
        int altura = vetor[i].pontuacao * 4;
        int x = i * larguraBarra;
        int y = ALTURA_JANELA - 60 - altura;

        Color cor = (i == indiceDestacado) ? LIME : SKYBLUE;
        DrawRectangle(x + 2, y, larguraBarra - 4, altura, cor);
        DrawText(TextFormat("%d", vetor[i].pontuacao), x + 4, y - 18, 12, DARKGRAY);
    }
}

int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(LARGURA_JANELA, ALTURA_JANELA, "Atividade 7 - Complexidade: Busca e Ordenacao");
    SetTargetFPS(60);

    Placar *placares = criarPlacares(TOTAL_PLACARES);
    bool ordenado = false;

    long comparacoes = 0, trocas = 0;
    int alvo = placares[GetRandomValue(0, TOTAL_PLACARES - 1)].pontuacao;
    int indiceEncontrado = -1;
    char resultado[96] = "Pressione Q para buscar (sequencial) ou W (binaria)";

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_O)) { // Ordena com bubble sort, contando comparações e trocas
            ordenarBubbleSort(placares, TOTAL_PLACARES, &comparacoes, &trocas);
            ordenado = true;
            indiceEncontrado = -1;
            TextCopy(resultado, TextFormat("Bubble sort: %ld comparacoes, %ld trocas (O(n^2))", comparacoes, trocas));
        }

        if (IsKeyPressed(KEY_N)) { // Sorteia um novo alvo dentre os valores existentes
            alvo = placares[GetRandomValue(0, TOTAL_PLACARES - 1)].pontuacao;
            indiceEncontrado = -1;
            TextCopy(resultado, TextFormat("Novo alvo sorteado: %d", alvo));
        }

        if (IsKeyPressed(KEY_Q)) { // Busca sequencial: funciona ordenado ou não, custo O(n)
            indiceEncontrado = buscaSequencial(placares, TOTAL_PLACARES, alvo, &comparacoes);
            TextCopy(resultado, TextFormat("Busca sequencial por %d: %ld comparacoes (O(n))", alvo, comparacoes));
        }

        if (IsKeyPressed(KEY_W)) { // Busca binária: só é confiável se o vetor estiver ordenado
            if (!ordenado) {
                TextCopy(resultado, "Ordene primeiro com O -- busca binaria exige vetor ordenado!");
            } else {
                indiceEncontrado = buscaBinaria(placares, TOTAL_PLACARES, alvo, &comparacoes);
                TextCopy(resultado, TextFormat("Busca binaria por %d: %ld comparacoes (O(log n))", alvo, comparacoes));
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            desenharBarras(placares, TOTAL_PLACARES, indiceEncontrado);

            DrawText(TextFormat("Alvo da busca: %d   Vetor ordenado: %s", alvo, ordenado ? "SIM" : "NAO"),
                      10, 10, 20, DARKGRAY);
            DrawText(resultado, 10, 34, 18, MAROON);
            DrawText("O ordena | N novo alvo | Q busca sequencial | W busca binaria | ESC sai",
                      10, ALTURA_JANELA - 25, 16, GRAY);

        EndDrawing();
    }

    free(placares);

    CloseWindow();
    return 0;
}
