#include <stdio.h>


char situacao(float p1, float p2, float p3, int faltas, int aulas, float*media){
    /* Função que  determine a média e a situação de um aluno em uma disciplina

    float p1: nota referente a prova 1 
    float p2: nota referente a prova 2
    float p3: nota referente a prova 3
    int faltas: faltas do aluno
    int aulas: total de aulas 
    float *media: ponteiro que armazena o endereço da variável que representa a média da nota

    Return: 
        A: para aprovado
        R: para reprovado
        F: para reprovado por faltas  
    */

    int nFaltas; // Variável para armazenar porcentagem de faltas 

    *media = (p1+p2+p3)/3.0; // o conteudo do ponteiro media é modificado para a media das notas 
    nFaltas = (100*faltas)/aulas; // porcentagem de faltas é calculada

    if ((nFaltas <=25) && (*media>=6.0)){ //Verifica se o aluno foi aprovado
        return 'A';
        }
    else if ((nFaltas <=25) && (*media<6.0)){ // Verifica se o aluno foi reprovado por nota 
        return 'R';
        }
    else    // Instrução executada apenas as duas condições anteriores não forem satisfeitas. 
        return 'F';
}



int main (void){

    /* Função principal do programa */ 

    float n1, n2, n3, m; //declaração de variáveis: n1, n2, n3 para as três notas a serem digitadas e m para guardar a média das notas
    char s; // s armazenará a letra referente a situação do aluno, isto é, A, R ou F. 
    int f, a; // f variável para armazenar o total de faltas. a variável para armazenare total de aulas 

    scanf("%f %f %f %d %d", &n1 , &n2, &n3, &f, &a); 
    s = situacao(n1, n2, n3, f, a, &m); // Faz a chamada da função situacao

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
