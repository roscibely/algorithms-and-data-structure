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

## Ponteiros para Ponteiros

Um ponteiro para ponteiro é um ponteiro que aponta para outro ponteiro. Isto é, um ponteiro que aponta para um endereço de memória que contém outro endereço de memória. Isso é útil quando precisamos manipular uma estrutura de dados complexa.

```c

int x = 10;
int *p = &x;
int **pp = &p;

printf("%d", **pp); //Acessamos o valor de x com **pp (conteúdo do conteúdo de pp)
```

## Ponteiros e Funções

Podemos também declarar ponteiros de funções. Isso é útil quando precisamos passar uma função como parâmetro para outra função.

```c

int soma(int a, int b) {
    return a + b;
}

int (*p)(int, int) = soma; /* Declaração de um ponteiro para função que recebe dois inteiros e retorna um inteiro */

printf("%d", p(1, 2));
```

Um ponteiro para função pode ser usado para criar uma função que recebe outra função como parâmetro.

```c

float (*ponteiro_para_funcao)(int, int); // Ponteiro para função que recebe dois inteiros e retorna um float
```

# Exemplo: Função que recebe outra função como parâmetro


```c
float media(int a, int b) {
    return (a + b) / 2.0;
}

void calcula(int a, int b, float (*ponteiro_para_funcao)(int, int)) {
    printf("%f", ponteiro_para_funcao(a, b));
}

int main(void){
    calcula(1, 2, media);
    return 0;
}

```






Links recomendados para estudo:

[1] [clique aqui](https://www.treinaweb.com.br/blog/ponteiros-em-c-uma-abordagem-basica-e-inicial)

[2] CELES, Waldemar; CERQUEIRA, Renato; RANGEL, José. Introdução a estruturas de dados: com técnicas de programação em C.
