#include <stdio.h>
#include <stdlib.h>

#define NUMERO_DE_FUNCIONARIOS  10 //Declaração de constante 

typedef struct funcionario{
    char nome[100];
    int idade; 
    float salario;
}Funcionario;

int main(void){

    Funcionario vetor_de_functionarios[NUMERO_DE_FUNCIONARIOS]; 
    int contador; 

    printf("\n----Digite os dados referentes aos funcionarios--- \n\n");
    //Leitura dos dados dos funcionarios
    for(contador=0; contador<NUMERO_DE_FUNCIONARIOS; contador++){

        printf("Digite o nome do funcionario \n");
        scanf("%[^\n]", vetor_de_functionarios[contador].nome);

        printf("Digite a idade do funcionario \n");
        scanf("%d", &vetor_de_functionarios[contador].idade);

        printf("Digite o salario do funcionario \n");
        scanf("%f", &vetor_de_functionarios[contador].salario);       
    }
    // Impressão dos dados dos funcionarios
    for(contador=0; contador<NUMERO_DE_FUNCIONARIOS; contador++){

        printf("Funcionario %d \n", contador);
        printf("Nome: %s\n", vetor_de_functionarios[contador].nome);
        printf("Idade: %d\n", vetor_de_functionarios[contador].idade);
        printf("Salario: R$ %.2f\n", vetor_de_functionarios[contador].salario);       
    }

    return 0; 
}
