#include <stdio.h>
#include <stdlib.h>
/*
 - O que veremos? 
    - Como manipular arquivos em C;
    - Funções para manipular arquivos (fechar e abrir);

    - Funções para ler dados:
     int fscanf (FILE* fp, char* formato, ...); 
     int fgetc (FILE* fp);
     char* fgets (char* s, int n, FILE* fp)
 */

int main() {
    // Abrindo um arquivo
    FILE *arquivo = fopen("arquivo.txt", "w");
    if(arquivo==NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    // Fechando um arquivo
    fclose(arquivo);

    return 0;
}