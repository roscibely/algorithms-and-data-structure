#include "pilha.c"

  

int main(void){
    Pilha* p = pilha_cria();
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);
    pilha_imprime(p);
    pilha_pop(p);
    pilha_imprime(p);
    pilha_libera(p);
    return 0;
}