#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(void){

	Lista* l = lst_cria(); /*Cria uma lista*/
	l = lst_insere(l, 2); /*Insere o elemento na lista*/
	l = lst_insere(l, 5);
	l = lst_insere(l, 4);
	l= lst_retira(l, 2);
	l= lst_busca(4, l);
	lst_imprime(l);
	return 0;
}
