#include <stdio.h>
#include <stdlib.h>
//#include "tokens.c"
#include "tokenizer.h"
int main(){
  // int i=space_char('h');
  // int nonSpace=non_space_char('h');
   char s[]="My Dog flees";
   char *pointer=s;
   // char start=word_start(*pointer);
   //      char end=word_terminator(*pointer);
   // int wordCounter=count_words(*pointer);
   //short len=(short)malloc(sizeof(short)*(pointer);
   //   char copy=copy_str(*pointer,15); 
   // printf("This is my test, so it works\n %d \n ",i);
   // printf("This is non space char %d\n", nonSpace);
   // printf("This is my word start %c\n", start);
   //   printf("", *pointer);
      //    printf("This is my word terminator %c \nHow is i this", end);
   // printf("This is my word counter test, %d \n", wordCounter);
   //   printf("This is my string %s\n", s);
   // printf("this is my copy string %s \n", copy );
   //char tokens=tokenize(*pointer);
   //printf("This iy my tokens %s \n", tokens);
   char **tokens=*pointer;
   print_tokens(tokens);
   
}

