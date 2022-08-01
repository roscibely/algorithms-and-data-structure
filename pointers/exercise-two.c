#include <stdio.h>

int main(void) {

    /* Função principal do programa */ 

    int x, *p; // Declara um inteiro x e um ponteiro p para int 
    x = 100;  // Atribui o valor 100 a x
    p = &x;  // p recebe o endereço de x
    
    printf("Valor de p = %p\tValor de *p = %d", p, *p);

    return 0;
}
