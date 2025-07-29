#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	const char* plaintext = "Encryption with xor!";
	int text_len = strlen(plaintext);
	char *key = malloc((text_len + 1) * sizeof(char));
    char *encrypted_text = malloc((text_len + 1) * sizeof(char));
    char *decrypted_text = malloc((text_len + 1) * sizeof(char));
		

	srand(time(NULL));

	for(int i=0; i<text_len; i++){
		int casing = rand() % 2;
		key[i] = (casing == 0) ? ('a' + rand() % ('z' - 'a' + 1)) : ('A' + rand() % ('Z' - 'A' + 1));
		//key[i] = 32 + rand() % (126 - 32 + 1);  safer key
		encrypted_text[i] = plaintext[i] ^ key[i];
		decrypted_text[i] = encrypted_text[i] ^ key[i];
	}
	key[text_len] = '\0';
	encrypted_text[text_len] = '\0';
	decrypted_text[text_len] = '\0';

	printf("\n%-15s%-14s%-15s%-15s\n", "plaintext", "key", "encrypted", "decrypted");
	for(int i=0; i<text_len; i++){
		printf("  %c\t\t%c\t\t%3d\t\t%c\n", plaintext[i], key[i], (unsigned char)encrypted_text[i], decrypted_text[i]);
	}
	printf("\nkey = %s\nencrypted text = %s\ndecrypted text = %s\n", key, encrypted_text, decrypted_text);
	
	free(key);
	free(encrypted_text);
	free(decrypted_text);

}
