#include "fila.c"

int main(void){
    Fila* f = fila_cria();
    fila_insere(f, 10);
    fila_insere(f, 20);
    fila_insere(f, 30);
    fila_imprime(f);
    fila_remove(f);
    fila_imprime(f);
    fila_libera(f);
    return 0;
}