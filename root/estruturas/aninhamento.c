#include <stdio.h> 
#include <stdlib.h>

typedef union  documento {
    int cpf;
    int rg;
}Documento;

typedef struct disciplina {
    char nome[50];
    int codigo;
    int carga_horaria;
} Disciplina;

typedef struct aluno {
    char nome[50];
    int matricula;
    Documento documento;
    Disciplina *disciplina; 
} Aluno;


Disciplina * aloca_disciplina(int num_disciplinas) {
    Disciplina *disciplina = (Disciplina *) malloc(num_disciplinas*sizeof(Disciplina));
    if (disciplina == NULL){
        exit(1);
    }   
    return disciplina;
}

Aluno * aloca_aluno() {
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
    if (aluno == NULL)
    {
        exit(1);
    }   
    aluno->disciplina = aloca_disciplina(1);
    return aluno;
}

void inicializar_aluno(Aluno *aluno) {
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", aluno->nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno->matricula);
    printf("Digite o cpf do aluno: ");
    scanf("%d", &aluno->documento.cpf);
    printf("Digite o nome da disciplina: ");
    scanf("%s", aluno->disciplina->nome);
    printf("Digite o codigo da disciplina: ");
    scanf("%d", &aluno->disciplina->codigo);
    printf("Digite a carga horaria da disciplina: ");
    scanf("%d", &aluno->disciplina->carga_horaria);
}

void imprime_aluno(Aluno *aluno){
    printf(" Nome do aluno: %s, Matricula: %d, CPF: %d ", aluno->nome, aluno->matricula, aluno->documento.cpf);
    printf(" Nome da disciplina: %s, Codigo: %d, Carga Horaria: %d ", aluno->disciplina->nome, aluno->disciplina->codigo, aluno->disciplina->carga_horaria);
}

int main(void){
    Aluno *aluno = aloca_aluno();
    inicializar_aluno(aluno);
    imprime_aluno(aluno);
    return 0;
}
