// Algoritmo de busca binária

#include <stdio.h>

int buscaBinaria(int *vetor, int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(int);
    int valor = 5;
    int posicao = buscaBinaria(vetor, tamanho, valor);
    if (posicao == -1) {
        printf("Valor não encontrado");
    } else {
        printf("Valor encontrado na posição %d", posicao);
    }
    return 0;
}