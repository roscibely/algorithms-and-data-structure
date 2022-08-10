#include <stdio.h>
#include <stdlib.h>

int verifica(int **A, int n, int valor); //prótotipo da função verifica

int main(void){
    /* Função principal do programa em C*/ 

    int i,j, n;

    printf("Insira a dimensão da matriz: \t");
    scanf("%d", &n); //Leitura da dimensão da matriz 

    // Declaração da matriz dinâmica A 
    int**A;
    A = (int**) malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        A[i] = (int*) malloc(n*sizeof(int));
    }

    // Loço de repetição para leitura os elementos de A 
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Digite o elemento da posicao i=%d j=%d \n", i, j);
            scanf("%d", &A[i][j]); 
        }
    }

    int valor = verifica(A, n, 3); //Chamada da função verifica
    printf("Resultado %d \t", valor); 
    
return 0;
}


int verifica(int **A, int n, int valor){
    /*
    Função que verifica se um dado valor existe dentro de uma matriz A

        int ** A: matriz de dimensão n x n
        int n: dimensão da matriz (linha ou coluna)
        int valor: valor que queremos verificar se existe dentro da matriz 
    Retrun: 
        1: se o valor existe dentro da matriz
        0: se o valor não existe na matriz     
    */
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(A[i][j]==valor){
                return 1;
            }
    }
    return 0; 
}