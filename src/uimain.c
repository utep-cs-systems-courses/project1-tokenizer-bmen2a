#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
int main(){
  // int i=space_char('h');
  // int nonSpace=non_space_char('h');
  //  char s[]="My Dog flees";
  // char *pointer=s;
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
  // char **tokens=*pointer;
  // print_tokens(tokens);
   printf("Hello! Please enter one of the following characters:\n");

   {

     int i;

     int numHistory=-1;

     char str[100];

     List *history = init_history();

     char str[100];

     int numHistory;

     char *strHistory;

     printf("Hello! Please enter one of the following characters:\n");



     while(1){
       printf("1. Enter 's' to type and record your sentence\n2. Enter '!' followed by a number to display a certain sentence from history\n3. Enter '!h' to display all recorded sentences\n ");

       printf("$");

       printf("$ ");



       fgets(str,100,stdin);

       //printf("%d\n",word_length(str));

       i = menuOpt(str);

       switch(i)//i

	 {

	 case 1: printf("Please enter your sentence:\n");

	 case 1:

	   printf("Please enter your sentence:\n$");

	   fgets(str, 100, stdin);

	   char **tokens = tokenize(str);

	   printf("\n");

	   print_tokens(tokens);

	   add_history(history, *tokens);

	   free_tokens(tokens);

	   break;



	 case 2:

	   if(*(str+1) == '0'){

	     printf("Please enter a number to display sentence from history or enter 'h' to display all recorded sentences:\n$ ");



	     fgets(str, 100, stdin);

	     char **tokens = tokenize(str);

	     print_tokens(tokens);

	     free_tokens(tokens);

	     break;



	   case 2: if (str[1]=='0'){

	       printf("Please enter a number to display sentence from history or enter 'h' to display all recorded sentences:\n");

	       fgets(str, 100, stdin);

	       if ((str[0]=='h'||str[0]=='H')&& !(str[1])){

		 //print_history();

		 break;

	       }
	       //printf(get_history(history,atoi(str)));

	       if ((str[0]=='h'||str[0]=='H')&& str[1] == '0'){

		 print_history(history);

		 break;

	       }
	     }

	       else{

		 if (str[1]=='h'||str[1]=='H'){

		   //print_history();

		   break;

		 }

		 //printf(get_history(history,atoi(str)));

		 strHistory = get_history(history,atoi(str));

		 if(*strHistory=='\0'){

		   continue;

		 }

		 printf("%s",str);

	       }

	       else{

		 if ((str[1]=='h'||str[1]=='H')&& str[2] == '0'){

		   print_history(history);

		   break;

		 }

		 strHistory = get_history(history,atoi(str));

		 if(*strHistory=='\0'){

		   continue;

		 }

		 printf("%s",str);
	       }

	       else{

		 if ((str[1]=='h'||str[1]=='H')&& str[2] == '0'){

		   print_history(history);

		   break;

		 }

		 strHistory = get_history(history,atoi(str));

		 if(*strHistory=='\0'){

		   continue;

		 }

		 printf("%s",str);

	       }



	     case 3: printf("Thank you, Goodbye!\n");

	       //free_history(history);

	       return 0;

	     case 3:

	       printf("Thank you, Goodbye!\n");

	       free_history(history);

	       return 0;



	     default:    printf("Sorry, that was not a valid option please try again.\n");

	       break;

	     default:

	       printf("Sorry, that was not a valid option please try again.\n");

	       break;

	     }

	 }
}
