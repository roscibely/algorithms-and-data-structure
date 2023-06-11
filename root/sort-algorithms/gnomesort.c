// Implementar o algoritmo de ordenação gnome sort 

#include <stdio.h>

void gnomeSort(int *vetor, int tamanho) {
    int i = 0;
    int aux;
    while (i < tamanho) {
        if (i == 0 || vetor[i - 1] <= vetor[i]) {
            i++;
        } else {
            aux = vetor[i];
            vetor[i] = vetor[i - 1];
            vetor[i - 1] = aux;
            i--;
        }
    }
}

int main() {
    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    gnomeSort(vetor, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf(" Ordenado com Gnome Sort ");
    return 0;
}