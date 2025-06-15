#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define INPUT_SIZE 32

int leggi_intero(int min, int max){
	char input[INPUT_SIZE];
	char *rimanente = NULL;
	long numero;

	while(1){
		printf("Inserisci numero tra %d e %d\n", min, max);

		if(!fgets(input, sizeof(input), stdin)){
			fputs("Errore nella lettura dell'input\n", stderr);
			exit(EXIT_FAILURE);
		}

		if(strchr(input, '\n') == NULL){
			int ch;
			while((ch = getchar()) != '\n' && ch != EOF);
		}

		input[strcspn(input, "\n")] = '\0';

		errno = 0;
		numero = strtol(input, &rimanente, 10);

		if(errno != 0){
			perror("Errore di conversione");
			continue;
		}
		if(*rimanente != '\0'){
			puts("Input non valido: sono ammessi solo numeri interi");
			continue;
		}
		if(numero<min || numero>max){
			printf("Errore, il numero deve essere compreso tra %d e %d\n", min, max);
			continue;
		}
		if(numero<INT_MIN || numero>INT_MAX){
			puts("Errore: il numero inserito è fuori dai limiti del tipo int");
			continue;
		}
		return (int)numero;
	}
}

int main(){
	int valore = leggi_intero(1, 100);	
	printf("Hai inserito il numero %d\n", valore);
	return EXIT_SUCCESS;
}


