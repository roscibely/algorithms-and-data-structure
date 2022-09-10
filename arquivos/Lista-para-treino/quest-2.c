/* 
escrever um programa em C que, dado o arquivo com a relação de funcionários,
imprima o valor gasto com a folha de pagamento para um determinado departamento. 
Os dados dos funcionários da empresa devem ser fornecidos para um vetor,
de modo que uma função que execute tal tarefa deve ser implementada, obedecendo ao protótipo:

void copia_dados(FILE* fl, int n, Funcionario* pessoal);
*/


#include <stdio.h> // printf, scanf, fopen, fclose
#include <stdlib.h> // malloc, free
#include <string.h> // strcpy

typedef struct funcionario{
    char nome[21];
    char departamento;
    float salario;
    char funcional[11];
}Funcionario;

void copia_dados(FILE* fl, int n, Funcionario** pessoal); // protótipo da função que copia os dados do arquivo para o vetor de ponteiro pessoal
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto); // protótipo da função que imprime a folha de pagamento de um determinado departamento
 
// função principal 
int main(void) {

    char linha[100]; // Variavel para armazenar a linha lida do arquivo
    int n; // Variavel para armazenar o numero de funcionarios
    Funcionario** pessoal; // Ponteiro para a estrutura Funcionario
    FILE * arquivo_de_entrada; // Variavel para armazenar o ponteiro do arquivo de entrada
    int i; // Variavel para controle do laço de repetição
    i=0; // Inicializando a variavel i com 0

    arquivo_de_entrada = fopen("entrada_ex2.txt", "rt"); // Abrindo o arquivo de entrada para leitura
    if (arquivo_de_entrada == NULL) { // Verifica se o arquivo foi aberto corretamente
        printf("Não encontrado\n"); // Caso o arquivo não seja encontrado, imprime a mensagem "Não encontrado"
        exit(1); 
    }

    fgets(linha, 100, arquivo_de_entrada); // Lê a primeira linha do arquivo de entrada que contém o numero de funcionarios ao todo na empresa
    sscanf(linha, "%d", &n); // Lê a linha do arquivo de entrada e armazena o valor em n
    printf("Numero de funcionarios: %d\n", n); // Imprime o numero de funcionarios

    pessoal = (Funcionario**) malloc(n*sizeof(Funcionario*)); // Alocando memoria para o vetor pessoal
    for(i=0; i<n; i++){ // Laço de repetição para alocar memoria para cada elemento do vetor pessoal
        pessoal[i] = (Funcionario*) malloc(sizeof(Funcionario)); // Alocando memoria para cada elemento do vetor pessoal
    }

    printf("\nCopiando dados do arquivo para o vetor...\n\n");
    copia_dados(arquivo_de_entrada, n, pessoal); // Chamando a função copia_dados
    printf("\nDados copiados com sucesso!\n\n");

    imprime_folha_pagamento(n, pessoal, 'A'); // Chamando a função imprime_folha_pagamento
    imprime_folha_pagamento(n, pessoal, 'B'); // Chamando a função imprime_folha_pagamento

    fclose(arquivo_de_entrada); // Fecha o arquivo de entrada

    for(i=0; i<n; i++){ // Laço de repetição para liberar a memoria alocada para cada elemento do vetor pessoal
        free(pessoal[i]); // Liberando a memoria alocada para cada elemento do vetor pessoal
    }
    free(pessoal); // Libera a memoria alocada para o vetor pessoal

    return 0; // Retorna 0 para o sistema operacional

}

void copia_dados(FILE* fl, int n, Funcionario** pessoal){
    int i=0; // Variavel para controle do laço de repetição
    while(!feof(fl)){ // Laço de repetição que lê as linhas do arquivo de entrada feof verifica se o arquivo chegou ao fim
        if(i==0){
            fscanf(fl,"%d", &n); // Lê a primeira linha do arquivo de entrada que contém o numero de funcionarios ao todo na empresa
        }
        else{ //Ler as demais linhas do arquivo de entrada
            fscanf(fl,"%[^\t]\t%[^\t]\t%c\t%f ", pessoal[i-1]->funcional, pessoal[i-1]->nome, &pessoal[i-1]->departamento, &pessoal[i-1]->salario); // Lê a linha do arquivo de entrada e armazena nos parametros da estrutura funcionario
        }
        i++; // Incrementa a variavel i
    }    
}


/* 
implementar uma função que imprime o valor gasto para um determinado departamento.
Esta função deve obedecer ao seguinte protótipo:
void imprime_folha_pagamento(int n, Funcionario* pessoal, char depto);
*/

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto){

    int i=0; // Variavel para controle do laço de repetição e Inicializando a variavel i com 0

    printf("Folha de pagamento do departamento %c \n\n", depto); //mensagem 
    printf("Funcional\tNome\t\tDepartamento\tSalario"); //mensagem

    while(i<n){ // Laço de repetição para ler as linhas do arquivo de entrada
        if(strcmp(&(pessoal[i]->departamento), &(depto)) == 0){ // Verifica se o departamento é igual ao depto
            printf("\n%s\t\t%s\t\t%c\t\t%.2f\n", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, pessoal[i]->salario); // Imprime os dados do funcionario
        }
        i++; // Incrementa a variavel i
    }
}