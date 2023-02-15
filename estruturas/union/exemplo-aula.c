#include <stdio.h> 
#include <stdlib.h>


typedef union documento{
    char rg[20];
    char cpf[20];
} Documento;

typedef struct pessoa{
    char nome[50];
    Documento doc;
} Pessoa;

int main(){
    Pessoa p;
    int opcao;
    printf("Digite o nome: ");
    scanf(" %[^\n]s", p.nome);
    printf("Digite o documento: 1- RG, 2- CPF: ");
    scanf("%d", &opcao);
    if(opcao == 1){
        printf("Digite o RG: ");
        scanf(" %[^\n]s", p.doc.rg);
    }else{
        printf("Digite o CPF: ");
        scanf(" %[^\n]s", p.doc.cpf);
    }
    printf("Nome: %s ", p.nome);
    if(opcao == 1){
        printf("RG: %s", p.doc.rg); 
    }else{
        printf("CPF: %s", p.doc.cpf);
    }
    return 0;
}


