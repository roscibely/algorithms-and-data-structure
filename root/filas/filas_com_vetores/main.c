#include "fila.c"

int main(void)
{
    Fila *f = fila_cria();

    printf("Inserindo 3 elementos (10, 20, 30) na fila:\n");
    fila_insere(f, 10);
    fila_insere(f, 20);
    fila_insere(f, 30);
    fila_imprime(f);

    printf("Removendo um elemento da fila (esperado: 10):\n");
    fila_remove(f);
    fila_imprime(f);

    printf("Inserindo 40 na fila:\n");
    fila_insere(f, 40);
    fila_imprime(f);

    printf("Removendo todos os elementos:\n");
    fila_remove(f);
    fila_remove(f);
    fila_remove(f);
    fila_imprime(f);

    printf("Tentando remover de uma fila vazia:\n");
    if (fila_vazia(f))
        printf("Fila está vazia.\n");
    else
        fila_remove(f);

    printf("Preenchendo a fila até a capacidade máxima (%d elementos):\n", MAX);
    for (int i = 1; i <= MAX; i++)
    {
        fila_insere(f, i * 10);
    }
    fila_imprime(f);

    printf("Tentando inserir em uma fila cheia:\n");
    if (fila_cheia(f))
        printf("Fila está cheia.\n");
    else
        fila_insere(f, 100);

    fila_libera(f);

    return 0;
}