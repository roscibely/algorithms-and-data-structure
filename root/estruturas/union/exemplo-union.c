#include <stdio.h>

typedef union id{
    int rg;
    int cpf;
}id; 

typedef struct pessoa{
    int idade; 
    id documento; 
    char nome[60];
}Pessoa;

int main(void){

    Pessoa p;
    int op;
    
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", p.nome);

    printf("Digite a idade: ");
    scanf("%d", &p.idade);

    printf("Selecione o documento a ser digitado 0-CPF ou 1-RG: ");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        printf("Digite o CPF: ");
        scanf("%d", &p.documento.cpf);
        break;
    case 1:
        printf("Digite o RG: ");
        scanf("%d", &p.documento.rg);
        break;
    default:
        printf("invalido \n");
        break;
    }

    printf("Dados: \n Nome: %s\n Idade: %d \nDocumento: %d", p.nome, p.idade, op?p.documento.rg:p.documento.cpf); //Operador ternario: Condição ? verdadeiro : falso
    return 0;
}