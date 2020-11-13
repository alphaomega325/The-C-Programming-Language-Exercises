#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void self_implemented_getline(char line[], int *len);
void copy(char to[], char from[]);
void remove_trailing_blanks(char s[], int *len);

/* print the longest input line */
int main(){

  int len = 0;               /* current line length */
  int max;               /* maximum length seens so far */
  char *line;    /* current input line */
  char *longest;      /* longest line saved here */
  int *lenptr = &len;

  line = malloc(INT_MAX * sizeof(char));
  longest = malloc(INT_MAX * sizeof(char));
  
  max = 0;
  do{
    self_implemented_getline(line, lenptr);
    if (len > max) {
      remove_trailing_blanks(line, lenptr);
      if(len > max){
	max = len;
	copy(longest, line);
      }
    }
  }while(len > 0);

  if (max > 0)  /* there was a line */
    printf("%s", longest);

  return 0;

}


/* getline: read a line into s, return length */
void self_implemented_getline(char s[], int *len){

  int c, i;
  
  for(i = 0;(c=getchar()) != EOF && c != '\n'; ++i){
    s[i] = c;
  }
  
  s[i] = '\0';
  *len = i;

}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){

  int i = 0;
  while (from[i] != '\0'){
    to[i] = from[i];
    ++i;
  }

}
/* remove_trailing_blanks: removes any spaces or tabs at the end of a string */
void remove_trailing_blanks(char s[], int *len){

  for(int i = *len - 1; s[i] == ' ' || s[i] == '\t'; i--){
    s[i] = '\0';
    *len = *len - 1;
  }
  
  if(*len == 0){
    *len = 1;
  }
}
