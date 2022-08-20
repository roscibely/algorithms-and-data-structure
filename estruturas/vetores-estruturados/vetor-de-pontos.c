#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    float x, y;
}Ponto; 

int main(void){

    int contador;
    int tamanho_vetor;

    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho_vetor);

    Ponto * vetor = (Ponto*) malloc(tamanho_vetor*sizeof(Ponto));

    //Leitura dos elementos para o vetor
    for(contador=0; contador<tamanho_vetor; contador++){
        printf("Digite as coordenadas do ponto %d\n", contador);
        scanf("%f %f", &vetor[contador].x, &vetor[contador].y); 
    }

    //Impressão dos pontos digitados
    for(contador=0; contador<tamanho_vetor; contador++){

        printf("As coordenadas do ponto %d: (%f, %f) \n", contador,  vetor[contador].x, vetor[contador].y);

    }    

    free(vetor); 

    return 0;
}