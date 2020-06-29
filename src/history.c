#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int str_length(char *str) {
  short c = 0;

  while(*str) {
    str++;
    c++;
  }
  return c-1;
}

List* init_history() {
  List *history = (List*)malloc(sizeof(List*) * 100);
  return history;
}

void add_history(List *list, char *str) {
  Item *item = (Item*)malloc(sizeof(Item*)*100);
  item->str = copy_str(str, str_length(str)+1);

  if(list->root != NULL) {
    Item *itr = list->root;
    item->id = 1;

    while(itr->next != NULL) {
      item->id++;
      itr = itr->next;
    }

    itr->next = item;
    item->id++;
  }
  else {
    item->id = 1;
    list->root = item;
  }
}

char *get_history(List *list, int id) {
  if(list == NULL && list->root == NULL)
    return 0;
  Item *itr = list->root;
  while(itr != NULL) {
    if(itr->id == id)
      return itr->str;
    itr = itr->next;
  }
  return 0;
}

void print_history(List *list) {
  Item *itr = list->root;

  while(itr != NULL) {
    printf("> %d: %s", itr->id, itr->str);
    itr = itr->next;
  }
}

void free_history(List *list) {
  Item *itr = list->root;

  while(itr->next != NULL) {
    free(itr->str);
    free(itr);
    itr = itr->next;
  }
  free(list);
  free(itr);
}
