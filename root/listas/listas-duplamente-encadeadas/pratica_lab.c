#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura da fruta
typedef struct Fruta {
    char nome[50];
    float valorPorQuilo;
} Fruta;

// Estrutura do nó da lista duplamente encadeada
typedef struct No {
    Fruta fruta;
    struct No* prox;
    struct No* ant;
} No;

// Função para criar um novo nó
No* criarNo(char nome[], float valorPorQuilo) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->fruta.nome, nome);
    novoNo->fruta.valorPorQuilo = valorPorQuilo;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    return novoNo;
}

// Função para inserir no início da lista
void inserirNoInicio(No** head, char nome[], float valorPorQuilo) {
    No* novoNo = criarNo(nome, valorPorQuilo);
    if (*head == NULL) {
        *head = novoNo;
    } else {
        novoNo->prox = *head;
        (*head)->ant = novoNo;
        *head = novoNo;
    }
}

// Função para exibir a lista
void exibirLista(No* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    No* temp = head;
    printf("Lista de Frutas:\n");
    while (temp != NULL) {
        printf("Fruta: %s, Valor por quilo: R$ %.2f\n", temp->fruta.nome, temp->fruta.valorPorQuilo);
        temp = temp->prox;
    }
}

// Função para liberar a memória alocada
void liberarLista(No** head) {
    No* temp = *head;
    while (temp != NULL) {
        No* proximo = temp->prox;
        free(temp);
        temp = proximo;
    }
    *head = NULL;
}

// Função para exibir o menu
void exibirMenu() {
    printf("\nMenu:\n");
    printf("1. Inserir uma nova fruta\n");
    printf("2. Exibir lista de frutas\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    No* listaFrutas = NULL;
    int opcao;
    char nome[50];
    float valorPorQuilo;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome da fruta: ");
                scanf("%s", nome);
                printf("Digite o valor por quilo: ");
                scanf("%f", &valorPorQuilo);
                inserirNoInicio(&listaFrutas, nome, valorPorQuilo);
                break;

            case 2:
                exibirLista(listaFrutas);
                break;

            case 3:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    // Liberando a memória alocada
    liberarLista(&listaFrutas);

    return 0;
}
