#include <stdio.h> // Biblioteca que define as funções de entrada e saída fopen, fclose, fprintf, fscanf, etc. 
#include <stdlib.h> // exit()
#include <string.h> // Biblioteca que define funções para manipulação de strings


/*Escreva um programa que preencha um vetor (strings)
 com informações vindas de um arquivo de entrada  */


int main(void) {

    char* nomes[4]; // Vetor de strings para armazenar os nomes
    char nome[21]; // Variavel para armazenar o nome lido do arquivo
    char linha[100]; // Variavel para armazenar a linha lida do arquivo

    FILE * arquivo_de_entrada; // Variavel para armazenar o ponteiro do arquivo de entrada
    int i, n; // Variaveis para controle do laço de repetição
    i=0; // Inicializando a variavel i com 0

    arquivo_de_entrada = fopen("entrada_ex1.txt", "rt"); // Abrindo o arquivo de entrada para leitura
    if (arquivo_de_entrada == NULL) { // Verifica se o arquivo foi aberto corretamente
        printf("Não encontrado\n"); // Caso o arquivo não seja encontrado, imprime a mensagem "Não encontrado"
        exit(1); 
    }

    /* preencha um vetor (strings) com informações vindas de um arquivo de entrada  */
    while(fgets(linha, 100, arquivo_de_entrada) !=NULL){ // Enquanto houver linhas no arquivo de entrada

        sscanf(linha, "%20[^\n]", nome); // Lê a linha do arquivo de entrada e armazena no vetor nome
        n = strlen(nome); // Armazena o tamanho da string nome na variavel n
        nomes[i] = (char*) malloc((n+1)*sizeof(char)); // Alocando memoria para o vetor nomes
        strcpy(nomes[i], nome); // Copia a string nome para o vetor nomes
        i++; // Incrementa o contador i

    }

    fclose(arquivo_de_entrada); // Fecha o arquivo de entrada

    /*imprima cada elemento do vetor na saída padrão*/ 
    for(i=0; i<4; i++){ // Laço de repetição para imprimir os nomes do vetor nomes
        printf(" %s \t", nomes[i]); // Imprime o nome do vetor nomes
    }

    return 0; // Retorna 0 para o sistema operacional

}