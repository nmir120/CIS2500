
#include "bow.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char *word;
	char *sentence = "^*^^%";

	printf("sentence = \"%s\"\n", sentence);

	while(*sentence){
		word = get_word(&sentence);
		printf("word = \"%s\"; sentence = \"%s\"\n", word, sentence);

		free(word);
	}
	return 0;

}
