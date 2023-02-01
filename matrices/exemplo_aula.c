/* Exemplo feito em aula: Alocação Dinâmica de Matrizes na Linguagem C

O programa consiste em solicitar ao usuário nomes e
 armazená-los em uma matriz de caracteres.

O programa solicita ao usuário a quantidade de nomes que ele deseja armazenar.

Em seguida, o programa aloca dinamicamente uma matriz de caracteres
 com a quantidade de linhas igual a quantidade de nomes digitados pelo usuário.

O programa vai armazenar os nomes digitados pelo usuário na matriz de caracteres.
Exemplo: 

nomes = {
    {"Joao Gomes Henrique"},
    {"Maria da Silva"},
    {"Jose da Silva"}
}

*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main(void){

    int qnt_nomes, linha;
    printf("Digite a quantidade de nomes: \n");
    scanf("%d", &qnt_nomes); 

    // Alocação dinâmica de uma matriz de caracteres
    char ** nomes = (char**) malloc(qnt_nomes*sizeof(char*));
    if(nomes==NULL){ // Verifica se a alocação foi bem sucedida
        printf("Erro");
        exit(1);
    } 
    // Alocação dinâmica de cada linha da matriz de caracteres
    for(linha=0; linha<qnt_nomes; linha++){
        nomes[linha] = (char*) malloc(50*sizeof(char));
    }

    for(linha=0; linha<qnt_nomes; linha++){
        printf("Digite o nome: ");
        scanf(" %[^\n]s", nomes[linha]);
    } 

    printf("Lista de nomes \n");
    printf("---------------------\n"); 
    for(linha=0; linha<qnt_nomes; linha++){
        printf("%s \n", nomes[linha]);
    }

    for(linha=0; linha<qnt_nomes; linha++){
        free(nomes[linha]);
    }
    free(nomes);

    return 0;
}