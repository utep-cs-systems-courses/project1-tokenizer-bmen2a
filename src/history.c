#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
/* Initialize the linked list to keep the history. */

List *init_history()

{

  // create a new List structure variable

  List *list =(List*)malloc (sizeof(List));
  list -> root=malloc(sizeof(Item));
  // return the pointer to the List

  return list;

}
short find_len(char *str)

{

  short i = 0;

  while(str[i] != '\0')

    {

      i++;

    }

  return i;

}
void add_history(List *list, char *str){
  int c = 1;
  Item *temp = list->root;

  if(list->root == NULL)

    {

      list->root = (Item*)malloc(sizeof(Item));

      list->root->id = c++;

      list->root->str = copy_str(str,find_len(str));

      list->root->next = NULL;

    }

  else

    {

      while(temp->next != NULL)

	{

	  temp = temp->next;

	}

      temp->next = (Item*)malloc(sizeof(Item));

      temp->next->id = c++;

      temp->next->str = copy_str(str,find_len(str));

      temp->next->next = NULL;

    }
  
}
char *get_history(List *list, int id){
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
	  return ptr -> str;
	}
      // otherwise, move ahead
      ptr = ptr -> next;
    }
  // if nothing's found, return empty string
  return '\0';
}

void print_history(List *list){
    Item *tmp = list->root;

    while(tmp!=NULL){

      printf("%d- %s\n",tmp->id, tmp->str);

      tmp=tmp->next;

    }

    printf("\n");
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
