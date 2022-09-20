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
  if(str== '\0'){
    return str;
  }
  while(space_char(str)) {

    if(non_space_char(*str)) {
      return str;
    }
    str++;
  }

  return str;
}
  char *word_terminator(char *word)
  {

    // word=word_start(word);

    while(non_space_char(word)){

      word++;

    }

    return word;

  }

int count_words(char *str){
  int counter=1;
  int state=0;
  //scan all characters one by one
  while(str){
    //If next char is serperator, add to counter, this is the end of a word
    //add to counter
    if(non_space_char(str)==1){
      state=0;
    }
    else if(state==0){
      state=1;
      counter++;
    }
    //move to next char
    str++;
  }
  return counter;
} /*
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
    printf("%s\n", *tokens);
    tokens++;
  }
}
void free_tokens(char **tokens){
  char**temp=tokens;

  while(*temp!="") // Till we not find the last empty string
    {
      free(*temp);
      temp++;
    }
  free(temp);
  }**/
