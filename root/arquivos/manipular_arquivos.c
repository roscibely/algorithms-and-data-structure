#include <stdio.h>
#include <stdlib.h>
/*
 - O que veremos? 
    - Como manipular arquivos em C;
    - Funções para manipular arquivos (fechar, abrir, ler e escrever);

    - Funções para abrir arquivos 
        FILE * fopen(char * nome_arquivo, char * modo_abertura);
        - nome_arquivo: nome do arquivo que será aberto;
        - modo_abertura: modo de abertura do arquivo;
            - r: leitura;
            - w: escrita;
            - a: anexar;
            - r+: leitura e escrita;
            - w+: escrita e leitura;
            - a+: anexar e leitura;
            - b: modo binário;
            - t: modo texto;
            - +: atualização;

    - Funções para fechar arquivos
        int fclose(FILE * arquivo);
        - arquivo: ponteiro para o arquivo que será fechado;

    - Funções para escrever em arquivos
        int fputc(int caractere, FILE * arquivo);
        - caractere: caractere que será escrito no arquivo;
        - arquivo: ponteiro para o arquivo que será escrito;
        int fputs(char * string, FILE * arquivo);
        - string: string que será escrita no arquivo;
        - arquivo: ponteiro para o arquivo que será escrito;
        int fprintf(FILE * arquivo, char * formato, ...);
        - arquivo: ponteiro para o arquivo que será escrito;
        - formato: formato da string que será escrita no arquivo;
        - ...: argumentos que serão escritos no arquivo;
    
    - Funções para ler dados:
     int fscanf (FILE* fp, char* formato, ...); 
        - fp: ponteiro para o arquivo que será lido;
        - formato: formato da string que será lida do arquivo;
        - ...: variáveis que receberão os dados lidos do arquivo;

     int fgetc (FILE* fp);
        - fp: ponteiro para o arquivo que será lido;
        - retorna: caractere lido do arquivo;

     char* fgets (char* s, int n, FILE* fp); 
        - s: string que receberá os dados lidos do arquivo;
        - n: tamanho máximo da string;
        - fp: ponteiro para o arquivo que será lido;
        - retorna: string lida do arquivo;
 */

int main() {
    
    // Abrindo um arquivo   
    FILE *arquivo = fopen("arquivo.txt", "w");
    if(arquivo==NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    // Escrevendo no arquivo
    fputs("ABC", arquivo);
    //fputc('A', arquivo);

    // Fechando um arquivo
    fclose(arquivo);  

    return 0;
}