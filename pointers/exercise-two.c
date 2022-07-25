#include <stdio.h>

int main(void) {

    int x, *p;
    x = 100;
    p = &x;
    
    printf("Valor de p = %p\tValor de *p = %d", p, *p);

    return 0;
}
