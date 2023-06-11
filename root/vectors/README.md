# Alocação dinâmica de Vetores 

# Introdução a vetores 

## Vetores

Um vetor é uma variável que armazena vários valores do mesmo tipo.

## Declaração de Vetores

Para declarar um vetor, basta colocar colchetes depois do nome da variável.

```c
int x[5];
```

## Atribuição de Vetores

Para atribuir um vetor, basta colocar os valores entre chaves.

```c

int x[5] = {1, 2, 3, 4, 5};
```

## Acesso aos Valores de um Vetor

Para acessar os valores de um vetor, basta colocar o índice entre colchetes.

```c

int x[5] = {1, 2, 3, 4, 5};

printf("%d", x[0]);
```

## Acesso ao Endereço de um Vetor

Para acessar o endereço de um vetor, basta colocar um & antes do nome da variável.

```c

int x[5] = {1, 2, 3, 4, 5};

printf("%d", &x);
```

## Ponteiros e Vetores

Um vetor é um ponteiro para o primeiro elemento do vetor.

```c

int x[5] = {1, 2, 3, 4, 5};

int *p = x;

printf("%d", *p);
```

## Alocação Dinâmica de Vetores

Para alocar dinamicamente um vetor, basta usar a função malloc.

```c

int *x = malloc(5 * sizeof(int));

x[0] = 1;
x[1] = 2;
x[2] = 3;
x[3] = 4;
x[4] = 5;

printf("%d", x[0]);
```

## Desalocação de Vetores

Para desalocar um vetor, basta usar a função free.

```c

int *x = malloc(1 * sizeof(int));

x[0] = 1;

free(x);
```

## Funçãp realloc 

A função realloc é usada para realocar um vetor.

```c

int *x = malloc(1 * sizeof(int));

x[0] = 1;

x = realloc(x, 5 * sizeof(int));

x[1] = 2;
x[2] = 3;
x[3] = 4;
x[4] = 5;

printf("%d", x[0]);
```

## Função calloc 

A função calloc é usada para alocar um vetor e inicializar todos os valores com 0.

```c

int *x = calloc(5, sizeof(int));

printf("%d", x[0]);
```

<div>
  <img src="https://github.com/roscibely/algorithms-and-data-structure/blob/develop/vectors/vetores.png" width="350" height="300">
  <img src="https://github.com/roscibely/algorithms-and-data-structure/blob/main/vectors/vetor-alocacao-dinamica.png" width="350" height="300">
</div>

#### Nota: Tente primeiro fazer seu código e só depois disso acesse a possível resposta. 
*Questão 1)* Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de tamanho n e retorne quantos números pares estão
armazenados nesse vetor. Essa função deve obedecer ao protótipo: int pares(int n, int* vet); [Acesse a resposta](https://github.com/roscibely/algorithms-and-data-structure/blob/main/vectors/question-1.c)


*Questão 2)* Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
produto (gostou/não gostou). Escreva um programa em C que:

   * a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados, um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta para a segunda pergunta.
  *  b) determine a porcentagem de pessoas do sexo feminino que responderam que gostaram do produto.
  *  c) determine a porcentagem de pessoas do sexo masculino que responderam que não gostaram do produto. 
   [Acesse a resposta](https://github.com/roscibely/algorithms-and-data-structure/blob/main/vectors/question-2.c)

*Questão 3)* Implemente uma função que preencha um vetor de N elementos com valores
inteiros fornecidos via teclado, de modo que, à medida que um novo elemento
é inserido, o vetor já permaneça organizado de maneira ordenada crescente.
Escreva um programa que utiliza esta função, que deve obedecer ao seguinte
protótipo: void preenche_ordenado(int n, int* vet); [Acesse a resposta](https://github.com/roscibely/algorithms-and-data-structure/blob/main/vectors/question-3.c)
