# Listas circulares 

### Uma lista circular é uma lista que possui um ponteiro para o próximo elemento e último nó aponta para o primeiro nó. Dessa forma, é possível a patir do último nó navegar para o primeiro nó.

### Aplicação de listas circulares:

-   Implementação de filas circulares

-   Implementação de pilhas circulares

### Implementação de uma lista circular para inteiros:

```c
typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct lista {
    No *inicio;
    No *fim;
} Lista;
```

### Função para criar uma lista circular:

```c
Lista *cria_lista() {
    Lista *l = (Lista *) malloc(sizeof(Lista));
    if (l != NULL) {
        l->inicio = NULL;
        l->fim = NULL;
    }
    return l;
}
```

### Função para inserir um elemento no início da lista circular:

```c

void insere_inicio(Lista *l, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo != NULL) {
        novo->valor = valor;
        if (l->inicio == NULL) {
            l->inicio = novo;
            l->fim = novo;
            novo->prox = novo;
        } else {
            novo->prox = l->inicio;
            l->inicio = novo;
            l->fim->prox = novo;
        }
    }
}
```

### Função para inserir um elemento no final da lista circular:

```c
void insere_fim(Lista *l, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo != NULL) {
        novo->valor = valor;
        if (l->inicio == NULL) {
            l->inicio = novo;
            l->fim = novo;
            novo->prox = novo;
        } else {
            novo->prox = l->inicio;
            l->fim->prox = novo;
            l->fim = novo;
        }
    }
}
```

### Função para imprimir os elementos da lista circular:

```c

void imprime_lista(Lista *l) {
    if (l->inicio != NULL) {
        No *aux = l->inicio;
        do {
            printf("%d ", aux->valor);
            aux = aux->prox;
        } while (aux != l->inicio);
    }
}
```

### Função para remover um elemento do início da lista circular:

```c

int remove_inicio(Lista *l) {
    if (l->inicio == NULL) {
        return -1;
    } else {
        No *aux = l->inicio;
        int valor = aux->valor;
        if (l->inicio == l->fim) {
            l->inicio = NULL;
            l->fim = NULL;
        } else {
            l->inicio = aux->prox;
            l->fim->prox = l->inicio;
        }
        free(aux);
        return valor;
    }
}
```

### Função para remover um elemento do final da lista circular:

```c

int remove_fim(Lista *l) {
    if (l->inicio == NULL) {
        return -1;
    } else {
        No *aux = l->inicio;
        int valor = l->fim->valor;
        if (l->inicio == l->fim) {
            l->inicio = NULL;
            l->fim = NULL;
        } else {
            while (aux->prox != l->fim) {
                aux = aux->prox;
            }
            aux->prox = l->inicio;
            l->fim = aux;
        }
        free(aux);
        return valor;
    }
}
```

### Função para liberar a memória alocada para a lista circular:

```c

void libera_lista(Lista *l) {
    if (l->inicio != NULL) {
        No *aux = l->inicio;
        while (aux->prox != l->inicio) {
            No *aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux);
    }
    free(l);
}
```

### Função para verificar se a lista circular está vazia:

```c

int lista_vazia(Lista *l) {
    if (l->inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}
```

### Função para verificar se um elemento está na lista circular:

```c

int elemento_existe(Lista *l, int valor) {
    if (l->inicio != NULL) {
        No *aux = l->inicio;
        do {
            if (aux->valor == valor) {
                return 1;
            }
            aux = aux->prox;
        } while (aux != l->inicio);
    }
    return 0;
}
```

### Função para retornar o tamanho da lista circular:

```c

int tamanho_lista(Lista *l) {
    if (l->inicio != NULL) {
        No *aux = l->inicio;
        int tamanho = 0;
        do {
            tamanho++;
            aux = aux->prox;
        } while (aux != l->inicio);
        return tamanho;
    }
    return 0;
}
```

### Função para retornar o elemento do início da lista circular:

```c

int elemento_inicio(Lista *l) {
    if (l->inicio != NULL) {
        return l->inicio->valor;
    }
    return -1;
}
```

