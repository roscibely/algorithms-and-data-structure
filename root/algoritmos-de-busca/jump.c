// Algoritmo Jump search (busca pulo)

#include <stdio.h>

int buscaPulo(int *vetor, int tamanho, int valor) {
    int i = 0;
    int pulo = 2;
    while (i < tamanho) {
        if (vetor[i] == valor) {
            return i;
        } else if (vetor[i] > valor) {
            int j;
            for (j = i - pulo; j < i; j++) {
                if (vetor[j] == valor) {
                    return j;
                }
            }
            return -1;
        }
        i += pulo;
    }
    return -1;
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(int);
    int valor = 5;
    int posicao = buscaPulo(vetor, tamanho, valor);
    if (posicao == -1) {
        printf("Valor não encontrado");
    } else {
        printf("Valor encontrado na posição %d", posicao);
    }
    return 0;
}