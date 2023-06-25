# Medindo o tempo de execução de um algoritmo em C 

Intuitivamente, podemos dizer que o tempo de execução de um algoritmo é a quantidade de tempo que o algoritmo leva para executar uma tarefa. Para medir o tempo de execução de um algoritmo, é necessário executar o algoritmo com diferentes entradas e calcular o tempo de execução para cada entrada. O tempo de execução de um algoritmo é a soma dos tempos de execução para cada entrada.

Para medir o tempo de execução de um algoritmo em C, podemos utilizar a função `clock()` do header `time.h`. A função `clock()` retorna o tempo de execução do programa em milissegundos. Para calcular o tempo de execução de um algoritmo, podemos utilizar a seguinte fórmula:

```c
double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
```

Onde `inicio` é o tempo de execução do programa antes de executar o algoritmo e `tempo` é o tempo de execução do programa após executar o algoritmo.

A seguir, temos um exemplo de como medir o tempo de execução de um algoritmo em C:

```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio = clock();
    // Executar o algoritmo
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", tempo);
    return 0;
}
```

# Analisando o tempo de execução de um algoritmo

Com o modelo de complexidade de tempo, podemos inserir um comprimento de lista e ter uma ideia do tempo de execução do algoritmo para esse comprimento de entrada sem precisar realmente executar o código.

## Modelo de complexidade de tempo

O modelo de complexidade de tempo é uma representação matemática de um algoritmo. O modelo de complexidade de tempo de um algoritmo é denotado por T(n), em que n é o tamanho da entrada. O modelo de complexidade de tempo de um algoritmo é a quantidade de tempo que o algoritmo leva para executar uma tarefa com uma entrada de tamanho n.

## Análise de tempo de execução

Na análise de tempo de execução, nós não queremos o tempo exato, e sim como o tempo de execução de um algoritmo cresce com o tamanho da entrada. Para analisar o tempo de execução de um algoritmo, podemos utilizar o modelo de complexidade de tempo.

Exemplo: Soma de todos os números de 1 a n

```c    

int soma(int n) {
    int soma = 0;  //c1
    for (int i = 1; i <= n; i++) { //c2
        soma += i; //c3
    }
    return soma; //c4
}
```

Os comentários acima significam que a primeira linha leva algum tempo constante c1 para ser executada. O segundo leva c2 e assim por diante. Então podemos contar quantas vezes cada linha será executada. Isso dependerá do tamanho de n. Vamos denotar esse tamanho por N e escrever a contagem de execução de cada linha na frente dele: 

```c
int soma(int n) {
    int soma = 0;  //c1, 1 vez
    for (int i = 1; i <= n; i++) { //c2, N vezes
        soma += i; //c3, N vezes
    }
    return soma; //c4, 1 vez
}
```

Podemos multiplicar a execução de cada linha pelo tempo que leva para executar essa linha. Então, o tempo total de execução será a soma de todos os tempos de execução de cada linha. 

$$ 
T(n) = c1 + c2N + c3N + c4 
$$ 

ou ainda 

$$
T(n) =  (c2 + c3)N + (c1 + c4)
$$ 

Agora, podemos ver que o tempo de execução cresce linearmente com o tamanho da entrada.

## [Complexidade de Algoritmos](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/root/algoritmos-de-busca/complexity.md)
