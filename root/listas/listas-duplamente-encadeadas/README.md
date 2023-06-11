# Listas duplamente encadeadas 

 ### Uma lista duplamente encadeada é uma lista que possui um ponteiro para o próximo elemento e um ponteiro para o elemento anterior. 


 ### Diferente da lista encadeada, a lista duplamente encadeada permite a navegação na lista em qualquer direção. Dessa forma, é possível navegar na lista tanto para frente quanto para trás. Por esse motivo, a lista duplamente encadeada é mais flexível que a lista encadeada e permite a implementação de algoritmos mais complexos. 

 ### Dessa forma, é necessário criar uma estrutura de dados que armazene o dado e dois ponteiros no nó, um para o próximo elemento e outro para o elemento anterior. 

 

 ### Implementação de uma lista duplamente encadeada para inteiros: 

 
 
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
