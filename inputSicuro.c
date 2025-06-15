#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

//è buona pratica avere almeno il doppio della dimensione necessaria
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

		if(strchr(input, '\n') == NULL){  //Se nell'input non viene trovato '\n' (perché input troppo grande)
			int ch;
			while((ch = getchar()) != '\n' && ch != EOF);  //Pulisce il buffer
		}

		input[strcspn(input, "\n")] = '\0';   //Mette il carattere di terminazione delle stringhe '\0' al posto del newLine

		errno = 0;      //Imposta a zero la variabile errno, che viene modificata se una conversione non va a buon fine
		//mette in "rimanente" i caratteri che non sono numeri, ad esempio se si inserisce 123ab
		numero = strtol(input, &rimanente, 10);  //10 è la base

		if(errno != 0){  //se errno viene modificato la conversione strtol non è andata a buon fine
			perror("Errore di conversione");
			continue;
		}
		if(*rimanente != '\0'){   //se in rimanente ci sono delle lettere significa che sono state inserite nell'input
			puts("Input non valido: sono ammessi solo numeri interi");
			continue;
		}
		if(numero<min || numero>max){
			printf("Errore, il numero deve essere compreso tra %d e %d\n", min, max);
			continue;
		}
		if(numero<INT_MIN || numero>INT_MAX){   //INT_MIN e INT_MAX fanno parte di <limits.h>
			puts("Errore: il numero inserito è fuori dai limiti del tipo int");
			continue;
		}
		return (int)numero;  //strtol restituisce un long int, per cui si fa la conversione a int
	}
}

int main(){
	int valore = leggi_intero(1, 100);	
	printf("Hai inserito il numero %d\n", valore);
	return EXIT_SUCCESS;
}


