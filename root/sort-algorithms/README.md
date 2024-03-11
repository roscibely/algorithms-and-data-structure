Dado o seguinte algoritmo:

```c
void algoritmo(int * vetor, int tamanho){
    int index, key, count;
    for (index = 1; index < tamanho; index++) {
        key = vetor[index];
        count = index - 1;
        while (count >= 0 && vetor[count] > key) {
            vetor[count + 1] = vetor[count];
            count-=1;
        }
        vetor[count + 1] = key;
    }
}
```

Esse algoritmo é uma implementação do algoritmo de ordenação por inserção (_insertion sort_). Vamos analisar sua complexidade:

- No melhor caso, o vetor já está ordenado. Nesse caso, a condição do `while` nunca será verdadeira, e a cada iteração do loop externo, apenas uma comparação será feita para verificar se `index` é menor que `tamanho`, e uma atribuição de `key` será feita. Assim, a complexidade será aproximadamente O(n), onde n é o tamanho do vetor.

- No pior caso, o vetor está ordenado de forma inversa. Isso significa que, em cada iteração do loop externo, o elemento atual precisa ser movido para a primeira posição do vetor. Isso envolve deslocar todos os elementos anteriores a ele para frente. Portanto, no pior caso, cada iteração do loop externo pode envolver até 'index' comparações e movimentos. Assim, a complexidade será quadrática, $O(n^2)$.

Podemos representar a complexidade do algoritmo de ordenação por inserção em termos de tempo como:

$$ O(n^2) $$ 

Isso se dá porque, no pior caso, a cada elemento do vetor, precisamos percorrer todos os elementos anteriores a ele, resultando em um comportamento quadrático.

Então, para resumir:

- Melhor caso: $O(n)$
- Pior caso: $O(n^2)$

## Exemplo 

O seguinte programa `main` faz o uso da função definida anteriormente. 

```c
void main(){
    int v[3] = { 12,13, 11};
    algoritmo(v, 3);
    int i;
    for(i=0;i<3;i++){
        printf("%d\t", v[i]);
    }
}
```

* Qual a saída do programa? Explique mostrando os valores assumidos pelas variáveis durante a execução do programa.


A saída do programa será:

11 12 13 


Explicação passo a passo:

1. Inicialização do vetor `v` com os valores `{12, 13, 11}`.
2. Chamada da função `algoritmo(v, 3)` para ordenar o vetor.
3. Na primeira iteração do algoritmo de ordenação por inserção:
   - `index` é 1, `key` é 13 e `count` é 0.
   - Como `vetor[count] (v[0]) > key`, o elemento 12 é deslocado uma posição para a direita.
   - O vetor fica `{13, 13, 11}`.
4. Na segunda iteração:
   - `index` é 2, `key` é 11 e `count` é 1.
   - Como `vetor[count] (v[1]) > key`, o elemento 13 é deslocado uma posição para a direita.
   - `vetor` se torna `{12, 13, 13}`.
   - Como `vetor[count - 1] (v[0]) > key`, o elemento 12 é deslocado uma posição para a direita.
   - Finalmente, o `vetor[count + 1]` (v[1]) recebe o valor de `key`, resultando em `{11, 12, 13}`.
5. O loop termina e o vetor é impresso usando o loop `for`:
   - A saída é `11    12    13`.

