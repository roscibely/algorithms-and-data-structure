#include "funcionario.c"

int main(void){

    preencherFuncionario("funcionarios.txt");
    imprimirFuncionarios("funcionarios.txt");
    alterarSalario("funcionarios.txt", "Maria");
    imprimirFuncionarios("funcionarios.txt");

    return 0;
}