#include <stdio.h>

int main (void){

    /* Função principal do programa */ 

    int x, y, *p; // Declaração das variáveis x e y do tipo int e um ponteiro para int p.
    y = 0;     // Innicializa o valor de y como 0
    p = &y;   // p armazena o endereço de y
    x = *p;  // x recebe o conteudo da variável que p aponta, isto é, x recebe o mesmo valor de y
    x = 4;   // valor de x é atualizado para 4
    (*p)++;  // conteudo da variável que p aponta é incrementado, isto é, o valor de y é incrementado
    --x;    // valor de x é decrementado
    (*p) += x; // // conteudo da variável que p aponta é atualizado [(*p) = (*p)+x], isto é, o valor de y é atualizado 
    printf("%d %d %p", x,y, p);
    
    return 0; 
}
