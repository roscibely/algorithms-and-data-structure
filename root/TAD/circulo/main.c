#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"


int main() {
    Circulo* c = cria_circulo();
    printf("Area do circulo: %f\n", area_circulo(c));
    move_circulo(c, 10, 10);
    free(c); // Libera a memória alocada
    return 0;
}