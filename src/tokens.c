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

    else if(space_char(*string) == 1 && words == 1) {

      words = 0;

    }

    string++;

  }

  return count;
} 
    char *copy_str(char *inStr, short len){
      //make memory avialalve for token
      char *output = (char*) malloc(sizeof(char) * len+ 1);



      if(!output){

	exit(EXIT_FAILURE);

      }



      char *c = output;



      for(short k=0; k < len; k++) {

	*c = *inStr;

	if(*c=='\0'){

	  break;

	}

	c++;

	inStr++;

      }

      *c=='\0';

      return output;
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
      int count = count_words(str);

      char** tokens = (char**)malloc((count+1) * (sizeof(char*)));

      char* temp = str;

      for (int i = 0; i < count; i++)

	{

	  temp = word_start(temp);

	  tokens[i] = copy_str(temp, (word_terminator(temp) - word_start(temp)));

	  temp = word_terminator(temp);

	}

      tokens[count] = '\0';

      return tokens;

    }		      
void print_tokens(char **tokens){
  for(char** token = tokens; *token != 0; token++) {

    printf("[%ld]%s\n", token - tokens, *token);

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
