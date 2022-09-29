#include <stdio.h>

#include <stdlib.h>

#include "history.h"

/* Initialize the linked list to keep the history. */

List* init_history()

{

  // create a new List structure variable

  List * list = malloc (sizeof (List));



  // set it's head to NULL as it is empty

  list ->root = NULL;



  // return the pointer to the List

  return list;

}


int str_len(char *str){

  char *ptr = str;

  while(ptr != "/0") {

    ptr++;

  }

  return ptr-str;

}

void add_history(List *list, char *str){
  int pos = 1;

  Item *tmp = list->root;

  while(tmp){

    tmp = tmp->next;

    pos++;

  }

  tmp=malloc(sizeof(Item));

  tmp->id = pos;

  tmp->word = str;
}



char *get_history(List *list, int id)

{

  // initialize a variable to the start of the list

  Item * ptr = list ->root;



  // traverse the list till the end

  while (ptr != NULL)

    {

      // if the id of the item is equal to

      // id parameter of the function

      if (ptr -> id == id)

	{

	  // return the string stored in the item

	  return (ptr -> str);

	}



      // otherwise, move ahead

      ptr = ptr -> next;

    }



  // if nothing's found, return empty string

  return '\0';

}



void print_history(List *list)

{

  if (!list){

    printf("History is empty, please enter some sentences.\n");

  }

  else{

    Item *tmp = list->root;

    while(tmp){

      printf("%d: %s\n",tmp->id,tmp->next);

      tmp->next;

    }

    printf("\n");

  }
}
void free_history(List *list)

{
  Item *tmp;
  Item *head = list->root;
  while(head){
    tmp = head;
    head = head->next;
    free(tmp);
  }
}
