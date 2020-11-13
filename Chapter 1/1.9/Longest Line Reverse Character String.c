#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void self_implemented_getline(char line[], int *len);
void copy(char to[], char from[]);
void reverse(char s[]);

/* print the longest input line */
int main(){

  int len = 0;               /* current line length */
  char *line;    /* current input line */
  int *lenptr = &len;

  line = malloc(INT_MAX * sizeof(char));
  do{
    self_implemented_getline(line, lenptr);
    if(len > 0){
      reverse(line);
      printf("%s\n", line);
    }
  }while(len > 0);

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

void reverse(char s[]){
  int begin = 0;
  int end = 0;
  while(s[end] != '\0')
    end++;

  end--;

  char temp = 0;
  while(begin < end){
    temp = s[begin];
    s[begin] = s[end];
    s[end] = temp;
    begin++;
    end--;
  }
  
}
