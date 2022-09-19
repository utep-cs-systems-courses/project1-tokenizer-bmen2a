#include <stdio.h>
//#include "tokens.c"
#include "tokenizer.h"
int main(){
  int i=space_char('h');
   int nonSpace=non_space_char('h');
   char s[]="My Dog flees";
   char *pointer=s;
   char start=word_start(*pointer);
  printf("This is my test, so it works\n %d \n ",i);
  printf("This is non space char %d\n", nonSpace);
  printf("This is my word start %c", start);
}

