#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cypher(char* frase, int jump);
void decypher(char* frase, int jump);

int main(){
	int jump = 2000;

	char frase[] = "Stringa da cifrare";
	cypher(frase, jump);
	printf("%s\n", frase);
	
	decypher(frase, jump);
	printf("%s\n", frase);
	
}

void cypher(char* frase, int jump){
	for(int i=0, len = strlen(frase); i<len; i++){
		if(isalpha(frase[i])){
			char base = isupper(frase[i]) ? 'A' : 'a';
			frase[i] = (frase[i] - base + jump) % 26 + base;
		}
	}
}

void decypher(char* frase, int jump){
	for(int i=0, len = strlen(frase); i<len; i++){
		if(isalpha(frase[i])){
			char base = isupper(frase[i]) ? 'A' : 'a';
			frase[i] = ((frase[i] - base - jump)%26 + 26) % 26 + base;
		}
	}
}
