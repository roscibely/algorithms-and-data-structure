#include <stdio.h>

int mult(int valor1, int valor2) {
    return valor1 * valor2;
}

int main() {
    int (*p)(int, int);
    p = mult;
    printf("%d", p(2, 3));
    return 0;
}


