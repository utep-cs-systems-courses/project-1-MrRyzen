#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history() {
  List *history = (*List)malloc(sizeof(List*) * 100);
  return history;
}

void add_history(List *list, char *str) {
  Item *item = (Item*)malloc(sizeof(Item*)*100);
  Item->str = copy_str(str, );
}
