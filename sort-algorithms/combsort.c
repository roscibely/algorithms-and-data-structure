// Implementar o algortimo de ordenação comb sort

#include <stdio.h>

void combSort(int *vetor, int tamanho) {
    int gap = tamanho;
    int troca = 1;
    int aux;
    while (gap > 1 || troca == 1) {
        if (gap > 1) {
            gap = gap / 1.3;
        }
        int i = 0;
        troca = 0;
        while (i + gap < tamanho) {
            if (vetor[i] > vetor[i + gap]) {
                aux = vetor[i];
                vetor[i] = vetor[i + gap];
                vetor[i + gap] = aux;
                troca = 1;
            }
            i++;
        }
    }
}

int main() {
    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    combSort(vetor, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf(" Ordenado com Comb Sort ");
    return 0;
}