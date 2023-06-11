#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
typedef struct aluno{
    int matricula;
    char nome[81];
    char turma;
    float nota[3];
    float media;
}Aluno;

void inicializa(Aluno **alunos, int n){
	int i;
	for(i=0; i<n; i++)
		alunos[i] = NULL;
}

void matricula(int n, Aluno** alunos){
    static int i = 0;
    if(i<n){
                alunos[i] = (Aluno*) malloc(n*sizeof(Aluno));
                if(alunos[i]==NULL){
                        printf("Memoria cheia \n");
                        exit(1);
                }
                else{
                    printf("Insiraa a matricula: \n Insira a turma: \n Insira o nome: \n");
                    scanf(" %d ", &alunos[i]->matricula);
                    scanf(" %c", &alunos[i]->turma);
                    scanf(" %80[^\n]", alunos[i]->nome);
                    alunos[i]->nota[0]=0;
                    alunos[i]->nota[1]=0;
                    alunos[i]->nota[2]=0;
                    alunos[i]->media=0;
                    i++;
                }
            }

    else
    {
      printf("Nao ha vagas");
    }

}

void lanca_notas(int n, Aluno** alunos){
    int i;
    for(i=0;i<n;i++){
            if(alunos[i]!=NULL){
                printf("Aluno %d", i+1);
                    printf("\n Digite as nota:\n");
                    scanf("%f %f %f", &alunos[i]->nota[0], &alunos[i]->nota[1], &alunos[i]->nota[2]);
                    alunos[i]->media=(alunos[i]->nota[0] + alunos[i]->nota[1] + alunos[i]->nota[2])/3;
                    printf("Media: %.2f \n", alunos[i]->media);
               }
    }
}

void imprime_tudo(int n, Aluno** alunos){
    int i;
    for(i=0; i<n; i++){
            if(alunos[i]!=NULL){
                printf("\n Matricula:  %d \n", alunos[i]->matricula );
                printf("Nome: %s \n", alunos[i]->nome);
                printf("Turma: %c \n", alunos[i]->turma);
                printf("Media: %f \n", alunos[i]->media);
                }

    }
}

void imprime_turma(int n, Aluno** alunos, char turma){
    int i;
    for(i=0;i<n;i++){
        if(alunos[i]!=NULL && alunos[i]->turma==turma){
            printf("\n Matricula:  %d \n", alunos[i]->matricula );
            printf("Nome: %s \n", alunos[i]->nome);
            printf("Turma: %c \n", alunos[i]->turma);
        }
    }
}

void imprime_turma_aprovados(int n, Aluno**alunos, char turma){
    int i;
    for(i=0;i<n;i++){
        if(alunos[i]!=NULL && alunos[i]->turma==turma){
           if(alunos[i]->media>=7){
                printf("\n Matricula:  %d \n", alunos[i]->matricula);
                printf("Nome: %s \n", alunos[i]->nome);
                printf("Media: %f \n, APROVADO \n", alunos[i]->media);
           }
        }
    }
}
int main(void){
    Aluno ** aluno = (Aluno**) malloc(MAX*sizeof(Aluno*)); //Vector de ponteiros de struct
    if (aluno==NULL){
        printf("Memoria cheia \n");
        exit(1);
    }
    inicializa(aluno,MAX);
    matricula(MAX,aluno);
    lanca_notas(MAX, aluno);
    imprime_tudo(MAX,aluno);
    imprime_turma(MAX, aluno, 'a');
    imprime_turma_aprovados(MAX,aluno, 'a');

return 0;
}