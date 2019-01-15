#include "bow.h"
#include <stdlib.h>

struct bag_struct *new_bag(){

	return NULL;
}
int bagsearch(struct bag_struct *bow, char *word){
	
	return 0;
}
int isLetter(char letter){
	if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')){
		return 1; /*returns 1 if letter*/
	}
	else{
		return 0; /*returns 0 if not a letter*/
	}
}
char *get_word(char **string_ptr){
	int i = 0;
	char *word;

	word = malloc(919);

	while(isLetter(**string_ptr) == 0 && isLetter(**string_ptr) != '\0'){
		*string_ptr += 1;
	}
	if((**string_ptr) == '\0'){
		free(word);
		return NULL;
	}
	while(isLetter(**string_ptr) == 1){
		word[i] = **string_ptr;
		++i;
	}
	word = (char *) realloc(word, 1);
	strncpy(word, *string_ptr, 1);
	*string_ptr += 1;
	word[i] = 0;

	return word;
}
struct word_count_struct *new_word_count(char *word){

	return NULL;
}
void add_word(struct bag_struct *bow, char *word){
	
}
void add_text(struct bag_struct *bow, char *line){

}
void read_sms_data(struct bag_struct *bow, char *label){

}
void differences(struct bag_struct *ham, struct bag_struct *spam){

}
