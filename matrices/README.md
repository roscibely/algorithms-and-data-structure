# Matrizes com alocação dinâmica 

## Introdução

Matrizes são estruturas de dados que armazenam dados em linhas e colunas. A matriz é uma estrutura de dados bidimensional, ou seja, ela possui duas dimensões. A primeira dimensão é a linha e a segunda dimensão é a coluna. A matriz é uma estrutura de dados muito utilizada em algoritmos e estruturas de dados.

## Aplicação

Uma das principais aplicações de matrizes é na representação de imagens. Uma imagem é composta por pixels, que são pontos de cor. Cada pixel é representado por uma matriz de 3 posições, onde cada posição representa uma cor. Por exemplo, uma imagem em tons de cinza é representada por uma matriz de 2 dimensões, onde cada posição representa um pixel. Uma imagem colorida é representada por uma matriz de 3 dimensões, onde cada posição representa um pixel.

## Exemplo

Podemos representar uma matriz de 3 linhas e 3 colunas da seguinte forma:

```c
int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

em que, acessamos o elemento da linha 1 e coluna 2 da seguinte forma:

```c
matriz[1][2];
```

## Alocação dinâmica

A alocação dinâmica é uma técnica utilizada para alocar memória em tempo de execução. A alocação dinâmica é muito utilizada em algoritmos e estruturas de dados, pois permite que o tamanho da estrutura seja definido em tempo de execução.

## Exemplo

Para alocar dinamicamente uma matriz de 3 linhas e 3 colunas, podemos fazer da seguinte forma:

```c
int colunas = 3;
int linhas = 3;

int **matriz = (int **) malloc(linhas * sizeof(int *)); // aloca as linhas
for (int i = 0; i < 3; i++) { // aloca as colunas
    matriz[i] = (int *) malloc(colunas * sizeof(int));
}
```

![](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/matrices/matriz.jpg)

### Liberação da memória

Para liberar a memória alocada dinamicamente para uma matriz, podemos fazer da seguinte forma:

```c
for (int i = 0; i < 3; i++) { // libera as colunas
    free(matriz[i]);
}
free(matriz); // libera as linhas
```

## Exercícios






Questão 1) Escreva um programa que calcula a soma de duas matrizes MxN, considerando matrizes quadradas. As dimensões deve ser fornecidas pelo o usuário. Use alocação dinâmica e escreva uma função que somará as matrizes; [Acesse a resposta](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/matrices/question-1.c)


Questão 2) Escreva um programa que aloque dinamicamente uma matriz de inteiros definida pelo o usuário. Em seguida, implemente uma função que receba um valor, retorne 1, caso esteja na matriz ou retorne 0 caso não esteja. Dica: implemente uma função que faz essa verificaçã. [Acesse a resposta](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/matrices/question-2.c)
