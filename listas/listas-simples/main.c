#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){

	Lista* l = lst_cria(); /*Cria uma lista*/
	l = lst_insere(l, 2); /*Insere o elemento na lista*/
	l = lst_insere(l, 5);
	l = lst_insere(l, 5);
	l= lst_retira_recursiva(l, 2);
	lst_imprime(l);
	return 0;
}
