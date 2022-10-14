# Listas encadeadas 

### Lista encadadedas são estruturas de dados que armazenam dados de forma sequencial, mas cada elemento da lista é um objeto que contém um campo com o dado e um campo com o endereço do próximo elemento da lista.

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