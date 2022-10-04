#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){ /*Returns 0 if whitespace character, return 1 if non whitespace*/
  if (c == ('\t') || c == (' ')|| c==('\n')|| c==('\v')|| c==('\f')|c==('\r')){
      return 1;
    }
  return 0;
}
int non_space_char(char c){
  if(c !=('\t') && c !=(' ') && c !=('\0')){
     return 1;
    }
   return 0;
}
char *word_start(char *str){
  while(space_char(str)) {

    if(non_space_char(str)) {
      return str;
    }
    str++;
  }

  return str;
}
  char *word_terminator(char *word)
  {

    while(non_space_char(word)){

      if(space_char(word)){

	return word;

      }
      word++;
    }

    return word;

  }

int count_words(char *string){
  int words=0;
  int count=0;
  while(*string != '\0') {
    if(non_space_char(*string) && words == 0) {
      
      count++;
      words = 1;
    }
    else if(space_char(*string) == 1 && words == 1){
      words = 0;
    }
    string++;
  }
  return count;
}
   char *copy_str(char *inStr, short len){
      char *copyStr = malloc(( len + 1) * sizeof(char));

      int i;

      for (i=0; i < len; i++){

	copyStr[i] = inStr[i];

      }

      copyStr[i] = '\0';

      return copyStr;
 }

    char **tokenize(char* str){
      int word_len = count_words(str);

      //Reserves memory used for string

      char **tokens=(char**)malloc(sizeof(char*)*(word_len+1));



      //Initializes the start and end pointers

      char *start = str;

      char *end = word_terminator(str);





      for(int i = 0; i < word_len; i++)

	{

	  //Initializes the pointers to the next start and end of current word

	  if(i > 0)

	    {

	      start = word_start(end);

	      end = word_terminator(start);

	    }

	  //Finds the length of the current word

	  int word_size = end - start;



	  //Reserves memory for current word in 2D array

	  tokens[i] = malloc(word_len*sizeof(char));



	  //Populates array with the current word

	  for(int j = 0;j < word_size;j++)

	    {

	      tokens[i][j] = start[j];

	    }

	}

      //Last is 0

      tokens[word_len] = 0;

      return tokens;
    }		      
void print_tokens(char **tokens){
  for(int i = 0; tokens[i] != 0; i++){
      printf("tokens[%i] = %s\n",i,tokens[i]);
    }
}

void free_tokens(char **tokens){
  int k = 0;

  //frees elements within tokens

  while(tokens[k]) {

    free(tokens[k]);

    k++;

  }

  //frees an empty tokens

  free(tokens);
}
