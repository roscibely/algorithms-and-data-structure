#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


typedef struct no{
    char nome_fruta[20];
    struct no * proxima;
}No;

No * adiciona_fruta(No * lista, char * nome_fruta){
    No * nova_fruta = (No*) malloc(sizeof(No)); 
    if (nova_fruta==NULL){
        printf("No memory!\n");
        exit(1);
    }
    strcpy(nova_fruta->nome_fruta,nome_fruta);
    nova_fruta->proxima=lista;
    return nova_fruta;
}

void imprime_Lista_frutas(No * lista){
    No * contador;
    for(contador=lista; contador!=NULL; contador=contador->proxima){
        printf(" %s -> ", contador->nome_fruta);
    }
}

int main(void){
    No * lista_de_frutas;
    lista_de_frutas = NULL;
    lista_de_frutas = adiciona_fruta(lista_de_frutas, "Morango");
    lista_de_frutas = adiciona_fruta(lista_de_frutas, "Abacate");
    lista_de_frutas = adiciona_fruta(lista_de_frutas, "Goiaba");
    imprime_Lista_frutas(lista_de_frutas);
    printf("Null");
    return 0;
}