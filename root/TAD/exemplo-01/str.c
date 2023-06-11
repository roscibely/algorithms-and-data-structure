#include "str.h"

int comprimento (char* s)
{
    int i;
    int n = 0; /* contador */
    for (i=0; s[i] != '\0'; i++)
    n++;
    return n;
}

void copia (char* dest, char* orig)
{
int i;
for (i=0; orig[i] != '\0'; i++)
dest[i] = orig[i];
/* fecha a cadeia copiada */
dest[i] = '\0';
}

void concatena (char*dest, char* orig)
{
    int i = 0; /* indice usado na cadeia destino, inicializado com zero */
    int j; /* indice usado na cadeia origem */
    /* acha o final da cadeia destino */
    i = 0;
    while (dest[i] != '\0')
        i++;
    /* copia elementos da origem para o final do destino */
    for (j=0; orig[j] != '\0'; j++)    {
        dest[i] = orig[j];
        i++;
    }
    /* fecha cadeia destino */
    dest[i] = '\0';
}