#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct professor {
    char nome[50];
    char disciplinas[50];
    int regime;
} Professor;

void preencheProfessor(Professor *professor) {
    printf("Digite o nome do professor: ");
    scanf(" %[^\n]", professor->nome);
    printf("Digite as disciplinas do professor: ");
    scanf(" %[^\n]", professor->disciplinas);
    printf("Digite o regime de trabalho do professor: ");
    scanf("%d", &professor->regime);
}


void imprimeProfessor(Professor *professor) {
    printf("Nome: %s\n", professor->nome);
    printf("Disciplinas: %s\n", professor->disciplinas);
    printf("Regime: %d\n", professor->regime);
}


void alteraRegime(Professor *professor, int novoRegime) {
    professor->regime = novoRegime;
}

int main(void){
    Professor professor;
    preencheProfessor(&professor);
    imprimeProfessor(&professor);
    alteraRegime(&professor, 40);
    imprimeProfessor(&professor);
    return 0;
    
}