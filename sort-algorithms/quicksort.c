// implementar o algoritmo de ordenação quicksort

#include <stdio.h>

void quickSort(int *vetor, int inicio, int fim) {
    int i, j, pivo, aux;
    i = inicio;
    j = fim - 1;
    pivo = vetor[(inicio + fim) / 2];
    while (i <= j) {
        while (vetor[i] < pivo && i < fim) {
            i++;
        }
        while (vetor[j] > pivo && j > inicio) {
            j--;
        }
        if (i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if (j > inicio) {
        quickSort(vetor, inicio, j + 1);
    }
    if (i < fim) {
        quickSort(vetor, i, fim);
    }
}

int main() {
    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    quickSort(vetor, 0, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf(" Ordenado com Quick Sort ");
    return 0;
}