#include <stdint.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
    /* Função que calcula a area e perimetro de uma hexagono 

    float l: lado do hexágono
    float *area: ponteiro que armazena o endereço da memoria onde está localizado o valor para area 
    float *perimetro: ponteiro que armazena o endereço da memoria onde está localizado o valor para perimetro

    */
    *perimetro = 6*l; // Realiza o calculo do perimetro do hexagono e atualiza o conteudo do endereço que o ponteiro perimetro aponta 
    *area = (3*pow(l,2)*sqrt(3))/2;  // Realiza o calculo da area do hexagono e atualiza o conteudo do endereço que o ponteiro area aponta 
}

int main(void){
    /* Função do programa principal */ 

    float l, a, p; // Declaração das variaveis 
    scanf("%f", &l); // Realiza a leitura do lado de um hexágono e amarzena o valor em "l"
    calcula_hexagono(l,&a,&p); //Faz a chamada da função calcula_hexagono
    printf("Area = %.2f \n Perimetro = %.2f \n", a,p); // Exibe a area e o perimetro calculados pela função calcula_hexagono

    return 0;
}
