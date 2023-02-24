# Recursão 

## O que é?

A recursão é um conceito matemático que consiste em uma função que se chama a si mesma. Em programação, a recursão é uma técnica que permite que uma função chame a si mesma, e que é muito utilizada para percorrer estruturas de dados como árvores e listas.

## Como funciona?

Um exemplo de função recursiva simples em C é a função fatorial, que calcula o fatorial de um número inteiro positivo n. A definição matemática do fatorial é 

$$ n! = n * (n-1) * (n-2) * ... * 2 * 1. $$

 A função fatorial pode ser implementada recursivamente em C da seguinte forma:

´´´c
    int fatorial(int n) {
        if (n == 0) {
            return 1;
        }
        return n * fatorial(n - 1);
    }
´´´

A função fatorial recebe um inteiro n como argumento e verifica se n é igual a 1. Se n for igual a 1, a função retorna 1, pois o fatorial de 1 é 1. Caso contrário, a função chama a si mesma com o argumento n-1 e multiplica o resultado pelo valor de n, retornando o resultado da multiplicação. Essa chamada recursiva continua até que a condição de parada seja atingida, ou seja, quando n for igual a 1.

Ao chamar a função fatorial com um valor de entrada, a função irá chamar a si mesma várias vezes até atingir a condição de parada e retornar o resultado final. Por exemplo, o fatorial de 5 seria calculado da seguinte forma:

´´´c
    fatorial(5) = 5 * fatorial(4)
    fatorial(4) = 4 * fatorial(3)
    fatorial(3) = 3 * fatorial(2)
    fatorial(2) = 2 * fatorial(1)
    fatorial(1) = 1 * 1 = 1
´´´
Portanto, 

´´´c
    fatorial(1) = 1 * 1 = 1
    fatorial(2) = 2 * 1 = 2
    fatorial(3) = 3 * 2 = 6
    fatorial(4) = 4 * 6 = 24
    fatorial(5) = 5 * 24 = 120
´´´






