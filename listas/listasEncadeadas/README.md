# Listas encadeadas 

### Lista encadadedas são estruturas de dados que armazenam dados de forma sequencial, mas cada elemento da lista é um objeto que contém um campo com o dado e um campo com o endereço do próximo elemento da lista.

### As listas encadeadas são estruturas de dados dinâmicas, ou seja, podem crescer e diminuir de tamanho conforme a necessidade. A princial vantagem das listas encadeadas é a facilidade de inserção e remoção de elementos, pois não é necessário deslocar os elementos da lista para inserir ou remover um elemento. 

### Além disso, não é necessário saber o tamanho da lista antes de inserir os elementos, pois a lista pode crescer conforme a necessidade. Chamos cada elemento da lista de nó, e um conjunto de nós é chamado de lista encadeada. 

## Exemplo: Considere a lista de frutas: 
```
0. maçã
1. banana
2. laranja
```
Queremos criar uma lista usando a linguagem de programação C. Podemos fazer isso da seguinte maneira: 
```c
struct Fruta {
    char nome[20];
    struct Fruta* proxima;
};

int main() {
    // Criar os elementos da lista
    struct Fruta* fruta1 = (struct Fruta*)malloc(sizeof(struct Fruta));
    struct Fruta* fruta2 = (struct Fruta*)malloc(sizeof(struct Fruta));
    struct Fruta* fruta3 = (struct Fruta*)malloc(sizeof(struct Fruta));

    // Atribuir os valores das frutas
    strcpy(fruta1->nome, "maçã");
    strcpy(fruta2->nome, "banana");
    strcpy(fruta3->nome, "laranja");

    // Construir a lista encadeada
    fruta1->proxima = fruta2;
    fruta2->proxima = fruta3;
    fruta3->proxima = NULL;

   // Liberar a memória alocada
    free(fruta1);
    free(fruta2);
    free(fruta3);

    return 0;
```


Exemplo de lista encadeada para inteiros:

```c 
struct no {
    int dado;
    struct no *prox;
};
```

### Para criar uma lista encadeada, é necessário criar um ponteiro para o primeiro elemento da lista, que será o primeiro elemento da lista. Para isso, é necessário criar uma função que aloca memória para o primeiro elemento da lista e retorna o endereço do primeiro elemento da lista.

```c
struct no *cria_lista() {
    struct no *p;
    p = (struct no *) malloc(sizeof(struct no));
    if (p != NULL) {
        p->prox = NULL;
    }
    return p;
}
```
