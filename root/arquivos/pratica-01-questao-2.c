#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // exit()

int main(void){

    char linha[100]; //Para armazenar a linha de entrada do arquivo
    int v[10]; // Vetor para armaenar os valores lidos do arquivo
    FILE * arq, *arq1; //Variaveis para armazenar o ponteiro do arquivo
    int n=0; // contador para acessar os dados do vetor v
    float media =0; // variavel para armazenar a media dos valores do vetor v
    
    //Abrindo o arquivo de entrada para leitura
    arq = fopen("entrada_lista1_ex2.txt", "rt");
    if (arq == NULL) {
        printf("Não encontrado\n");
        exit(1);
    }

    // Cria o arquivo de saida para escrita 
    arq1 = fopen("saida_lista1_ex2.txt", "wt");
    if (arq1 == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    // Ler os dados do arquivo de entrada 
    while (fgets(linha,100,arq) != NULL){
        // Passando os dados do vetor linha para o vetor v
        sscanf(linha, "%d ", &v[n]);
        // Somando os valores do vetor v e armazenando em media 
        media+=v[n];
        // Incrementando o contador n para acessar o proximo elemento do vetor v
        n++;
    }

   // Encontrar o maior e menor elemento do vetor v  
    int menor = v[0]; //Variavel para guardar o menor
    int maior = v[0]; // Variavel para guardar o maior 

    // Laço de repetição for para encontrar o maior e menor elemento do vetor v 
    for(n=0; n<10; n++){
            // Verifica se o elemento do vetor v é menor que o valor armazenado em menor
            if(v[n] < menor)
                menor =  v[n];
            // Verifica se o elemento do vetor v é maior que o valor armazenado em maior    
            if(v[n] > maior)
                maior =  v[n];
        }
    // Escrever no arquivo de saida
    fprintf(arq1, "  menor elemento: %d\n maior elemento: %d \n media dos elementos %f ", menor, maior, media/10);
    fclose(arq);
    return 0;
}