#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
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

   char hello[] = "Hello world";

   char *str = hello;

   int id_tracker = 1;



   char array [30];

   while (1)

     {

       char* temp = str;

       List *strings;

       strings = init_history();



       printf("->");

       fgets(array, 29, stdin);

       char *str = &array[0];



       if (*str == 'q') // quit

	 {

	   exit(0);

	 }



       char** tokenizer = tokenize(str);

       print_tokens(tokenizer);



       List *list = init_history();



       //      char string[29] = *str;



       /*if (*str == "!1")

	 {

	   print_tokens(tokenize(get_history(list,1)));

	   }

      if (strcmp(*str,"!2"))

      {

        print_tokens(tokenize(get_history(list,2)));

	}

      if (*str == "!3")

      {

        print_tokens(tokenize(get_history(list,3)));

	}

      if (*str == "!4")

      {

      }

       */



       add_history(list, str);

       print_history(list);

       free_tokens(tokenizer);

       free_history(list);
       id_tracker++;
     }
}

