#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(void){

    Lista2* l = NULL;
    l= lst_insere(l,2);
    l = lst_busca(l, 2);
    l= lst_insere(l,3);
    l= lst_insere(l,6);
    l= lst_retira(l, 3);
    lst_imprime(l);

}
