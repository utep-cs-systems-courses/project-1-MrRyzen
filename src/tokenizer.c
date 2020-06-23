#include <stdio.h>
#include "tokenizer.h"

int space_char(char c) {
  if(c == ' ' || c == '\t')
    return 1;
  return 0;
}

int main() {
  char str[100];

  printf("> ");
  gets(str);

  printf("\n You Entered: ");
  puts(str);

  

  return 0;

}
