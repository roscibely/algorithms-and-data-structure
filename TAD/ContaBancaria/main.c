#include "contabancaria.h"


int main(void) {
    ContaBancaria *conta = criaconta("conta.txt");
    deposita(conta, 100, "conta.txt");
    saca(conta, 50, "conta.txt");
    ContaBancaria *conta2 = criaconta("conta.txt");
    deposita(conta2, 200, "conta.txt");
    transfere(conta, conta2, 50);
    return 0;
}