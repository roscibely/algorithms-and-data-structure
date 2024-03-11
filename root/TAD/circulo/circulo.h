typedef struct circulo Circulo; 

/* Função que cria um circulo */
Circulo* cria_circulo();

/* Função que calcula a área de um circulo */
float area_circulo(Circulo* c);

/* Função que modifica o centro de um circulo */
void move_circulo(Circulo* c, float novo_x, float novo_y);