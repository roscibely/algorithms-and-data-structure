#include <stdio.h>

int main(void) {

    int a, b, c;
    int *p1;
    int *p2 = &a;
    int *p3 = &c;
    
    p1 = p2;
    *p2 = 10;
    b = 20;
    int **pp;
    pp = &p1;
    *p3 = **pp;
    *p2 = b + (*p1)++;

    printf("%d\t%d\t%d\n", a, b, c);

    return 0;

}
