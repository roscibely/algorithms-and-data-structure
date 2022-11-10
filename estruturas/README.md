# Estruturas de dados na linguagem C 

## O que é uma estrutura de dados?

Uma estrutura de dados é uma forma de organizar dados em um programa.

## Para que serve?

Estruturas de dados são úteis para organizar dados de forma que seja fácil acessá-los.

## Como funciona?

Estruturas de dados são definidas através de structs.

```c

struct pessoa {
    char nome[50];
    int idade;
};

```

## Acesso aos valores de uma estrutura

Para acessar os valores de uma estrutura, basta usar o operador de acesso (.) e o nome da variável.

```c

struct pessoa p;

p.idade = 20;
p.nome = "João";

```

## Acesso ao endereço de uma estrutura

Para acessar o endereço de uma estrutura, basta colocar um & antes do nome da variável.

```c

struct pessoa p;

printf("%d", &p);

```

## Ponteiros e Estruturas

Uma estrutura é um ponteiro para a primeira variável da estrutura.

```c

struct pessoa p;

struct pessoa *p = &p;

printf("%d", *p);

```

## Alocação Dinâmica de Estruturas

Para alocar dinamicamente uma estrutura, basta usar a função malloc.

```c

struct pessoa *p = malloc(sizeof(struct pessoa));

p->idade = 20;
p->nome = "João";

printf("%d", p->idade);

```

## Desalocação de Estruturas

Para desalocar uma estrutura, basta usar a função free.

```c

struct pessoa *p = malloc(sizeof(struct pessoa));

free(p);

```

## Exercícios


![](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/estruturas/struct.png)


## Questões 

1) Crie um tipo estruturado para representar uma conta bancária, cujos campos são: o nome do
cliente, o número da conta e um saldo. Crie uma variável do tipo estrutura e escreva instruções
para inicializar seus campos. Em seguida, implemente uma função para realizar um depósito em
uma estrutura do tipo struct contaBancaria. Sua função deve obedecer ao seguinte protótipo:
void deposita(float valor, struct contaBancaria* conta); [Acessar resposta](https://github.com/roscibely/algorithms-and-data-structure/blob/main/estruturas/conta-bancaria.c)
