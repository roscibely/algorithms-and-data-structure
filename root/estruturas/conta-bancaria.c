#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//Definição da struct Conta 
typedef struct Conta{
    /*int num: numero da conta
    char cliente[]: nome do cliente
    float saldo: saldo da conta */
    int num;
    char cliente[81];
    float saldo;
}ContaBancaria;


void inicializa(ContaBancaria*CONTA){
    /*Função para inicializar a CONTA */
	CONTA = NULL;
}

void deposita(float valor, ContaBancaria*conta){
    /*Função que incrementa o saldo da conta
    float valor: valor a ser incrementado na conta
    ContaBancaria * conta: ponteiro para a estrutura do tipo ContaBancaria */
    conta->saldo=+valor;
}

int main(void){
    /*Função principal */

    // Alocação dinâmica de um ponteiro do tipo ContaBancaria 
    ContaBancaria *Conta;
    Conta = (ContaBancaria *) malloc(sizeof(ContaBancaria));

    //inicializa(Conta);
    Conta->saldo = 4000.00;
    Conta->num = 7863;
    deposita(1000, Conta);

    strcpy(Conta->cliente,"Fulano"); 

    printf("Novo saldo: %.2f \n", Conta->saldo);
    
    free(Conta); // Libera o espaço de memoria alocado para o ponteiro Conta

return 0;
}