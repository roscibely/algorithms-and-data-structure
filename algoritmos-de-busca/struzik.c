// Algoritmo de Busca exponencial (ou busca struzik/busca a galope)

#include <stdio.h>

int buscaExponencial(int *vetor, int tamanho, int valor) {
    int i = 1;
    while (i < tamanho && vetor[i] <= valor) {
        i *= 2;
    }
    int j;
    for (j = i / 2; j < i; j++) {
        if (vetor[j] == valor) {
            return j;
        }
    }
    return -1;
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(int);
    int valor = 5;
    int posicao = buscaExponencial(vetor, tamanho, valor);
    if (posicao == -1) {
        printf("Valor não encontrado");
    } else {
        printf("Valor encontrado na posição %d", posicao);
    }
    return 0;
}