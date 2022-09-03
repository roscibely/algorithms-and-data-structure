#include <stdio.h>
/*
Crie um tipo estruturado para armazenar dados de uma pessoa.
Uma estrutura deste tipo possui os seguintes campos: nome da pessoa, numero do documento e idade.
 */

typedef struct pessoa {
    char nome[50];
    int idade;
    int documento;
}Pessoa;

/*
Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa e
preencha seus campos com valores fornecidos pelo usuário via teclado. 
 */

void preenchePessoa(Pessoa *pessoa) {
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", &pessoa->nome);
    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa->idade);
    printf("Digite o numero do documento: ");
    scanf("%d", &pessoa->documento);
}

/*
Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa
 e imprima os valores dos seus campos.
 */

void imprime(Pessoa *pessoa) {
    printf("Nome da pessoa: %s, idade: %d, documento: %d ", pessoa->nome, pessoa->idade, pessoa->documento);
}

/*
Implemente uma função para realizar uma atualização da idade de uma estrutura do tipo Pessoa.
 */

void atualizaIdade(Pessoa *pessoa, int novaidade) {
    pessoa->idade = novaidade;
}

/*Escreva uma função que receba como parâmetro um vetor de estruturas
do tipo Pessoa e imprima o nome da Pessoa mais velha e mais nova. */

void maisVelhaMaisNova(Pessoa *pessoas, int tam) {
    int i, maisvelha = 0, maisnova = 0;
    for (i = 0; i < tam; i++) {
        if (pessoas[i].idade > pessoas[maisvelha].idade) {
            maisvelha = i;
        }
        if (pessoas[i].idade < pessoas[maisnova].idade) {
            maisnova = i;
        }
    }
    printf("\nPessoa mais velha: %s,\nPessoa mais nova: %s", pessoas[maisvelha].nome, pessoas[maisnova].nome);
}

/*
Implemente a função main para testar todas as demais funções declaradas nos itens anteriores
 */

int main() {

    int n;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);

    Pessoa pessoas[n];
    int i;
    for (i = 0; i < n; i++) {
        preenchePessoa(&pessoas[i]);
    }
    for (i = 0; i < n; i++) {
        imprime(&pessoas[i]);
    }
    atualizaIdade(&pessoas[0], 18);
    maisVelhaMaisNova(pessoas, n);
    return 0;
}