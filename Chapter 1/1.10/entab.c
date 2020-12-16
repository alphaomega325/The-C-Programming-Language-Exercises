#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000   /* maximum input line size */
#define TAB_SIZE 6     /* size of the tab */

void entab(int len, char string[]);

/* prints and detab input line */
int main()
{

  int len = 0;
  char *line;

  size_t maxsize = (size_t)MAXLINE;
  
  do{
    line = NULL;
    len = getline(&line, &maxsize, stdin);
    printf("%s", line);
    entab(len, line);
    printf("%s", line);
    free(line);
  }while(len > 1);
  
  return 0;

}

void entab(int len, char s[]){
  int space_length = 0;
  for(int i = 0; i < len; i++){
    if(space_length == TAB_SIZE){
      s[i - TAB_SIZE] = '\t';
      len -= TAB_SIZE;
      space_length = 0;
      int j = i - (TAB_SIZE - 1);
      while(j < len){
	s[j] = s[j + (TAB_SIZE - 1)];
	j++;
      }
      s[j] = '\n';
      s[j + 1] = '\0';
      i -= TAB_SIZE;
    }
    if(s[i] == ' '){
      space_length++;
    }
    else{
      space_length = 0;
    }


  }


}
