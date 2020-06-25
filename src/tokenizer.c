#include <stdio.h>
#include "tokenizer.h"

int space_char(char c) {
  if(c == ' ' || c == '\t' || c == 0)
    return 1;
  return 0;
}

int non_space_char(char c) {
  if(c != ' ' && c != '\t' && c != 0)
    return 1;
  return 0;
}

char *word_start(char *str) {
  int i = 0;
  while(space_char(str[i]))
    i++;
  return &str[i];
}

int main() {
  char str[100];

  printf("> ");
  fgets(str, 101, stdin);
  char *c = *word_start(str);
  printf(c);

  printf("You Entered: %s\n", str);

  return 0;
}
