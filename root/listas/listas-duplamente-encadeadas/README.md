# Listas duplamente encadeadas 

 * Uma lista duplamente encadeada é uma lista que possui um ponteiro para o próximo elemento e um ponteiro para o elemento anterior. 


* Diferente da lista encadeada, a lista duplamente encadeada permite a navegação na lista em qualquer direção. Dessa forma, é possível navegar na lista tanto para frente quanto para trás. Por esse motivo, a lista duplamente encadeada é mais flexível que a lista encadeada e permite a implementação de algoritmos mais complexos. 

* Dessa forma, é necessário criar uma estrutura de dados que armazene o dado e dois ponteiros no nó, um para o próximo elemento e outro para o elemento anterior. 

 

* Implementação de uma lista duplamente encadeada para inteiros: 

 Podemos definir uma estrutura para denotar a lista com um ponteiro para o início e um ponteiro para o fim da lista, ou simplesmente trabalharmos com a estrutura do nó.
 
 ```c 
typedef struct no { 
    int valor; 
    struct no *prox; 
    struct no *ant; 
} No; 

typedef struct lista { 
    No *inicio; 
    No *fim; 
 } Lista; 
 ``` 

Veja que a estrutura do nó possui um ponteiro para o próximo elemento e um ponteiro para o elemento anterior. Diferente da lista encadeada, a lista duplamente encadeada possui um ponteiro para o início e um ponteiro para o fim da lista.

* Inicialização da lista: 

```c
void inicializaLista(Lista *lista) { 
    lista->inicio = NULL; 
    lista->fim = NULL; 
} 
```

Veja que a inicialização da lista é simples, basta atribuir NULL para o início e fim da lista. 

* Inserção de elemento no início da lista: 

```c
void insereInicio(Lista *lista, int valor) { 
    No *novo = (No*) malloc(sizeof(No)); 
    novo->valor = valor; 
    novo->prox = lista->inicio; 
    novo->ant = NULL; 
    if (lista->inicio != NULL) { 
        lista->inicio->ant = novo; 
    } 
    lista->inicio = novo; 
    if (lista->fim == NULL) { 
        lista->fim = novo; 
    } 
} 
```

Veja que a inserção de um elemento no início da lista é simples, basta criar um novo nó, atribuir o valor e fazer o ponteiro para o próximo elemento apontar para o início da lista.


* Inserção de elemento no fim da lista: 

```c
void insereFim(Lista *lista, int valor) { 
    No *novo = (No*) malloc(sizeof(No)); 
    novo->valor = valor; 
    novo->prox = NULL; 
    novo->ant = lista->fim; 
    if (lista->fim != NULL) { 
        lista->fim->prox = novo; 
    } 
    lista->fim = novo; 
    if (lista->inicio == NULL) { 
        lista->inicio = novo; 
    } 
} 
```

Veja que a inserção de um elemento no fim da lista é simples, basta criar um novo nó, atribuir o valor e fazer o ponteiro para o elemento anterior apontar para o fim da lista.

* Inserção de elemento na lista de forma ordenada: 

```c

void insereOrdenado(Lista *lista, int valor) { 
    No *novo = (No*) malloc(sizeof(No)); 
    novo->valor = valor; 
    if (lista->inicio == NULL) { 
        novo->prox = NULL; 
        novo->ant = NULL; 
        lista->inicio = novo; 
        lista->fim = novo; 
    } else { 
        No *aux = lista->inicio; 
        while (aux != NULL && aux->valor < valor) { 
            aux = aux->prox; 
        } 
        if (aux == NULL) { 
            novo->prox = NULL; 
            novo->ant = lista->fim; 
            lista->fim->prox = novo; 
            lista->fim = novo; 
        } else if (aux->ant == NULL) { 
            novo->prox = aux; 
            novo->ant = NULL; 
            aux->ant = novo; 
            lista->inicio = novo; 
        } else { 
            novo->prox = aux; 
            novo->ant = aux->ant; 
            aux->ant->prox = novo; 
            aux->ant = novo; 
        } 
    } 
} 
```

