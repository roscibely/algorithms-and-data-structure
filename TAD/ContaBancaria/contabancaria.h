#include <stdio.h>
#include <stdlib.h>

/*Definição do tipo de dados abstrato ContaBancaria: 
estrutura que armazena o número da conta, o nome do correntista e o saldo da conta. */
typedef struct contabancaria ContaBancaria;

/*Cria conta: aloca dinamicamente uma estrutura do tipo ContaBancaria
 e retorna seu endereço */
ContaBancaria *criaconta(char * nome_arquivo);

/*Deposita: recebe, como parâmetros, o endereço de uma estrutura do tipo ContaBancaria
 e um valor, atualizando o saldo;*/
void deposita(ContaBancaria *conta, float valor);

/*Saca: recebe, como parâmetros, o endereço de uma estrutura do tipo ContaBancaria
 e um valor, atualizando o saldo;*/
void saca(ContaBancaria *conta, float valor);

/*Transfere: recebe, como parâmetros, o endereço de duas estruturas do tipo ContaBancaria
 e um valor, atualizando o saldo das duas contas;*/
void transfere(ContaBancaria *conta1, ContaBancaria *conta2, float valor);

/*Exclui conta: libera o espaço alocado dinamicamente para a estrutura*/
void excluiConta(ContaBancaria *conta);