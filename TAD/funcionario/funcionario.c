//TAD Funcionario que possui os seguintes campos: nome, salario e cargo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"



struct funcionario{
    char nome[50];
    float salario;
    char cargo[50];
};

// Preencher campos do funcionario: Receber os dados do funcionario fornecidos pelo usuario via teclado e armazenar em um arquivo

void preencherFuncionario(char *nomeArquivo){

    Funcionario func;
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", func.nome);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &func.salario);
    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]", func.cargo);

    FILE *arquivo = fopen(nomeArquivo, "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    fprintf(arquivo, "%s %f %s ", func.nome, func.salario, func.cargo);
    printf("Funcionario cadastrado com sucesso!");

    fclose(arquivo);
}

// Imprime funcionarios: Imprime todos os funcionarios cadastrados em um arquivo

void imprimirFuncionarios(char *nomeArquivo){

    Funcionario func;

    FILE *arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    while(fscanf(arquivo, "%s %f %s ", func.nome, &func.salario, func.cargo) != EOF){
        printf("Nome: %s Salario: %.2f Cargo: %s \n ", func.nome, func.salario, func.cargo);
    }

    fclose(arquivo);
}

// Altera salário: Altera o salário de um funcionário cadastrado em um arquivo

void alterarSalario(char *nomeArquivo, char * nome){

    Funcionario func;
    float novoSalario;

    printf("Digite o novo salario do funcionario %s: ", nome);
    scanf("%f", &novoSalario);

    FILE *arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    FILE *arquivoTemp = fopen("temp.txt", "w");
    if(arquivoTemp == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    while(fscanf(arquivo, "%s %f %s ", func.nome, &func.salario, func.cargo) != EOF){
        if(strcmp(func.nome, nome) == 0){
            func.salario = novoSalario;
        }
        fprintf(arquivoTemp, "%s %f %s ", func.nome, func.salario, func.cargo);
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    remove(nomeArquivo);
    rename("temp.txt", nomeArquivo);
}