#ifndef BOW_H
#define BOW_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word_count_struct {
  char *word;
  int count;
};


struct bag_struct {
  struct word_count_struct *bag;
  int bag_size;
  int total_words;
};

struct bag_struct *new_bag();
int isLetter(char letter);
int bagsearch(struct bag_struct *bow, char *word);
char *get_word(char **string_ptr);
struct word_count_struct *new_word_count(char *word);
void add_word(struct bag_struct *bow, char *word);
void add_text(struct bag_struct *bow, char *line);
void read_sms_data(struct bag_struct *bow, char *label);
void differences(struct bag_struct *ham, struct bag_struct *spam);

#endif
