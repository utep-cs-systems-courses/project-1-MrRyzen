#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c) {
  if(c == '\t' || c == ' ' || c == '\0')
    return 1;
  return 0;
}

int non_space_char(char c) {
  if(c == '\t' || c == ' ' || c == '\0')
    return 0;
  return 1;
}

char *word_start(char *str) {
  while(space_char(*str)) {
    str++;
  }
  return str;
}

char *word_terminator(char *word) {
  while(non_space_char(*word)) {
    word++;
  }
  return word;
}

int count_words(char *str) {
  char *word = str;
  int c = 0;

  while(*word) {
    word = word_start(word);
    word = word_terminator(word);

    c++;
  }
  return c;
}

char *copy_str(char *inStr, short len) {
  char *copy = (char*)malloc((len+1) * sizeof(char));

  for(int i = 0; i < len; i++) {
    copy[i] = inStr[i];
  }
  copy[len] = '\0';

  return copy;
}

void print_tokens(char **tokens) {
  int i = 0;
  
  while(tokens[i]) {
    printf("%d: %s ", i, tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens) {
  int i = 0;

  while(tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}

char **tokenize(char *str) {
  char *wordPointer = str;
  int i = 0;
  int words = count_words(wordPointer);
  char **tokens = (char**)malloc((words+1)*sizeof(char*));

  while(i < words) {
    wordPointer = word_start(wordPointer);
    char *currWord = copy_str(wordPointer,word_terminator(wordPointer)-wordPointer);
    wordPointer = word_terminator(wordPointer);

    tokens[i] = currWord;
    i++;
  }
  
  tokens[i] = '\0';
  return tokens;
}
