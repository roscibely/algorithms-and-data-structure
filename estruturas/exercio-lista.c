#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TURMAS 3
#define MAX_VAGAS 3

struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};

typedef struct aluno Aluno;

struct turma {
    char id; 
    int vagas; 
    Aluno* alunos[MAX_VAGAS];
};

typedef struct turma Turma;

Turma* turmas[MAX_TURMAS];


Turma * cria_turma(char id){
    /* 
    char id: identificador da turma
    */
    Turma *t = (Turma*) malloc(sizeof(Turma));
    t->id = id;
    t->vagas = 0;
    int i;
    for(i = 0; i < MAX_VAGAS; i++){
        t->alunos[i] = NULL;
    }
    return t;
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    /* 
    Turma* turma: ponteiro para a turma
    int mat: matricula do aluno
    char* nome: nome do aluno
    */
    if(turma->vagas < MAX_VAGAS){
        Aluno *a = (Aluno*) malloc(sizeof(Aluno));
        a->mat = mat;
        strcpy(a->nome, nome);
        int i;
        for(i = 0; i < 3; i++){
            a->notas[i] = 0;
        }
        a->media = 0;
        turma->alunos[turma->vagas] = a;
        turma->vagas++;
    }
}

void lanca_notas(Turma* turma){
    /*
    Turma* turma: ponteiro para a turma
    */

    int i, j;
    for(i = 0; i < turma->vagas; i++){
        for(j = 0; j < 3; j++){
            printf("Digite a nota %d do aluno %s: ", j+1, turma->alunos[i]->nome);
            scanf("%f", &turma->alunos[i]->notas[j]);
            turma->alunos[i]->media += turma->alunos[i]->notas[j];
        }
        turma->alunos[i]->media /= 3;
    }
}



void imprime_alunos(Turma* turma){
    /*
    Turma* turma: ponteiro para a turma
    */
    printf("Turma %c \r", turma->id);
    int i;
    for(i = 0; i < turma->vagas; i++){
        printf("Matricula: %d Nome: %s Notas: %.2f %.2f %.2f Media: %.2f \r" , turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->notas[0], turma->alunos[i]->notas[1], turma->alunos[i]->notas[2], turma->alunos[i]->media); 

    }
}

int main(void){

    turmas[0] = cria_turma('A');
    turmas[1] = cria_turma('B');
    matricula_aluno(turmas[0], 1, "Joao");
    matricula_aluno(turmas[0], 2, "Maria");
    matricula_aluno(turmas[1], 4, "Pedro");
    lanca_notas(turmas[0]);
    lanca_notas(turmas[1]);
    imprime_alunos(turmas[0]);
    imprime_alunos(turmas[1]);
    
    return 0;
}



