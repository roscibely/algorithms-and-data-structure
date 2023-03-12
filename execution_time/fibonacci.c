#include <stdio.h>
#include <time.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int fibonacci_iterativo(int n) {
    int f0 = 0;
    int f1 = 1;
    int fn = 0;
    int i;
    if (n == 0) {
        return f0;
    } else if (n == 1) {
        return f1;
    } else {
        for (i = 2; i <= n; i++) {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
        return fn;
    }
}

int main() {
    clock_t inicio = clock();
    int n = 40;
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; //milisegundos
    printf("Tempo de execucao: %.5f ms\n", tempo);

    inicio = clock();
    printf("Fibonacci(%d) = %d\n", n, fibonacci_iterativo(n));
    tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; //milisegundos
    printf("Tempo de execucao: %.5f ms\n", tempo);
    return 0;
}