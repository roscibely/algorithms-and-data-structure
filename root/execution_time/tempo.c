#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio = clock();
    // Executar o algoritmo
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; //milisegundos
    printf("Tempo de execucao: %.50f\n", tempo);
    return 0;
}