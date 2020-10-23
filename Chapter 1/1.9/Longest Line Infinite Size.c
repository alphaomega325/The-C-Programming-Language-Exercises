#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int self_implemented_getline(char line[]);
void copy(char to[], char from[]);
int array_element_num(char array[]);

/* print the longest input line */
int main(){

  int len;               /* current line length */
  int max;               /* maximum length seens so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = self_implemented_getline(line)) > 0){
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0)  /* there was a line */
    printf("%s", longest);

  return 0;

}


/* getline: read a line into s, return length */
int self_implemented_getline(char s[]){

  int c, i;
  int lim = array_element_num(s);
  
  for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i){
    if(i == lim - 2){
      char temp[lim + 100];
      copy(temp, s);
      s = temp;
      lim = array_element_num(s);
    }
    s[i] = c;
  }

  if (c == '\n'){
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;


}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){

  int i = 0;
  int lim = array_element_num(from);
  if(array_element_num(to) < lim){
    char temp[lim];
    to = temp;
  }
  
  while (i < lim - 1){
    to[i] = from[i];
    ++i;
  }

}

/* array_element_num: shows how many elements are in a array */
int array_element_num(char s[]){
  return (int)(sizeof(s)/sizeof(s[0]));

}
