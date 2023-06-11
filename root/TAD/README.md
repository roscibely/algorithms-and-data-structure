# Tipos Abstrato de Dados (TAD) na Linguagem C

## O que é um TAD?

Um TAD é um tipo de dado abstrato, ou seja, um tipo de dado que não é definido na linguagem C, mas que pode ser utilizado para representar um tipo de dado abstrato. 

## Para que serve?

TADs são úteis para representar tipos de dados abstratos.

## Como funciona?

TADs são definidos através de structs.

```c

struct pessoa {
    char nome[50];
    int idade;
};

struct pessoa joao;

```

Para criar um TAD, precisamos criar uma struct que contenha os dados que queremos representar. Um arquivo que contenha uma struct é chamado de arquivo de cabeçalho (.h). E um arquivo que contenha a implementação de uma struct é chamado de arquivo de implementação (.c). Portanto, para criar um TAD, precisamos criar um arquivo de cabeçalho e um arquivo de implementação. 

## Exemplo: TAD pessoa 

### Arquivo de cabeçalho (pessoa.h)



```c

typedef struct pessoa Pessoa;

Pessoa* cria_pessoa(char nome[50], int idade);

void imprime_pessoa(Pessoa *p);

```

### Arquivo de implementação (pessoa.c)



```c

#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

struct pessoa {
    char nome[50];
    int idade;
};

Pessoa* cria_pessoa(char nome[50], int idade) {
    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
    p->idade = idade;
    strcpy(p->nome, nome);
    return p;
}

void imprime_pessoa(Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
}

```

## Arquivo principal (main.c)


```c

#include <stdio.h>
#include "pessoa.h"

int main() {
    Pessoa *p = cria_pessoa("João", 20);
    imprime_pessoa(p);
    return 0;
}

```



