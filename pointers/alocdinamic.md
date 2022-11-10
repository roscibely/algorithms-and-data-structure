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

## Desalocação de memória

Para desalocar memória, basta usar a função free.

```c

int *x = malloc(1 * sizeof(int));

x[0] = 1;

free(x);

```