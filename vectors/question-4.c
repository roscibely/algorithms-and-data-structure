#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*Faça um programa que perunte ao user quantos valores eele deseja armazenar em um vetor tipo double com alocação dinamica,
esse vetor deve ter um tamanho maior ou igual a 10. Abriua aos 10 primeiros elementos valores aleatorios com a função rand() entre 0 a 100 */

int main(void){
    int tamanho;
    double *vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    while(tamanho<10){
        printf("Digite um tamanho maior ou igual a 10: ");
        scanf("%d", &tamanho);
    }
    vetor = (double*)malloc(tamanho*sizeof(double));
    int i;
    for(i=0; i<10; i++){
        vetor[i] = rand()%100;
    }
    for(i=0; i<10; i++){
        printf("%.0lf ", vetor[i]);
    }
    free(vetor);
    return 0;
}