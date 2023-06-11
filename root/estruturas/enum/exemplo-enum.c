#include <stdio.h> 

typedef enum boolean {
    false,
    true
}bool;

typedef enum response {
    no,
    yes
}response;


int main(void){

    bool var; 
    printf("Digite true ou false: ");
    scanf("%d", &var);

    if(var==false){
        printf("Is false");
    }
    else{
        printf("Is true");
    }


    response r; 
    r=yes; 
    printf("%d", yes); 

    return 0;
}