#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void self_implemented_getline(char line[], int *len);
void copy(char to[], char from[]);
void add_to(char to[], char from[]);

/* print the longest input line */
int main(){

  int len = 0;               /* current line length */
  char *line;    /* current input line */
  char *longest;      /* longest line saved here */
  int *lenptr = &len;

  line = malloc(INT_MAX * sizeof(char));
  longest = malloc(INT_MAX * sizeof(char *));

  do{
    self_implemented_getline(line, lenptr);
    if (len > 40) {
      add_to(longest, line);
      
    }
  }while(len > 0);

  if (longest[0] != '\0')  /* there was a line */
    printf("%s", longest);


  return 0;

}


/* getline: read a line into s, return length */
void self_implemented_getline(char s[], int *len){

  int c, i;
  
  for(i = 0;(c=getchar()) != EOF && c != '\n'; ++i){
    s[i] = c;
  }
  if(c == '\n'){
    s[i] = '\n';
    s[++i] = '\0';
  }
  else{
    s[i] = '\0';
  }
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
void add_to(char to[], char from[]){
  int i = 0;
  while(to[i] != '\0')
    i++;

  int j = 0;
  while(from[j] != '\0'){
    to[i] = from[j];
    i++;
    j++;
  }
  
}

