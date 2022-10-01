#define LIN 10
#define COL 10

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void preencheMat(int mat[LIN][COL]);
void mostraMat(int mat[LIN][COL]);
void inverteMat(int mat[LIN][COL]);
void alteraMat(int mat[LIN][COL]);
void trocaInt(int *a, int *b);

int main () {
    int m[LIN][COL];
    preencheMat(m);
    printf("\nMatriz original:\n");
    mostraMat(m);
    
	printf("\nMatriz invertida (inicio X final):\n");
    inverteMat(m);
    mostraMat(m);

	printf("\nProcessamento das trocas:\n");
    alteraMat(m);
    printf("\nMatriz pares no comeco, impares depois:\n");
    mostraMat(m);

    return 0;
}

void preencheMat(int mat[LIN][COL]){
    int i, j;
    srand(time(NULL));
    for (i=0; i<LIN; i++) {
        for (j=0; j<COL; j++) { 
           mat[i][j] = 10 + rand()%90;
        }
    }
}

void mostraMat(int mat[LIN][COL]){
    int i, j;
    for (i=0; i<LIN; i++) { 
        for (j=0; j<COL; j++) {
            printf("%d   ", mat[i][j]);
        }
        printf("\n");
    }
}

// troca elementos do final com inicio
void inverteMat(int mat[LIN][COL]){
    int *e, *d;
    e = &mat[0][0]; // esquerda recebe endereco do primeiro elemento da matriz
    d = &mat[LIN-1][COL-1];  // direita recebe endereco do ultimo elemento do matriz
    do {
        trocaInt(e, d); 
        e++;  // incrementa ponteiro para proximo inteiro, ou seja pula 4 bytes    
        d--;  // decrementar ponteiro para inteiro anterior, ou seja, volta 4 bytes
    } while (e < d); // at� se cruzarem
}

// troca elementos do final com inicio
void alteraMat(int mat[LIN][COL]){
    int *e, *d;
    e = &mat[0][0]; // esquerda recebe endereco do primeiro elemento da matriz
    d = &mat[LIN-1][COL-1];  // direita recebe endereco do ultimo elemento do matriz
    do {
 		// achar o primeiro impar fora de lugar
 		while (*e % 2 == 0) 
 			e++;
 		printf("Achei um impar fora do lugar %d\n", *e);
        
        // achar o primeiro par fora de lugar
 		while (*d % 2 == 1) 
 			d--;
 		printf("Achei um par fora do lugar %d\n", *d);
		
		printf("Trocando %d com %d\n\n", *e, *d);
		trocaInt(e, d); 
        e++; 
        d--; 
    } while (e < d); // at� se cruzarem
}
	
// passagem por REFERENCIA de tipos primitivos 
// demanda uso de PONTEIROS explicitos
void trocaInt(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

