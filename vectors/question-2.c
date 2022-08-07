#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    /* Função principal do programa */

    int i, somaF, somaM, j, n;
    somaM = somaF = 0;
    /* i e j: contadores auxilares para o laço de repetição for
    somaF e somaM variáveis para armazenar a quantidade de mulheres (somaF) e homens (somaM) entrevistados
    n: variável para armazenar a quantidade de usuarios entrevistados*/

    printf("Informe a quantidade de usuarios entrevistados \n");
    scanf("%d", &n);

    char *sexo = (char *)malloc(n * sizeof(char)); //Alocação dinâmica do vetor sexo. Vetor que guardará o sexo dos entrevistados F ou M
    int *op = (int *)malloc(n * sizeof(int)); //Alocação dinâmica do vetor op. Vetor de guardará valor 0 ou 1. 
    //0 quando o usuario não gostou do produto e 1 quando ele gostar do produto. 

    printf("----QUESTIONARIO----: \n");

    //Laço de repetição for para ler e armazenar os dados nos vetores sexo e op
    for (i = 0; i < n; i++)
    {
        printf("Sexo do entrevistado: Digite F ou M \n");
        scanf(" %c", &sexo[i]);
        printf("Opniao sobre o produto: \n 0. nao gostou \n 1. gostou \n");
        scanf("%d", &op[i]);
    }

    // Laço de repetição para somar a quantidade de pessoas do sexo F que gostaram do produto e
    //somar a quantidade de pessoas do sexo M que não gostaram
    for (j = 0; j < n; j++)
    {
        // Verificar se o sexo é F e a op 1, isto é, gostou 
        if ((sexo[j] == 'F') && (op[j] == 1))
        {
            somaF++;
        }
        // Verificar se o sexo é M e a op 0, isto é, não gostou 
        if ((sexo[j] == 'M') && (op[j] == 0))
        {
            somaM++;
        }
    }

    somaF = ((somaF * 100.0f) / n); //determine a porcentagem de pessoas do sexo feminino que responderam que gostaram do produto
    somaM = ((somaM * 100.0f) / n); //determine a porcentagem de pessoas do sexo masculino que responderam que não gostaram do produto

    printf("\n %d %% das mulheres gostaram do produto \n %d %% dos homens nao gostaram do produto \n", somaF, somaM);

    // libera a memória alocada 
    free(sexo);
    free(op);

    return 0;
}