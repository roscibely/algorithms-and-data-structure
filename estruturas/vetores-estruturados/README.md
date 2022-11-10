# Vetores de Estruturas na Linguagem C 


## O que é um vetor de estruturas?

Um vetor de estruturas é um vetor que contém estruturas.

## Para que serve?

Vetores de estruturas são úteis para armazenar várias estruturas em um vetor.

## Como funciona?

Vetores de estruturas são definidos através de structs.

```c

struct pessoa {
    char nome[50];
    int idade;
};

struct pessoa pessoas[10];

```

## Acesso aos valores de um vetor de estruturas

Para acessar os valores de um vetor de estruturas, basta usar o operador de acesso (.) e o nome da variável.

```c

struct pessoa pessoas[10];

pessoas[0].idade = 20;
pessoas[0].nome = "João";

```

## Acesso ao endereço de um vetor de estruturas

Para acessar o endereço de um vetor de estruturas, basta colocar um & antes do nome da variável.

```c

struct pessoa pessoas[10];

printf("%d", &pessoas);

```

## Ponteiros e Vetores de Estruturas

Um vetor de estruturas é um ponteiro para a primeira variável do vetor.

```c

struct pessoa pessoas[10];

struct pessoa *p = &pessoas;

printf("%d", *p);

```



## Exemplo: Declaração de um vetor do tipo struct ponto dinâmicamente 
![](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/estruturas/vetores-estruturados/vetor-de-struct.png)
