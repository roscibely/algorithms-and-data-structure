#include <stdio.h>
#include <stdlib.h>

void preenche_ordenado(int n, int*vet){

    int i,j, aux;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            aux = vet[i];
            if(aux>vet[j]){
                vet[i] = vet[j];
                vet[j] = aux;
                }
        }

    }

}


int main(void){

    int n,i,j;

    printf("Insira a quatidade de elementos do vetor: \t");
    scanf("%d", &n);

    int *vet;
    vet = (int*) malloc(n*sizeof(int));

    for(i=0; i<n;i++)
        scanf("%d", &vet[i]);

    preenche_ordenado(n,vet);

    for(j=n-1; j>=0; j--){
        printf("%d \t", vet[j]);
    }

    return 0;
}