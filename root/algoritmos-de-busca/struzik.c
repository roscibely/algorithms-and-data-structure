// Algoritmo de Busca exponencial (ou busca struzik/busca a galope)

#include <stdio.h>

int buscaExponencial(int *vetor, int tamanho, int valor) { // Busca exponencial porque o tamanho do intervalo é dobrado a cada iteração
    int i = 1; 
    while (i < tamanho && vetor[i] <= valor) { // Encontra o intervalo onde o valor pode estar
        i *= 2; // Dobro do tamanho do intervalo
    }
    int j;
    for (j = i / 2; j < i; j++) { // Busca linear no intervalo
        if (vetor[j] == valor) { // Se o valor for encontrado, retorna a posição
            return j;
        }
    }
    return -1; // Se o valor não for encontrado, retorna -1
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