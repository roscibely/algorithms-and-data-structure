#include <stdio.h>
#include <stdlib.h>

int pares(int n, int* vet){
    /* Função que conta a quantidade de números pares em um  vetor

        int n: números de elementos do vetor (tamanho do vetor vet)
        int *vet: endereço para o primeiro elemento do vetor

    Return: 
        int soma: quantidade de elementos pares existentes no vetor vet

    */

    int i, soma;
    soma=0;
    for(i=0; i<n; i++){
            if(vet[i]%2==0){
                soma++;
            }
    }
    return soma;
}

int main(void){

    /* Função principal do programa */ 

    int n, i, s;

    printf("Digite a quantidade de elementos do vetor \n");
    scanf("%d", &n);

    int * v = (int*) malloc(n*sizeof(int)); // Aloca o vetor v dinamicamente

    for(i=0; i<n; i++){
        printf("Digite um elemento do vetor\n");
        scanf("%d", &v[i]);
    }

    s = pares(n,v); // Faz a chamada da função pares 

    printf("\n ----Existe %d numeros  pares----\n", s);

    free(v); //Libera o espeço alocado para v 

    return 0;
}