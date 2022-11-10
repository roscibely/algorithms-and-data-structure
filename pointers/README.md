# Introdução a Ponteiros na Linguagem C 

## Ponteiros

Um ponteiro é uma variável que armazena o endereço de outra variável.

## Declaração de Ponteiros

Para declarar um ponteiro, basta colocar um asterisco antes do nome da variável.

```c
int *p;
```

## Atribuição de Ponteiros

Para atribuir um ponteiro, basta colocar o endereço da variável que ele apontará.

```c

int x = 10;
int *p = &x;
```

## Acesso ao Valor de um Ponteiro

Para acessar o valor de um ponteiro, basta colocar um asterisco antes do nome da variável.

```c

int x = 10;
int *p = &x;

printf("%d", *p);
```

## Acesso ao Endereço de um Ponteiro

Para acessar o endereço de um ponteiro, basta colocar um & antes do nome da variável.

```c

int x = 10;
int *p = &x;

printf("%d", &p);
```

## Ponteiros e Vetores

Um vetor é um ponteiro para o primeiro elemento do vetor.

```c

int x[5] = {1, 2, 3, 4, 5};
int *p = x;

printf("%d", *p);
```




Links recomendados para estudo:

[1] [clique aqui](https://www.treinaweb.com.br/blog/ponteiros-em-c-uma-abordagem-basica-e-inicial)

[2] CELES, Waldemar; CERQUEIRA, Renato; RANGEL, José. Introdução a estruturas de dados: com técnicas de programação em C.
