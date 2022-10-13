// TAD Ingresso que contenha os seguintes campos: atração, local e preço

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresso.h"

struct ingresso {
    char atracao[50];
    char local[50];
    float preco;
};



void preencherIngresso(char *nomeArquivo) {

    Ingresso ingresso;

    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %[^\n]", ingresso.atracao);
    printf("Digite o local: ");
    scanf(" %[^\n]", ingresso.local);
    printf("Digite o preço: ");
    scanf("%f", &ingresso.preco);

    fprintf(arquivo, "%s %s %f ", ingresso.atracao, ingresso.local, ingresso.preco);
    printf("Ingresso cadastrado com sucesso!\n");

    fclose(arquivo);
}



void imprimirIngressos(char *nomeArquivo) {

    Ingresso ingresso;

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (fscanf(arquivo, "%s %s %f ", ingresso.atracao, ingresso.local, &ingresso.preco) != EOF) {
        printf("Atração: %s Local: %s Preço: %.2f \n ", ingresso.atracao, ingresso.local, ingresso.preco);
    }

    fclose(arquivo);
}

// Função para alterar o preço de um ingresso em um arquivo dado o nome da atração 

void alterarPreco(char *nomeArquivo, char *atracao) {

    Ingresso ingresso;

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    FILE *arquivoTemp = fopen("temp.txt", "w");
    if (arquivoTemp == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (fscanf(arquivo, "%s %s %f ", ingresso.atracao, ingresso.local, &ingresso.preco) != EOF) {
        if (strcmp(ingresso.atracao, atracao) == 0) {
            printf("Digite o novo preço da atração: ");
            scanf("%f", &ingresso.preco);
        }
        fprintf(arquivoTemp, "%s %s %f ", ingresso.atracao, ingresso.local, ingresso.preco);
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    remove(nomeArquivo);
    rename("temp.txt", nomeArquivo);
}
