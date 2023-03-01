# Manipulação de arquivos na linguagem C

## Introdução 

A linguagem C é uma linguagem de programação de propósito geral, estruturada, imperativa, procedural, padronizada pela ISO, criada em 1972 por Dennis Ritchie no Bell Labs para desenvolver o sistema operacional Unix (que posteriormente foi adotado pelo GNU Project). Foi a primeira linguagem de programação a ser implementada em uma máquina real, o DEC PDP-11.

## Manipulação de arquivos

A manipulação de arquivos é uma das principais funcionalidades de uma linguagem de programação. Através dela é possível criar, ler, escrever e excluir arquivos.

## Funções usadas na manipulação de arquivos texto em C

### fopen()

A função fopen() é usada para abrir um arquivo. Ela retorna um ponteiro do tipo FILE, que é usado para manipular o arquivo.

```c
FILE *fopen(const char *filename, const char *mode);
```

O primeiro parâmetro é o nome do arquivo que será aberto. O segundo parâmetro é uma string que especifica o modo de abertura do arquivo. Os modos de abertura mais comuns são:

- r: abre um arquivo existente para leitura.
- w: abre um arquivo existente para escrita. Se o arquivo não existir, cria um novo arquivo.
- a: abre um arquivo existente para escrita. Se o arquivo não existir, cria um novo arquivo. As novas informações são adicionadas ao final do arquivo.
- r+: abre um arquivo existente para leitura e escrita.
- w+: abre um arquivo existente para leitura e escrita. Se o arquivo não existir, cria um novo arquivo.
- a+: abre um arquivo existente para leitura e escrita. Se o arquivo não existir, cria um novo arquivo. As novas informações são adicionadas ao final do arquivo.

### fclose()

A função fclose() é usada para fechar um arquivo.

```c
int fclose(FILE *fp);
```

O parâmetro fp é um ponteiro para o arquivo que será fechado.

### fgetc()

A função fgetc() é usada para ler um caractere de um arquivo.

```c
int fgetc(FILE *fp);
```

O parâmetro fp é um ponteiro para o arquivo que será lido.

### fputc()

A função fputc() é usada para escrever um caractere em um arquivo.

```c
int fputc(int c, FILE *fp);
```

O primeiro parâmetro é o caractere que será escrito. O segundo parâmetro é um ponteiro para o arquivo que será escrito.

### feof()

A função feof() é usada para verificar se o final de um arquivo foi atingido.

```c
int feof(FILE *fp);
```

O parâmetro fp é um ponteiro para o arquivo que será verificado.

### fgets()

A função fgets() é usada para ler uma linha de um arquivo.

```c
char *fgets(char *str, int n, FILE *fp);
```

O primeiro parâmetro é um ponteiro para uma string que será usada para armazenar a linha lida. O segundo parâmetro é o número máximo de caracteres que podem ser lidos. O terceiro parâmetro é um ponteiro para o arquivo que será lido.

### fputs()

A função fputs() é usada para escrever uma string em um arquivo.

```c
int fputs(const char *str, FILE *fp);
```

O primeiro parâmetro é a string que será escrita. O segundo parâmetro é um ponteiro para o arquivo que será escrito.

### fprintf()

A função fprintf() é usada para escrever uma string formatada em um arquivo.

```c

int fprintf(FILE *fp, const char *format, ...);
```

O primeiro parâmetro é um ponteiro para o arquivo que será escrito. O segundo parâmetro é a string formatada que será escrita.

### fscanf()

A função fscanf() é usada para ler uma string formatada de um arquivo.

```c
int fscanf(FILE *fp, const char *format, ...);
```

O primeiro parâmetro é um ponteiro para o arquivo que será lido. O segundo parâmetro é a string formatada que será lida.

## Exemplos

### Exemplo 1

Neste exemplo, o arquivo "arquivo.txt" é aberto para escrita. Em seguida, o caractere 'A' é escrito no arquivo. Por fim, o arquivo é fechado.

```c
#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("arquivo.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fputc('A', fp);
    fclose(fp);

    return 0;
}
```

### Exemplo 2

Neste exemplo, o arquivo "arquivo.txt" é aberto para leitura. Em seguida, o caractere 'A' é lido do arquivo. Por fim, o arquivo é fechado.

```c

#include <stdio.h>

int main() {
    FILE *fp;
    int c;

    fp = fopen("arquivo.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    c = fgetc(fp);
    fclose(fp);

    printf("%c\n", c);

    return 0;
}
```

### Exemplo 3

Neste exemplo, o arquivo "arquivo.txt" é aberto para escrita. Em seguida, a string "Hello World!" é escrita no arquivo. Por fim, o arquivo é fechado.

```c
#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("arquivo.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fputs("Hello World!", fp);
    fclose(fp);

    return 0;
}
```



1.  (Aula 01) [Funções usadas na manipulação de arquivos texto em C](https://github.com/roscibely/algorithms-and-data-structure/blob/main/arquivos/manipular_arquivos.c)

2. Prática 01 ✅[(clique aqui para ver as questões)](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/arquivos/quest%C3%B5es-pr%C3%A1tica-01-arquivos.pdf):  
   1️⃣ [Acesse a resposta da questão 1](https://github.com/roscibely/algorithms-and-data-structure/blob/main/arquivos/pratica-01-questao-1.c) 
    
   2️⃣ [Acesse a resposta da questão 2](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/arquivos/pratica-01-questao-2.c) 
