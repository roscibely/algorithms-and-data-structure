
# Union 

### Definição:

A estrutura de dados union é uma estrutura de dados que permite armazenar diferentes tipos de dados em um mesmo espaço de memória. A estrutura de dados union é semelhante a estrutura de dados struct, mas a estrutura de dados union armazena apenas um tipo de dado por vez. A estrutura de dados union é definida da seguinte forma:

```c
union nome_da_union {
    tipo_de_dado1 nome_do_campo1;
    tipo_de_dado2 nome_do_campo2;
    ...
    tipo_de_dadon nome_do_campon;
};
```

### Exemplo de declaração de union:

```c
union uniao{
    int inteiro;
    float real;
    char caractere;
};

union uniao u; // declara a variável u do tipo union uniao


u.inteiro = 10; // armazena o valor 10 na variável inteiro
u.real = 10.5; // armazena o valor 10.5 na variável real
u.caractere = 'a'; // armazena o valor 'a' na variável caractere
```
No exemplo acima, a variável u pode armazenar um valor inteiro, um valor real ou um caractere. A variável u armazena apenas um tipo de dado por vez. Se a variável u armazenar um valor inteiro, então o valor real e o caractere são descartados. Se a variável u armazenar um valor real, então o valor inteiro e o caractere são descartados. Se a variável u armazenar um caractere, então o valor inteiro e o valor real são descartados. 

Dessa forma, como no exemplo acima a última atribuição feita na variável u foi a atribuição do caractere 'a', então a variável u armazena o caractere 'a', e os valores 10 e 10.5 são descartados.



### Exemplo de declaração de union:


![](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/estruturas/union/union.png)
