# Enum

## Definição

A estrutura de dados enum é uma estrutura de dados que permite armazenar um conjunto de valores inteiros. A estrutura de dados enum é definida da seguinte forma:

```c
enum nome_da_enum {
    valor1,
    valor2,
    ...
    valorn
};
```

### Exemplo de declaração de enum:

```c
enum dias_semana {
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO
};
```

No exemplo acima, a variável dias_semana pode armazenar os valores inteiros 0, 1, 2, 3, 4, 5 e 6. O valor 0 é atribuído ao valor SEGUNDA, o valor 1 é atribuído ao valor TERCA, o valor 2 é atribuído ao valor QUARTA, o valor 3 é atribuído ao valor QUINTA, o valor 4 é atribuído ao valor SEXTA, o valor 5 é atribuído ao valor SABADO e o valor 6 é atribuído ao valor DOMINGO.


### Exemplo de declaração de enum:
![](https://github.com/roscibely/algorithms-and-data-structure/blob/develop/estruturas/enum/enum.png)


### Exemplo

```c
#include <stdio.h>

enum dias_semana {
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO
};

int main() {
    enum dias_semana dia;
    dia = SEGUNDA;
    printf("Dia da semana: %d\n", dia);
    return 0;
}
```

Neste exemplo, a variável dia é declarada como um tipo enum dias_semana. A variável dia é inicializada com o valor SEGUNDA. O valor de dia é impresso na tela. O valor de dia é 0, pois o valor SEGUNDA é 0.