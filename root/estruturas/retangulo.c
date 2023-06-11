#include <stdio.h>

typedef struct ponto{
    float x, y;
}Ponto;

typedef struct retangulo{
    Ponto p1, p2; 
}Retangulo; 

int main(void){

    Retangulo tela; 

    printf("Informe as cordenadas do ponto p1 da tela: ");
    scanf("%f %f", &tela.p1.x, &tela.p1.y);

    printf("Informe as cordenadas do ponto p2 da tela: ");
    scanf("%f %f", &tela.p2.x, &tela.p2.y);

    printf("A tela possui os dois pontos: p1=(%f, %f)  p2=(%f, %f)", tela.p1.x, tela.p1.y, tela.p2.x, tela.p2.y);

    return 0;
}