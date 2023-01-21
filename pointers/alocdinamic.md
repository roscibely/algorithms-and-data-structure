# Alocação dinâmica 

## O que é alocação dinâmica?

A alocação dinâmica é um processo de alocar memória em tempo de execução. 

## Para que serve? 

A alocação dinâmica é útil quando não sabemos o tamanho de um vetor ou quando queremos alocar memória para um vetor de tamanho variável.

Na linguagem C, a alocação dinâmica é feita através da função malloc, calloc e/ou realloc.

## Como funciona?

A alocação dinâmica é feita através da função malloc ou calloc.

```c

int *x = malloc(5 * sizeof(int));

```

ou, com a função calloc 

```c

int *x = calloc(5, sizeof(int));

```

A diferenciação entre as duas funções é que a função calloc inicializa cada posição do vetor com zeros.

## Desalocação de memória

Para desalocar memória, basta usar a função free.

```c

int *x = malloc(1 * sizeof(int));

x[0] = 1;

free(x);

```

## Realocação de memória

A função realloc é usada para realocar memória. Ela recebe como parâmetro um ponteiro para um bloco de memória já alocado e um inteiro que representa o novo tamanho do bloco de memória. Usa-se a função realloc quando queremos aumentar ou diminuir o tamanho de um bloco de memória já alocado.

```c

int *x = malloc(1 * sizeof(int)); // x tem tamanho 1



x = realloc(x, 2 * sizeof(int)); // Agora x tem tamanho 2



```