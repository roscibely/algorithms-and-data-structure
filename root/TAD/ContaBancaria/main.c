#include "contabancaria.h"


int main(void) {
    ContaBancaria *conta = criaconta("conta.txt");
    deposita(conta, 100);
    saca(conta, 50);
    ContaBancaria *conta2 = criaconta("conta.txt");
    deposita(conta2, 200);
    transfere(conta, conta2, 50);
    return 0;
}
