#include "ingresso.c"

int main(void){

    preencherIngresso("ingressos.txt");
    imprimirIngressos("ingressos.txt");
    alterarPreco("ingressos.txt", "Circo");
    imprimirIngressos("ingressos.txt");
       

    return 0;
}