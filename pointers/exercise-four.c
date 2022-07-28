#include <stdint.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){

    *perimetro = 6*l;
    *area = (3*pow(l,2)*sqrt(3))/2;

}

int main(void){

    float l, a, p;
    scanf("%f", &l);
    calcula_hexagono(l,&a,&p);
    printf("Area = %.2f \n Perimetro = %.2f \n", a,p);

    return 0;
}
