#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  if(c == '\t' || c == ' ' || c == '\0')
    return 1;
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c) {
  if(c == '\t' || c == ' ' || c == '\0')
    return 0;
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str) {
  while(space_char(*str)) {
    str++;
  }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word) {
  while(non_space_char(*word)) {
    word++;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str) {
  char *word = str;
  int c = 0;

  while(*word) {
    //simplified word counter by moving between words
    word = word_start(word);
    word = word_terminator(word);

    c++;
  }
  return c;
}

/* Returns a freshly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  char *copy = (char*)malloc((len+1) * sizeof(char));

  for(int i = 0; i < len; i++) {
    copy[i] = inStr[i];
  }
  copy[len] = '\0';

  return copy;
}

/* Prints all tokens */
void print_tokens(char **tokens) {
  int i = 0;
  
  while(tokens[i]) {
    printf("[%d]: %s ", i, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing them */
void free_tokens(char **tokens) {
  int i = 0;

  while(tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str) {
  char *wordPointer = str;
  int i = 0;
  int words = count_words(wordPointer);//number of words
  char **tokens = (char**)malloc((words+1)*sizeof(char*));//allocate array

  while(i < words) {
    wordPointer = word_start(wordPointer);//start of next word
    char *currWord = copy_str(wordPointer,word_terminator(wordPointer)-wordPointer);//allocate word
    wordPointer = word_terminator(wordPointer);//move to next word

    tokens[i] = currWord;//add current word to array
    i++;
  }
  
  tokens[i] = '\0';//terminate array
  return tokens;
}
