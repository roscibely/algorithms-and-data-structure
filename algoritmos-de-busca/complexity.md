# Complexidade de Algoritmos 

## O que é complexidade de algoritmos?

Complexidade de algoritmos é uma medida de desempenho de um algoritmo. É uma medida de tempo e espaço de memória que um algoritmo consome para executar uma tarefa.

## Como medir a complexidade de algoritmos?

Existem duas formas de medir a complexidade de algoritmos:

- Tempo de execução
- Espaço de memória

### Tempo de execução

O tempo de execução de um algoritmo é a quantidade de tempo que o algoritmo leva para executar uma tarefa. Para medir o tempo de execução de um algoritmo, é necessário executar o algoritmo com diferentes entradas e calcular o tempo de execução para cada entrada. O tempo de execução de um algoritmo é a soma dos tempos de execução para cada entrada.

### Espaço de memória

O espaço de memória de um algoritmo é a quantidade de memória que o algoritmo consome para executar uma tarefa. Para medir o espaço de memória de um algoritmo, é necessário executar o algoritmo com diferentes entradas e calcular o espaço de memória para cada entrada. O espaço de memória de um algoritmo é a soma dos espaços de memória para cada entrada.

## Como calcular a complexidade de algoritmos?

Existem duas formas de calcular a complexidade de algoritmos:

- Complexidade de tempo

- Complexidade de espaço

### Complexidade de tempo

A complexidade de tempo de um algoritmo é denotada por T(n), em que n é o tamanho da entrada. A complexidade de tempo de um algoritmo é a quantidade de tempo que o algoritmo leva para executar uma tarefa com uma entrada de tamanho n. 

Normalmente, utilizamos a notação big-O para denotar a complexidade de tempo de um algoritmo. A notação big-O denota o limite superior da complexidade de tempo de um algoritmo. 

Por exemplo, se T(n) = 2n + 1, então T(n) = O(n).

### Complexidade de espaço

A complexidade de espaço de um algoritmo é denotada por S(n), em que n é o tamanho da entrada. A complexidade de espaço de um algoritmo é a quantidade de memória que o algoritmo consome para executar uma tarefa com uma entrada de tamanho n.

Normalmente, utilizamos a notação big-O para denotar a complexidade de espaço de um algoritmo. A notação big-O denota o limite superior da complexidade de espaço de um algoritmo. 


### Exemplo de complexidade de tempo: 

```c
int soma(int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += i;
    }
    return soma;
}
```

O algoritmo acima calcula a soma dos números de 0 até n-1. A complexidade de tempo de soma(n) é O(n). Pois, o algoritmo executa n operações de soma e n operações de comparação. Já que o algoritmo executa n operações de soma e n operações de comparação, o tempo de execução do algoritmo é proporcional a n. 

A complexidade de espaço de soma(n) é O(1). Pois, o algoritmo consome uma quantidade constante de memória. 