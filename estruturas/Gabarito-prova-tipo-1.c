#include <stdio.h>
/*
Crie um tipo estruturado para armazenar dados de uma conta bancária. Uma estrutura deste tipo possui os
seguintes campos: nome do cliente, saldo e número.
 */
typedef struct conta {
    char nome[50];
    float saldo;
    int numero;
} ContaBancaria;

/* 
Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo ContaBancária e
preencha seus campos com valores fornecidos pelo usuário via teclado. 
*/

void preencheConta(ContaBancaria *conta) {
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", &conta->nome);
    printf("Digite o saldo da conta: ");
    scanf("%f", &conta->saldo);
    printf("Digite o numero da conta: ");
    scanf("%d", &conta->numero);
}

 /*
 Escreva uma função que receba como parâmetro o endereço
 de uma estrutura do tipo ContaBancária e imprima os valores dos seus campos. 
 */

void imprime(ContaBancaria *conta) {
    printf("Nome do cliente: %s, saldo: %.2f, numero: %d ", conta->nome, conta->saldo, conta->numero);
}

/*
Implemente uma função para realizar um depósito em
uma estrutura do tipo ContaBancaria.
*/

void deposito(ContaBancaria *conta, float valor) {
    conta->saldo += valor;
}

/*
Escreva uma função que receba como parâmetro um vetor de estruturas
do tipo ContaBancária imprima o nome do cliente com menor saldo e o nome do cliente com maior saldo. 
 */

void maiorMenor(ContaBancaria *contas, int tam) {
    int i, maior = 0, menor = 0;
    for (i = 0; i < tam; i++) {
        if (contas[i].saldo > contas[maior].saldo) {
            maior = i;
        }
        if (contas[i].saldo < contas[menor].saldo) {
            menor = i;
        }
    }
    printf("\nCliente com maior saldo: %s,\nCliente com menor saldo: %s", contas[maior].nome, contas[menor].nome);
}

/*Implemente a função main para testar todas as demais funções declaradas nos itens anteriores*/

int main(void){

    int n;
    printf("Quantas contas deseja cadastrar? ");
    scanf("%d", &n);

    ContaBancaria contas[n];
    int i;

    for (i = 0; i < n; i++) {
        preencheConta(&contas[i]);
    }
    for (i = 0; i < n; i++) {
        imprime(&contas[i]);
    }
    deposito(&contas[0], 100);
    maiorMenor(contas, n);
    return 0;
}