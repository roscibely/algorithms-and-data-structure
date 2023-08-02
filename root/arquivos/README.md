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

### Exemplo: abrindo um arquivo

Neste exemplo, o arquivo "arquivo.txt" é aberto para escrita.

```c
#include <stdio.h>

FILE * fp;
fp = fopen("arquivo.txt", "w");
if (fp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
}
```


### fclose()

A função fclose() é usada para fechar um arquivo.

```c
int fclose(FILE *fp);
```

O parâmetro fp é um ponteiro para o arquivo que será fechado.

### Exemplo: fechando um arquivo

Neste exemplo, o arquivo "arquivo.txt" é fechado.

```c
#include <stdio.h>

FILE * fp;
fp = fopen("arquivo.txt", "w"); // Abre o arquivo
 
fclose(fp); // Fecha o arquivo

```

### fgetc()

A função fgetc() é usada para ler um caractere de um arquivo.

```c
int fgetc(FILE *fp);
```

O parâmetro fp é um ponteiro para o arquivo que será lido.

### Exemplo: lendo com a função fgetc()

Neste exemplo, o arquivo "arquivo.txt" é aberto para leitura. Em seguida, o caractere 'A' é lido do arquivo. Por fim, o arquivo é fechado. Portanto, considerando que o arquivo "arquivo.txt" contenha apenas o caractere 'A', o programa imprimirá na tela o caractere 'A'.

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
    c = fgetc(fp); // Lê um caractere do arquivo
    printf("%c\n", c); // Imprime o caractere lido
    fclose(fp);

    return 0;
}
```

### fputc()

A função fputc() é usada para escrever um caractere em um arquivo.

```c
int fputc(int c, FILE *fp);
```

O primeiro parâmetro é o caractere que será escrito. O segundo parâmetro é um ponteiro para o arquivo que será escrito.

### Exemplo: escrevendo com a função fputc()

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
    fputc('A', fp); // Escreve o caractere 'A' no arquivo apontado por fp
    fclose(fp);

    return 0;
}
```

### feof()

A função feof() é usada para verificar se o final de um arquivo foi atingido.

```c
int feof(FILE *fp);
```

O parâmetro fp é um ponteiro para o arquivo que será verificado.

### Exemplo: Veficando se chegamos ao final do arquivo

```c
#include <stdio.h>

int main() {
    FILE *fp;
    int c;

    fp = fopen("arquivo.txt", "r"); // Abre o arquivo
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    while (!feof(fp)) { // Enquanto não chegar ao final do arquivo
        c = fgetc(fp); // Lê um caractere do arquivo
        printf("%c", c); // Imprime o caractere lido
    }
    fclose(fp); // Fecha o arquivo

    return 0;
}
```


### fgets()

A função fgets() é usada para ler uma linha de um arquivo.

```c
char *fgets(char *str, int n, FILE *fp);
```

O primeiro parâmetro é um ponteiro para uma string que será usada para armazenar a linha lida. O segundo parâmetro é o número máximo de caracteres que podem ser lidos. O terceiro parâmetro é um ponteiro para o arquivo que será lido.

### Exemplo: lendo com a função fgets()

Neste exemplo, o arquivo "arquivo.txt" é aberto para leitura. Em seguida, uma linha do arquivo é lida e armazenada na string str. Por fim, o arquivo é fechado. Portanto, considerando que o arquivo "arquivo.txt" contenha apenas a linha "Hello World!", o programa imprimirá na tela a string "Hello World!".

```c
#include <stdio.h>

int main() {
    FILE *fp;
    char str[100];

    fp = fopen("arquivo.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fgets(str, 100, fp); // Lê uma linha do arquivo fp e armazena na string str com no máximo 100 caracteres
    printf("%s", str); // Imprime a string lida
    fclose(fp);

    return 0;
}
```

### fputs()

A função fputs() é usada para escrever uma string em um arquivo.

```c
int fputs(const char *str, FILE *fp);
```

O primeiro parâmetro é a string que será escrita. O segundo parâmetro é um ponteiro para o arquivo que será escrito.

### Exemplo: escrevendo com a função fputs()

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
    fputs("Hello World!", fp); // Escreve a string "Hello World!" no arquivo apontado por fp
    fclose(fp);

    return 0;
}
```

### fprintf()

A função fprintf() é usada para escrever uma string formatada em um arquivo.

```c

int fprintf(FILE *fp, const char *format, ...);
```

O primeiro parâmetro é um ponteiro para o arquivo que será escrito. O segundo parâmetro é a string formatada que será escrita.

### Exemplo: escrevendo com a função fprintf()

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
    fprintf(fp, "Hello World!"); // Escreve a string "Hello World!" no arquivo apontado por fp
    fclose(fp);

    return 0;
}
```

### fscanf()

A função fscanf() é usada para ler uma string formatada de um arquivo.

```c
int fscanf(FILE *fp, const char *format, ...);
```

O primeiro parâmetro é um ponteiro para o arquivo que será lido. O segundo parâmetro é a string formatada que será lida.

### Exemplo: lendo com a função fscanf()

Neste exemplo, o arquivo "arquivo.txt" é aberto para leitura. Em seguida, uma string formatada é lida do arquivo e armazenada na string str. Por fim, o arquivo é fechado. Portanto, considerando que o arquivo "arquivo.txt" contenha apenas a string "Hello World!", o programa imprimirá na tela a string "Hello World!".

```c
#include <stdio.h>

int main() {
    FILE *fp;
    char str[100];

    fp = fopen("arquivo.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fscanf(fp, "%s", str); // Lê uma string formatada do arquivo fp e armazena na string str
    printf("%s", str); // Imprime a string lida
    fclose(fp);

    return 0;
}
```

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



1.  (Aula 01) [Funções usadas na manipulação de arquivos texto em C](https://github.com/roscibely/algorithms-and-data-structure/blob/main/root/arquivos/manipular_arquivos.c)

2. Prática 01 ✅[(clique aqui para ver as questões)](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/root/arquivos/quest%C3%B5es-pr%C3%A1tica-01-arquivos.pdf):  
   1️⃣ [Acesse a resposta em C da questão 1](https://github.com/roscibely/algorithms-and-data-structure/blob/main/root/arquivos/pratica-01-questao-1.c) 
   1️⃣ [Acesse a resposta em Python da questão 1](https://github.com/roscibely/data-structure-with-python/blob/main/root/arquivos/pratica_q1.py) 
    
   2️⃣ [Acesse a resposta em C da questão 2](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/root/arquivos/pratica-01-questao-2.c) 
   2️⃣ [Acesse a resposta em Python da questão 2](https://github.com/roscibely/data-structure-with-python/blob/main/root/arquivos/pratica-q2.py) 
