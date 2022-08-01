#include <stdio.h>

int main(void) {
     /* Função principal do programa */ 

    int a, b, c;    // Declaração de variáveis 
    int *p1;       // Declaração de um ponteiro p para int 
    int *p2 = &a;  // Declaração do ponteiro p2. O ponteiro p2 recebe o valor de endereço da variável "a" 
    int *p3 = &c;  // Declaração do ponteiro p3. O ponteiro p3 recebe o valor de endereço da variável "c" 
    
    p1 = p2;        // p1 agora guarda o mesmo endereço que p2 guarda 
    *p2 = 10;       // o conteúdo de p2, isto é, o valor da variável "a" é alterado para 10 
    b = 20;         //variável b armazena o valor 20 
    int **pp;       //declaração de ponteiro para ponteiro 
    pp = &p1;       //pp recebe o endereço do ponteiro p1
    *p3 = **pp;     //o conteúdo de p3, isto é, o valor de c é alterado e agora é igual ao valor de a
    *p2 = b + (*p1)++; //o conteúdo de p2, isto é, o valor de a é alterado

    printf("%d\t%d\t%d\n", a, b, c);

    return 0;

}
