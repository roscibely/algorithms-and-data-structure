## Estrutura de dados: Pilha 

### As pilhas são estruturas de dados que seguem o princípio LIFO (Last In, First Out), ou seja, o último elemento a entrar é o primeiro a sair.

### Exemplo de uso: 
```c
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha *pilha = cria_pilha();
    int i;
    for (i = 0; i < 10; i++) {
        pilha_push(pilha, i);
    }
    while (!pilha_vazia(pilha)) {
        printf("%d ", pilha_pop(pilha));
    }
    printf("\n");
    libera_pilha(pilha);
    return 0;
}
```

### Saída:
```c
9 8 7 6 5 4 3 2 1 0
```