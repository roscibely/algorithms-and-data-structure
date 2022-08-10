#include <stdio.h>
#include <stdlib.h>

int verifica(int **A, int n, int valor);

int main(void){

    int i,j, n;

    printf("Insira a dimensão da matriz: \t");
    scanf("%d", &n);

    int**A;
    A = (int**) malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        A[i] = (int*) malloc(n*sizeof(int));
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Digite o elemento da posicao i=%d j=%d \n", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int valor = verifica(A, n, 3);
    printf("Resultado %d \t", valor);
    
return 0;
}


int verifica(int **A, int n, int valor){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(A[i][j]==valor){
                return 1;
            }
    }
    return 0; 
}