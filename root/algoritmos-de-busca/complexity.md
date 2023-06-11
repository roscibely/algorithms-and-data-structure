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

### Exemplo de complexidade de tempo linear: 

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

### Exemplo de complexidade de tempo quadrática: 

```c
int soma(int n) {
    int soma = 0; // c1, 1 vez
    for (int i = 0; i < n; i++) { // c2, n vezes
        for (int j = 0; j < n; j++) { // c3, n*n vezes
            soma += i * j; // c4,  n*n vezes
        }
    }
    return soma; // c5 1 vez
}
```

Podemos multiplicar a execução de cada linha pelo tempo que leva para executar essa linha. Então, o tempo total de execução será a soma de todos os tempos de execução de cada linha. 

$$
T(n) = c1 + c2n + c3n^2 + c4n^2 + c5
$$

ou ainda

$$
T(n) = (c1 + c5) + c2n + (c3 + c4)n^2
$$

Chamamos esse modelo de modelo quadrático porque N está elevado a 2. Algoritmos com complexidade quadrática quadruplicam o tempo de execução quando os dados são duplicados.

Portanto, o algoritmo acima calcula a soma dos produtos de todos os pares de números de 0 até n-1. A complexidade de tempo de soma(n) é O(n^2). Pois, o algoritmo executa n^2 operações de soma e n^2 operações de comparação. Já que o algoritmo executa n^2 operações de soma e n^2 operações de comparação, o tempo de execução do algoritmo é proporcional a n^2.

## Simplificando ainda mais

Até agora, analisamos algoritmos com apenas algumas linhas de código, para que os cálculos não ficassem extremamente complexos. No entanto, à medida que os algoritmos se tornam mais complicados, esse processo pode se tornar bastante complexo e complicado.

Além disso, lembre-se de que estamos interessados apenas em ver quanto o tempo de execução cresce à medida que os dados crescem, não o tempo exato de execução. Com isso em mente, podemos simplificar ainda mais nossa análise descartando informações desnecessárias.

1. Remova termos constantes

Seja T(n) = 2n + 1. Podemos remover o termo constante 1, pois ele não afeta o crescimento do tempo de execução. Portanto, T(n) = O(2n).

2. Remova constantes multiplicativas

Seja T(n) = 2n + 1. Podemos remover a constante multiplicativa 2, pois ela não afeta o crescimento do tempo de execução. Portanto, T(n) = O(n).

3. Remova termos de menor ordem

Seja T(n) = n^2 + n. Podemos remover o termo de menor ordem n, pois ele não afeta o crescimento do tempo de execução. Portanto, T(n) = O(n^2).

4. Mantenha apenas o termo de maior ordem

Seja T(n) = n^3 + n^2 + n + 1. Podemos remover todos os termos de menor ordem, pois eles não afetam o crescimento do tempo de execução. Portanto, T(n) = O(n^3).


### Complexidade de espaço

A complexidade de espaço de um algoritmo é denotada por S(n), em que n é o tamanho da entrada. A complexidade de espaço de um algoritmo é a quantidade de memória que o algoritmo consome para executar uma tarefa com uma entrada de tamanho n.

Normalmente, utilizamos a notação big-O para denotar a complexidade de espaço de um algoritmo. A notação big-O denota o limite superior da complexidade de espaço de um algoritmo. 


