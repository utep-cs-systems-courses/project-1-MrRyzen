#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  //global variables
  char str[100];//input
  char **tokens;
  List *history = init_history();
  int exit = 1;//exit boolean for program

  printf("\n$ Type !h for help");
  //Controls program runtime
  while(exit) {
    printf("\n> ");
    fgets(str, sizeof(str), stdin);//takes input from user
    printf("\n$ You entered: %s", str);//Echos user input

    //Command controller
    if(str[0] == '!') {
      int i = str[1] - '0';//casting second char into int for command
      if(str[1] == 'e')//exit
	exit = 0;
      else if(str[1] == 'h')//help
	printf("\n$ !n where n is a integer pertaining to history\n$ !e to exit\n$ !a to print all history\n$ Lastly typing a sentence will tokenize it");
      else if(str[1] == 'a')//print all history
	print_history(history);
      //gets history
      else if(i > 0) {
	char *str = get_history(history, i);
	//runs through tokenizer again with previous input
	tokens = tokenize(str);
	printf("\n$ ");
	print_tokens(tokens);
	free_tokens(tokens);
      }
      else//invalid command
	printf("\n$ Invalid command");
    }
    //tokenizes sentence if not a command
    else {
      tokens = tokenize(str);
      printf("\n$ ");
      print_tokens(tokens);//tokenized sentence
      free_tokens(tokens);//frees tokens
      add_history(history, word_start(str));//add to history
    }
  }
  //free history
  free_history(history);
  return 0;
}
