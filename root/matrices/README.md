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

## Função para alocar dinamicamente uma matriz

Você pode criar uma função para alocar dinamicamente uma matriz. 
```c
int **alocaMatriz(int linhas, int colunas) {
    int **matriz = (int **) malloc(linhas * sizeof(int *)); 
    for (int i = 0; i < linhas; i++) { 
        matriz[i] = (int *) malloc(colunas * sizeof(int));
    }
    return matriz;
}
```
A função acima recebe o número de linhas e o número de colunas da matriz e retorna a matriz alocada dinamicamente.

### Liberação da memória

Para liberar a memória alocada dinamicamente para uma matriz, podemos fazer da seguinte forma:

```c
for (int i = 0; i < 3; i++) { // libera as colunas
    free(matriz[i]);
}
free(matriz); // libera as linhas
```

## Passando matrizes para funções

Para passar uma matriz para uma função, devemos passar o número de linhas e o número de colunas da matriz. Por exemplo, para passar uma matriz de 3 linhas e 3 colunas para uma função, podemos fazer da seguinte forma:

```c
void imprimeMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
```

A função acima recebe uma matriz de inteiros, o número de linhas e o número de colunas da matriz. Em seguida, ela imprime a matriz na tela.

## Exemplo: Soma de matrizes

Para somar duas matrizes, devemos percorrer as duas matrizes e somar os elementos de mesma posição. Por exemplo, para somar as matrizes abaixo:

```c
int matriz1[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int matriz2[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

Podemos fazer da seguinte forma:

```c

int matriz3[3][3];

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
    }
}
```

Com alocação dinâmica:

```c
int colunas = 3;
int linhas = 3;

int **matriz1 = (int **) malloc(linhas * sizeof(int *)); // aloca as linhas
for (int i = 0; i < 3; i++) { // aloca as colunas
    matriz1[i] = (int *) malloc(colunas * sizeof(int));
}

int **matriz2 = (int **) malloc(linhas * sizeof(int *)); // aloca as linhas
for (int i = 0; i < 3; i++) { // aloca as colunas
    matriz2[i] = (int *) malloc(colunas * sizeof(int));
}

int **matriz3 = (int **) malloc(linhas * sizeof(int *)); // aloca as linhas
for (int i = 0; i < 3; i++) { // aloca as colunas
    matriz3[i] = (int *) malloc(colunas * sizeof(int));
}

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
    }
}
```

## Exemplos realizados em sala de aula 

[Exemplo 1](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/matrices/exemplo_aula.c): Nomes completos 

[Exemplo 2](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/matrices/frutas_exemplo.c): Frutas e Preços


## Exercícios



Questão 1) Escreva um programa que calcula a soma de duas matrizes MxN, considerando matrizes quadradas. As dimensões deve ser fornecidas pelo o usuário. Use alocação dinâmica e escreva uma função que somará as matrizes; [Acesse a resposta](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/matrices/question-1.c)


Questão 2) Escreva um programa que aloque dinamicamente uma matriz de inteiros definida pelo o usuário. Em seguida, implemente uma função que receba um valor, retorne 1, caso esteja na matriz ou retorne 0 caso não esteja. Dica: implemente uma função que faz essa verificaçã. [Acesse a resposta](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/matrices/question-2.c)
