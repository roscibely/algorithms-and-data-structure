// Crie um TAD chamado ContaBancaria que possui os seguintes campos: titular, número e saldo.
#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

struct contabancaria
{
    char titular[50];
    int numero;
    float saldo;
};


ContaBancaria *criaconta(char * nome_arquivo){
    ContaBancaria *conta;
    conta = (ContaBancaria *) malloc(sizeof(ContaBancaria));
    printf("Digite o nome do titular: ");
    scanf("%s", conta->titular);
    printf("Digite o numero da conta: ");
    scanf("%d", &conta->numero);
    conta->saldo = 0;
    FILE *arq;
    arq = fopen(nome_arquivo, "a");
    fprintf(arq, "Titular: %s Numero: %d Saldo: %.2f \n", conta->titular, conta->numero, conta->saldo);
    fclose(arq);
    return conta;
}


void deposita(ContaBancaria *conta, float valor, char * nome_arquivo){
    conta->saldo += valor;
    FILE *arq;
    arq = fopen(nome_arquivo, "a");
    fprintf(arq, "Titular: %s Numero: %d Saldo: %.2f \n", conta->titular, conta->numero, conta->saldo);
    fclose(arq);
}


void saca(ContaBancaria *conta, float valor, char * nome_arquivo){
    if(conta->saldo >= valor){
        conta->saldo -= valor;
        FILE *arq;
        arq = fopen(nome_arquivo, "a");
        fprintf(arq, "Titular: %s Numero: %d Saldo: %.2f \n", conta->titular, conta->numero, conta->saldo);
        fclose(arq);
    }else{
        printf("Saldo insuficiente para realizar o saque");
    }
    
}


void transfere(ContaBancaria *conta1, ContaBancaria *conta2, float valor){
    if(conta1->saldo >= valor){
        conta1->saldo -= valor;
        conta2->saldo += valor;
    }else{
        printf("Saldo insuficiente para realizar a transferencia");
    }
}


void excluiConta(ContaBancaria *conta){
    free(conta);
}