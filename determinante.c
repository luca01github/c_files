#include <stdio.h>
#include <stdlib.h>

int calc_det(int **matrix, int n);
void sub_matrix(int **matrix,int **sub, int excluded_col, int n);
int** malloc_matrix(int n);
void free_matrix(int **matrix, int n);
void print_matrix(int **matrix, int n);

int main(){
	int n = 3;
	int valori[3][3] = {
		{1, 2, 3},
		{-2, -1, -3},
		{0, -4, 1}
	};
	int **matrice = malloc_matrix(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			matrice[i][j] = valori[i][j];  //Copio i valori per inizializzare 
		}
	}
	int det = calc_det(matrice, n);
	printf("Determinante = %d\n", det);
	free_matrix(matrice, n);
}

/*calcola ricorsivamente il determinante della sottomatrice chiamando sub_matrix() con dimensione n-1*/
int calc_det(int **matrix, int n){
	if(n==1){
		return matrix[0][0];
	}
	else if(n==2){
		return matrix[0][0]*matrix[1][1] -  matrix[0][1]*matrix[1][0]; 
	}

	int **sub = malloc_matrix(n-1);
	int det=0;
	for(int col=0; col<n; col++){
		sub_matrix(matrix, sub, col, n);  //serve per aggiornare la sottomatrice che altrimenti sarebbe sempre la stessa
		printf("Stampa della sottomatrice corrente escludendo la colonna %d\n", col);
		print_matrix(sub, n-1);
		putchar('\n');
		int sign = (col%2) == 0 ? 1 : -1;  //Il segno equivale a (-1)^i+j: se la somma è pari restituisce 1, altrimenti -1
		det += sign * matrix[0][col] * calc_det(sub, n-1);
		
	}
	
	free_matrix(sub, n-1);
	return det;
}

//restiruisce la sottomatrice 
void sub_matrix(int **matrix,int **sub, int excluded_col, int n){
	int subi = 0;  //indice i della sottomatrice (per tenere traccia delle righe)
	for(int i=1; i<n; i++){  //si parte direttamente dalla seconda riga perché calcolo le sottomatrici a partire dai suoi elementi
		int subj=0;  //Tiene traccia delle colonne della sottomatrice
		for(int j=0; j<n; j++){
			if(j == excluded_col) continue;
			sub[subi][subj++] = matrix[i][j];  //prima copia il valore nella sottomatrice, poi aggiorna subj 
		}
		subi++;
	}
}

int** malloc_matrix(int n){
	int **mat = malloc(n * sizeof(int*));  //alloca array di righe
	for(int i=0; i<n; i++){
		mat[i] = malloc(n * sizeof(int));  //Alloca le colonne per ogni riga
	}
	return mat;
}

void free_matrix(int **matrix, int n){
	for(int i=0; i<n; i++){
		free(matrix[i]);  //libera ogni riga
	}	
	free(matrix);  //libera l'array di puntatori
}

void print_matrix(int **matrix, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d    ", matrix[i][j]);
		}
		putchar('\n');
	}
}
