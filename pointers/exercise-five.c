#include <stdio.h>


char situacao(float p1, float p2, float p3, int faltas, int aulas, float*media){
    
    int nFaltas;

    *media = (p1+p2+p3)/3.0;
    nFaltas = (100*faltas)/aulas;

    if ((nFaltas <=25) && (*media>=6.0)){
        return 'A';
        }
    else if ((nFaltas <=25) && (*media<6.0)){
        return 'R';
        }
    else
        return 'F';
}



int main (void){

    float n1, n2, n3, m;
    char s;
    int f, a;

    scanf("%f %f %f %d %d", &n1 , &n2, &n3, &f, &a);
    s = situacao(n1, n2, n3, f, a, &m);

    switch(s){
    case 'A':
        printf("Media = %.1f \t 'APROVADO' ", m);
        break;
    case 'R':
        printf("Media = %.1f \t 'REPROVADO' ", m);
        break;
    default:
        printf("Media = %.1f \t 'REPROVADO POR FALTAS' ", m);
        }

    return 0;
}
