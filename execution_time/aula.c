#include <stdio.h> 

// Algortimo: SUM: i 0  i< N

int sum(int n){
    int soma = 0;  // 1 vez: c1
    int i; //1 vez: c2
    for(i=0; i<n; i++){soma=soma+i;} // n vez: c3
    return soma; // 1 vez: c4
}


/* 
T(sum) = c1 + c2+ c3*n + c4
T(sum) = c1 + c2+ c4 + c3*n 
T(sum) = b + a*n
T(n) = a*n + b : Tempo de execução linear! 


-------
Big-O 

T(n) = O(n)
*/

//SUM: i*j : i < N , j<N
int sum_ij(int n){
    int soma = 0;  // 1 vez: c1
    int i, j; //1 vez: c2
    for(i=0; i<n; i++){ // n vez: c3
        for(j=0; j<n; j++){ 
            soma=soma+i*j;
             } // n² vez: c4
        } 
    return soma; // 1 vez: c5
}

/*
T(n) = c1 + c2 + c3*n + c4* n² + c5 
T(n) = c4* n² + c3*n + c1 + c2+ c5

T(n) = a*n² +  b*n +  c : Tempo de execução quadrático

1 - remover as constantes 
T(n) = a*n² +  b*n 
2 - remover os termos multiplicativos 
T(n) = n² + n 
3 - Considerar o termo de maior grau 
T(n) = n²

O(n²)
-
Notação Big-O 
T(n) = O(n²)
*/


void insertionSort(int arr[], int n){
  int i, key, j; // 1 vez, c1 
  for(i=1;i<n; i++){ // n-1 vez, c2 
    key=arr[i]; // n-1 vez, c3
    j=i-1; // n-1 vez, c4
    while(j>=0 && arr[j]>key){ 
      arr[j+1]=arr[j]; 
      j=j-1; 
    }
    arr[j+1]=key; //n-1 vez, c8 
  }
}

/* T(n) = c1 + (c2+c3+c4+c8)(n-1) + n(n-1)(c5+c6+c7)
T(n) = c + b(n-1) + n(n-1)*a

T(n) = c + bn-b + an² - an

T(n) = bn + an² - an

T(n) = n + n² - n

T(n) = n²

Pior Insertion e Medio 
T(n) = O(n²)

Melhor 
T(n) = O(n)

 */

