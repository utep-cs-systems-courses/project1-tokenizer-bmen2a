#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
int main(){
  // int i=space_char('h');
  // int nonSpace=non_space_char('h');
   char s[]="My Dog flees";
    char *pointer=s;
   // char start=word_start(*pointer);
  //     char end=word_terminator(*pointer);
    int count=count_words(*pointer);
   //short len=(short)malloc(sizeof(short)*(pointer);
    // char copy=copy_str(*pointer,15); 
   // printf("This is my test, so it works\n %d \n ",i);
   // printf("This is non space char %d\n", nonSpace);
   //printf("This is my word start %c\n", start);
   //   printf("", *pointer);
   //    printf("This is my word terminator %c \nHow is i this", end);
   printf("This is my word counter test, %d \n", count);
   //      printf("This is my string %s\n", s);
   // printf("this is my copy string %s \n", copy );
   //char tokens=tokenize(*pointer);
   //printf("This iy my tokens %s \n", tokens);
  // char **tokens=*pointer;
  // prin
   /*	 char userResponse[64];

	 List *hist = init_history();

	 // add_history(hist, "ajhebvhlb");

	 // add_history(hist, "gg ez");

	 while(1){

	   printf("Would you like to access your history or tokenize? (!h or !t)\n");

	   printf("> ");

	   fgets(userResponse, 64, stdin);

	   if(userResponse[0] == '!'){

	     if(userResponse[1] == 'h'){

	     }
	     if(userResponse[1]=='q'){
	       break;
	     }

	     if(userResponse[1] == 't'){

	       printf("Type in your string: \n");

	       printf("> ");

	       fgets(userResponse, 64, stdin);

	       add_history(hist, userResponse);

	       char **tokens = tokenize(userResponse);

	       print_tokens(tokens);

	     }

	   }



	 }

	 return 0;
   */ }

       
