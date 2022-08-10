#include <stdio.h>
#include <stdlib.h>

int *soma_vetor_simples(int*A, int*B, int n);
int **soma_vetor_ponteiros(int**A, int**B, int n);

/*____________________________________________*/
int *soma_vetor_simples(int *A, int*B, int n){
    int i,j;
    int *C;
    C = (int*) malloc(n*n*sizeof(int));
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            C[i*n +j] = A[i*n +j] +B[i*n +j];
    }
    return C;
}

/*____________________________________________*/
int **soma_vetor_ponteiros(int **A, int **B, int n){
    int i,j;
    int**C;
    C = (int**) malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        C[i] = (int*) malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
    }
    return C;
}


/*____________________________________________*/
int main(void){
    int i,j, n;
    printf("Insira a dimensão da matriz: \t");
    scanf("%d", &n);
    int**A, **B;
    /*Alocação da matriz A*/
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
    /*Alocação da matriz B*/
    B = (int**) malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        B[i] = (int*) malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Digite o elemento da posicao i=%d j=%d \n", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    int**Soma = soma_vetor_ponteiros(A, B,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        printf("\n %d \t", Soma[i][j]);

    }
    }
return 0;
}