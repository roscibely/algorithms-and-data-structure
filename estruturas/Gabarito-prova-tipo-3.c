#include <stdio.h>
/*
Crie um tipo estruturado para armazenar dados de um funcionário.
Uma estrutura deste tipo possui os seguintes campos: nome, salário e cargo.
 */

typedef struct funcionario {
    char nome[50];
    float salario;
    char cargo[50];
} Funcionario;

/*
Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario e
preencha seus campos com valores fornecidos pelo usuário via teclado. 
 */

void preencheFuncionario(Funcionario *func) {
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", &func->nome);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &func->salario);
    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]", &func->cargo);
}

/*
Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
 e imprima os valores dos seus campos. 
 */

void imprimeFuncionario(Funcionario *func) {
    printf("Nome do funcionario: %s, salario: %.2f, cargo: %s ", func->nome, func->salario, func->cargo);
}

/*
Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario.
 */

void alteraSalario(Funcionario *func, float valor) {
    func->salario += valor;
}

/*
Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario
 e imprima o cargo do Funcionario com maior salário e o cargo do funcionário com o menor salário.  
 */

void maiorMenorSalario(Funcionario *func, int tam) {
    int i, maior = 0, menor = 0;
    for (i = 0; i < tam; i++) {
        if (func[i].salario > func[maior].salario) {
            maior = i;
        }
        if (func[i].salario < func[menor].salario) {
            menor = i;
        }
    }
    printf("\nFuncionario com maior salario: %s,\nFuncionario com menor salario: %s", func[maior].cargo, func[menor].cargo);
}

/*
Implemente a função main para testar todas as demais funções declaradas nos itens anteriores
 */

int main() {

    int n;
    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &n);

    Funcionario func[n];
    int i;
    for (i = 0; i < n; i++) {
        preencheFuncionario(&func[i]);
    }
    for (i = 0; i < n; i++) {
        imprimeFuncionario(&func[i]);
    }
    alteraSalario(&func[0], 1000);

    maiorMenorSalario(func, n);
    return 0;
}