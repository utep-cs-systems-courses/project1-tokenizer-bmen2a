#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){ /*Returns 0 if whitespace character, return 1 if non whitespace*/
  int i=1;
  if (c == ('\t') || c == (' ')){
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
  int i=0;
  while (space_char(str[i]==1)){
      if(str[i]=='\0'){
	return NULL;
      }
      i++;
    }
  return &str[i];
}
  char *word_terminator(char *word){
    word=word_start(word);
    //check if its at the end already
    if(word==NULL)
      return NULL;
    int i=0;
    while(non_space_char(word[i])==1){
      if(word[i]=='\0')
	return &word[i-1];
      i++;
      }
      return &word[i];
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
      int i=0;
      char *outStr= malloc((len+1)*sizeof(int));
      if(outStr==NULL){
	fprintf(stderr, "Error\n");
	return NULL;
      }//wihle loop to copy string
      while(i<len){
	outStr[i]=inStr[i];
	i++;
      }
      outStr[i]='\0'; //set the end of String
      return outStr;
    }
    char **tokenizer (char* str){
      int i=0;
      int all=count_words(str);
      char **tokens=malloc((all+1)*sizeof(char*));
    if(tokens==NULL){
      fprintf(stderr, "error: allocating memory\n");
      return NULL;
    }
    tokens[i]=NULL;
    return tokens;
    }
void print_tokens(char **tokens){
  
  while(tokens!=NULL){
    printf("%s\n", tokens);
    tokens++;
  }
}
void free_tokens(char **tokens){
  free(tokens);// the free method releases the memory at that address
}
