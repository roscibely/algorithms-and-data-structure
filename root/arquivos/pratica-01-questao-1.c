#include <stdio.h>
#include <string.h>


int main(void){

    FILE * arquivo_entrada, * arquivo_saida; 
    float nota1, nota2, nota3, media=0;
    char nome[100], linha[100];

    //Abrir o arquivo de entrada apenas para leitura (r)
    arquivo_entrada = fopen("entrada_q3.txt", "r");
    if(arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //Abrir/criar o arquivo de saida para escrita (w)
    arquivo_saida = fopen("saida_q3.txt", "w");
    if(arquivo_saida==NULL){
        printf("Erro ao abrir o arquivo"); 
        exit(1); 
    }

    //Ler os dados do arquivo de entrada
    while(fgets(linha,100,arquivo_entrada) != NULL){
        sscanf(linha, "%20[^\t]\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3);
        media = (nota1 + nota2 + nota3)/3;
        
        // Escreve no arquivo de saida os dados de nome, media e aprovado/reprovado
        fprintf(arquivo_saida, "%s\t%.1f\t %s\n", nome, media, (media>=7.0)?"aprovado":"reprovado");

    }
    // Fecha os arquivos abertos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}