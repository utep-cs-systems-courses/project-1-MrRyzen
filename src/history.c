#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

//Counts the char in the string
int str_length(char *str) {
  short c = 0;

  while(*str) {
    str++;
    c++;
  }
  return c-1;
}

/* Initialize the linked list to keep the history. */
List* init_history() {
  List *history = (List*)malloc(sizeof(List*) * 100);
  return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  //allocate memory for item and str
  Item *item = (Item*)malloc(sizeof(Item*)*100);
  item->str = copy_str(str, str_length(str)+1);
  //if root is not null add to the list by iteration
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
  //if no root add it
  else {
    item->id = 1;
    list->root = item;
  }
}
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  //just return if empty
  if(list == NULL && list->root == NULL)
    return 0;
  Item *itr = list->root;
  //itr through the list and return the str
  while(itr != NULL) {
    if(itr->id == id)
      return itr->str;
    itr = itr->next;
  }
  return 0;
}

/* Print the entire contents of the list. */
void print_history(List *list) {
  Item *itr = list->root;

  while(itr != NULL) {
    printf("> %d: %s", itr->id, itr->str);
    itr = itr->next;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list) {
  Item *itr = list->root;
  //free all the items and strings
  while(itr->next != NULL) {
    free(itr->str);
    free(itr);
    itr = itr->next;
  }
  //free list and iterator
  free(list);
  free(itr);
}
