#incldue <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){ /*Returns 0 if whitespace character, return 1 if non whitespace*/
  int i=1;

  if (c == ('\t') || c == (' '))
    {
      i= 0;

    }
  return i;
}
int non_space_char(char c){
  if( c==('\t') || c ==(' ')){
    return 0;
  }
  return 1;
}
char *word_start(char *str){
  while (*str != '\0' && !isspace(*str ){
      str++;
    }
  return str;
}
  char *word_terminator(char *word){
    while( *word == '\0' && isspace(*word){
	word++;
      }
      return word;
  }
    int count_words(char *str){
      int counter;
      while( *str != '\0'){
	str++;
	counter++;
      }
      return counter;
    }
    char *copy_str(char *inStr, short len){
      *inStr= (char*) malloc(len*sizeof(int));
    }
