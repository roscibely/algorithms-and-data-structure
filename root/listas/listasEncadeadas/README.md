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
// criaremos uma estrutura em que essa estrutura terá o nome da fruta e o endereço da estrutura da próxima fruta 
struct Fruta {
    char nome[20]; // nome da fruta
    struct Fruta* proxima; // endereço da próxima fruta
};

int main() {
    // Vamos criar 3 structs Fruta para nossa lista de frutas
    // Criar os elementos da lista
    struct Fruta* fruta1 = (struct Fruta*)malloc(sizeof(struct Fruta));
    struct Fruta* fruta2 = (struct Fruta*)malloc(sizeof(struct Fruta));
    struct Fruta* fruta3 = (struct Fruta*)malloc(sizeof(struct Fruta));

    // Atribuir os valores das frutas
    strcpy(fruta1->nome, "maçã");
    strcpy(fruta2->nome, "banana");
    strcpy(fruta3->nome, "laranja");
    // Precisamos agora conectar os elementos da nossa lista de frutas
    // Para isso vamos encadear/conectar os elementos da lista encadeada
    fruta1->proxima = fruta2; // o endereço da próxima fruta que a fruta 1 vai armazenar é o endereço da fruta2
    fruta2->proxima = fruta3; // o endereço da próxima fruta que a fruta 2 vai armazenar é o endereço da fruta3
    fruta3->proxima = NULL; // o endereço da próxima fruta que a fruta 3 vai armazenar é NULL, pois não existe próxima fruta

   // Liberar a memória alocada
    free(fruta1);
    free(fruta2);
    free(fruta3);

    return 0;
    }
```

Podemos simplificar nosso exemplo acima criando uma função para alocar e encadear os elementos da nossa lista. 

```c
struct Fruta {
    char nome[20]; // nome da fruta
    struct Fruta* proxima; // endereço da próxima fruta
};

// Função para criar e encadear os elementos da lista
struct Fruta* insere(struct Fruta* fruta, char nome[20]) {
    /*A função recebe como parâmetros: 
    struct Fruta* fruta: o endereço da lista de fruta (nossa lista existente)
    char nome[20]: o nome da fruta que será inserida na lista    
    */
    struct Fruta* novaFruta = (struct Fruta*)malloc(sizeof(struct Fruta));
    strcpy(novaFruta->nome, nome);
    novaFruta->proxima = fruta;
    return novaFruta;
}

// Nossa main pode ser simplificada para:
int main() {
    // Criar os elementos da lista
    struct Fruta* fruta = NULL; // lista vazia
    fruta = insere(fruta, "maçã"); // insere a fruta maçã na lista
    fruta = insere(fruta, "banana"); // insere a fruta banana na lista
    fruta = insere(fruta, "laranja"); // insere a fruta laranja na lista

    // Liberar a memória alocada
    free(fruta);

    return 0;
    }
```


Podemos ter listas encadeadas de qualquer tipo de dado, inclusive listas encadeadas de listas encadeadas.

## Exemplo de lista encadeada para inteiros:

```c 
struct lista_inteiro {
    int dado; // veja que o dado armaenado é do tipo inteiro
    struct lista_inteiro *prox;
};
```

Veja que para representar uma lista encadeada de inteiros, precisamos criar uma estrutura que armazena um inteiro e o endereço do próximo elemento da lista.

### Para criar uma lista encadeada, é necessário criar um ponteiro para o primeiro elemento da lista, que será o primeiro elemento da lista. Para isso, é necessário criar uma função que aloca memória para o primeiro elemento da lista e retorna o endereço do primeiro elemento da lista.

```c
struct lista_inteiro* cria_lista() {
    struct lista_inteiro* lista = (struct lista_inteiro*)malloc(sizeof(struct lista_inteiro));
    lista->prox = NULL;
    return lista;
}
```

### Para inserir um elemento na lista, é necessário criar uma função que aloca memória para o novo elemento da lista e retorna o endereço do novo elemento da lista. 

```c
struct lista_inteiro* insere(struct lista_inteiro* lista, int dado) {
    struct lista_inteiro* novo = (struct lista_inteiro*)malloc(sizeof(struct lista_inteiro));
    novo->dado = dado;
    novo->prox = lista;
    return novo;
}
```
