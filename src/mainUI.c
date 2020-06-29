#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main() {
  char str[100];

  printf("> ");
  fgets(str, sizeof(str), stdin);
  printf("You entered: %s", str);

  printf("Tokenizing...\n");
  char **tokens = tokenize(str);

  printf("Printing...\n");
  print_tokens(tokens);
  printf("Clearing...\n");
  free_tokens(tokens);
  print_tokens(tokens);
  
  return 0;
}
