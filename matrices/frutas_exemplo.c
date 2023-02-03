#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Problema: 
Programa que recebe nomes de frutas e seu preço. A quantidade frutas deve ser informada
pelo o usuário. Utilize alocação dinâmica, especialmente a função  realloc para nãoo desperdiçar
memória.

*/

int main() {

    char **nomes;
    float *precos;
    int qtd_frutas, i, j;

    printf("Quantidade de frutas: ");
    scanf("%d", &qtd_frutas);

    nomes = (char **)malloc(qtd_frutas * sizeof(char *));
    precos = (float *)malloc(qtd_frutas * sizeof(float));

    for (i = 0; i < qtd_frutas; i++) {
        nomes[i] = (char *)malloc(20 * sizeof(char));
        printf("Digite o nome da fruta %d: ", i + 1);
        scanf(" %[^\n]s", nomes[i]);

        // Para não "desperdiçar" a memória, realocamos a memória para o tamanho exato
        nomes[i] = (char *)realloc(nomes[i], (strlen(nomes[i]) + 1) * sizeof(char));
        
        printf("Digite o preco da fruta %d: ", i + 1);
        scanf("%f", &precos[i]);
    }


    printf("Frutas e Preços: \n");
    for (i = 0; i < qtd_frutas; i++) {
        printf("Fruta %d: %s, Preço: %.2f\n", i + 1, nomes[i], precos[i]);
    }

    // Liberando memória
    for (i = 0; i < qtd_frutas; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(precos);
    return 0;
}
