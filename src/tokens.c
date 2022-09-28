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

int count_words(char *str){
  int count =1;
  while(str != '\0'){
    str=word_start(str);
    str=word_terminator(str);
    count++;
  }
  return count;
} 
    char *copy_str(char *inStr, short len){
      //make memory avialalve for token
      char *ans=malloc((len+1)*sizeof(char));
      int i=0;
      while(i <len){
	ans[i]=inStr[i];
	i++;
      }
      ans[i]= '\0';
      
      return ans;
 }
//helper mehtod
short word_length(char *str){
  short size;
  char* start=word_start(str);
  char *end=word_terminator(start);
  size=end-start;
  return size;
}
    char **tokenize(char* str){
      int size=count_words(str);
      char **tokens = malloc((size + 1) * sizeof(char *));
      int i;
      int length;
      char *p = str;
      for(i = 0;i < size;i++){
	p = word_start(p);
	tokens[i] = copy_str(p, length);
	p = word_terminator(p);
      }
      tokens[i] = '\0';
      return tokens;
    }
void print_tokens(char **tokens){
  int i=0;
  while(tokens[i]){
    printf("Token[%s]\n", tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens){
  for(int i=0; tokens[i] !='\0'; i++){
    free(tokens[i]);
  }
  free(tokens);
  }
