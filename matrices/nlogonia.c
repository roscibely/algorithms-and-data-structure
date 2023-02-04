#include <stdio.h>
#include <stdlib.h>

int main(void){
    int m, n, i, j, k, l, cont = 0;
    char **matriz;
    
    // restrição de tamanho da matriz
    do{    
    printf("Digite o numero de linhas e colunas.\nDeve ser maior que 1 e menor que 1000: ");
    scanf("%d %d", &m, &n);
    }while(m < 1 || m > 1000 || n < 1 || n > 1000);


    matriz = (char**) malloc(m * sizeof(char*));
    for(i = 0; i < m; i++)
        matriz[i] = (char*) malloc(n * sizeof(char));

    printf("Digite o mapa em linhas: . para mar e # para terra:\n ");
    for(i = 0; i < m; i++){
            scanf(" %[^\n]s", matriz[i]);
    }


for ( i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
        if (matriz[i][j] == '#') {
          
            if ((i == 0 && j == 0 && (i + 1 < m && matriz[i + 1][j] == '.') || (j + 1 < n && matriz[i][j + 1] == '.'))) {
                cont++;
            } else if ((i == 0 && j == n - 1 && (i + 1 < m && matriz[i + 1][j] == '.') || (j > 0 && matriz[i][j - 1] == '.'))) {
                cont++;
            } else if ((i == m - 1 && j == 0 && (i > 0 && matriz[i - 1][j] == '.') || (j + 1 < n && matriz[i][j + 1] == '.'))) {
                cont++;
            } else if ((i == m - 1 && j == n - 1 && (i > 0 && matriz[i - 1][j] == '.') || (j > 0 && matriz[i][j - 1] == '.'))) {
                cont++;
                
                
            } else if ((i == m - 1 && j > 0 && j < n - 1 && (matriz[i][j - 1] == '.' || matriz[i][j + 1] == '.'))) {
                cont++;
            } else if ((j == n - 1 && i > 0 && i < m - 1 && (matriz[i - 1][j] == '.' || matriz[i + 1][j] == '.'))) {
                cont++;
            } else if ((i == 0 && j > 0 && j < n - 1 && (matriz[i][j - 1] == '.' || matriz[i][j + 1] == '.'))) {
                cont++;
            } else if ((j == 0 && i > 0 && i < m - 1 && (matriz[i - 1][j] == '.' || matriz[i + 1][j] == '.'))) {
                cont++;
                
               
            } else if ((i != 0 && j != 0 && j != n - 1 && i != m - 1) && (matriz[i - 1][j] == '.' || matriz[i + 1][j] == '.' || matriz[i][j - 1] == '.' || matriz[i][j + 1] == '.')) {
                cont++;
            }
        }
    }
}

 


    printf("%d \n", cont);

    // imprime a matriz
    printf("Mapa: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++)
            printf("%c ", matriz[i][j]);
        printf("\n");
    }

    for(i = 0; i < m; i++)
        free(matriz[i]);
    free(matriz);

    return 0;

}

