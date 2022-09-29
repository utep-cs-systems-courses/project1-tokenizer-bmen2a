#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
int main(){
  // int i=space_char('h');
  // int nonSpace=non_space_char('h');
  //   char s[]="My Dog flees";
  // char *pointer=s;
   // char start=word_start(*pointer);
  //     char end=word_terminator(*pointer);
  // int count=count_words(*pointer);
   //short len=(short)malloc(sizeof(short)*(pointer)
   	 char userResponse[64];

	 List *hist = init_history();
	 int i=0;
	 // add_history(hist, "ajhebvhlb");

	 // add_history(hist, "gg ez");

	 while(1){

	   printf("Would you like to access your history or tokenize? (!h or !t)\n");

	   printf("> ");

	   fgets(userResponse,64, stdin);

	     if(userResponse[1] == 'h'){
	       // get_history(hist, i);
	       print_history(hist);
	       free_history(hist);
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
	       i++;
	     }



	 }

	 return 0;
    }

       
