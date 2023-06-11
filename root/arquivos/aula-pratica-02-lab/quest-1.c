/*
1) Faça um programa em C que solicita ao usuário informações de funcionários via teclado.
As informações digitadas pelo o usuário são: id, nome e salário do funcionário.
Armazene as informações digitadas pelo usuário em um arquivo texto. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct functionario{
    int id;
    char nome[50];
    float salario;
} Funcionario;

int main() {

    Funcionario funcionario;
    FILE *arquivo;
    char nomeArquivo[50];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    printf("Digite o id do funcionario: ");
    scanf("%d", &funcionario.id);
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", funcionario.nome);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    fprintf(arquivo, "%d %s %f", funcionario.id, funcionario.nome, funcionario.salario);

    fclose(arquivo);
    
    return 0;

}
