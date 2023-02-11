# Vetores de ponteiros para struct 

## Exemplo:  Declaração de um vetor do tipo ponteiro struct ponto dinâmicamente 
![](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/estruturas/vetores-de-ponteiros-de-struct/vetor-ponteiro-struct.png)


No exemplo acima, declaramos um vetor que armazena 3 ponteiros para struct ponto. Dessa forma, em cada posição do vetor, podemos armazenar o endereço de uma struct ponto. 

### Exemplo em C:  Atribuição de valores para um vetor de ponteiros de struct

´´´c
#include <stdio.h>
#include <stdlib.h>

struct ponto {
    int x;
    int y;
};

int main() {
    struct ponto **pontos = (struct ponto **) malloc(3 * sizeof(struct ponto *));
    
    int i;

    for (i = 0; i < 3; i++) {
        pontos[i] = (struct ponto *) malloc(sizeof(struct ponto));
        pontos[i]->x = i;
        pontos[i]->y = i;
    }

    for (i = 0; i < 3; i++) {
        printf("pontos[%d] = (%d, %d)\n", i, pontos[i]->x, pontos[i]->y);
    }

    return 0;
}
