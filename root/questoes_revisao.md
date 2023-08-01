# Questões para revisão 

## 1. Ponteiros 

    01. Suponha que v é um vetor. Descreva a diferença conceitual entre as expressões v[2] e v+2.

    02. Suponha que os elementos do vetor v são do tipo int e cada int ocupa 4 bytes no seu computador. Se o endereço de v[0] é 55000, qual o valor da expressão v+3. 

## 2. Alocação dinâmica

    01. Escreva uma função que receba dois vetores como entrada e retorne um novo vetor que contenha a soma dos elementos correspondentes dos vetores de entrada.
    
    02. Escreva uma função que receba duas strings como entrada e retorne uma nova string que seja a concatenação das duas. 

Lembre-se de usar `malloc()` para alocar memória dinamicamente e `free()` para liberar a memória alocada quando ela não for mais necessária.

## 3. Structs 

Você precisa criar um programa para armazenar informações sobre diferentes tipos de frutas. Crie uma struct chamada "Fruta" com os seguintes campos: nome (string), cor (string), sabor (string) e quantidade (int).

Em seguida, escreva um programa que permita ao usuário cadastrar várias frutas, armazenando-as em um vetor de structs. O programa deve ter as seguintes funcionalidades:

* Cadastrar uma nova fruta: Solicitar ao usuário que insira o nome, cor, sabor e quantidade da fruta. Em seguida, adicionar a fruta ao array de structs.

* Listar todas as frutas cadastradas: Imprimir na tela todas as informações das frutas cadastradas até o momento.

* Buscar fruta por nome: Solicitar ao usuário que insira o nome de uma fruta. O programa deve buscar no array de structs por todas as frutas com esse nome e imprimir suas informações.

