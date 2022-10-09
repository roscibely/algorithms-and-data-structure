# Listas duplamente encadeadas 

 ### Uma lista duplamente encadeada é uma lista que possui um ponteiro para o próximo elemento e um ponteiro para o elemento anterior. 

 ### Implementação 
 
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
