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
  while(space_char((char)*str)) {

    if(non_space_char((char)*str)) {
      return str;
    }
    str++;
  }

  return str;
}
  char *word_terminator(char *word)
  {
    while(non_space_char((char)*word)){

      if(space_char((char)*word)){
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
    if(non_space_char((char)*string) && words == 0) {
      count++;
      words = 1;
    }
    else if(space_char((char)*string) == 1 && words == 1){
      words = 0;
    }
    string++;
  }
  return count;
}
   char *copy_str(char *inStr, short len){
     char *copyStr =(char*)malloc(( len + 1) * sizeof(char));
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
      char *start;
      char *end;
    
      for(int i = 0; i < word_len; i++)
      {
	str = word_start((char*)str);   
	  end = word_terminator((char*)start);
	  //Finds the length of the current word
	  int word_size = end - str;
	  //Reserves memory for current word
	  tokens[i] = copy_str((char*)start,word_size);
	  str = end;
       }
      //Last is 0
      tokens[word_len] = 0;
      return tokens;
    }

void print_tokens(char **tokens){
  int i=0;
  while(tokens[i] != 0){
    printf("Tokens[%d] = %s \n", i, tokens[i]);
    i++;
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
