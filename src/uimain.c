#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
int main(){
      	 char userResponse[20];

	 List *hist = init_history();
	 int i=0;
	  add_history(hist, "ajhebvhlb");
	  
	  add_history(hist, "gg ez");
	  char *id=get_history(hist, 1);
	  printf("String stored into this %s \n",id);
	 // print_history(hist);
	  char s[]="My dog fless";
	  char *pointer=s;
	  char **tokens=tokenize(pointer);
	  print_tokens(tokens);
	  

	 while(1){

	   printf("Access your history or tokenizeor quit? (h or t or q)\n");

	   printf("== ");

	   fgets(userResponse,64, stdin);

	     if(userResponse[0] == 'h'){
	       // get_history(hist, i);
	        print_history(hist);
	       // free_history(hist);
		printf("Woudl you like to clear history or get history ?(c or g)\n");
		printf("==");
		fgets(userResponse, 64,stdin);
		if(userResponse[0]=='y'){
		  free_tokens(userResponse);
		  free_history(hist);
		}
		if(userResponse[0]=='g'){
		  printf("Enter a number\n");
		  fgets(userResponse[0],64,stdin);
		  printf("%s \n",get_history(hist, userResponse));
		}
		
	     }
	     if(userResponse[0]=='q'){
	       break;
	     }

	     if(userResponse[0] == 't'){

	       printf("Type in your string: \n");

	       printf("> ");

	       fgets(userResponse, 64, stdin);

     	       add_history(hist, userResponse);
	       // print_history(hist);
	       char **tokens = tokenize(userResponse);

	       print_tokens(tokens);
     	     }
	 }

	 return 0;
    }

       
