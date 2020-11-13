#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000   /* maximum input line size */
#define TAB_SIZE 5     /* size of the tab */

void detab(int len, char string[]);

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
    detab(len, line);
    printf("%s", line);
    free(line);
  }while(len > 0);
  
  return 0;

}

/* detab: replaces tabs in a string with spaces */
void detab(int len, char s[]){
  int i = 0;
  int tab_num = 0;
  while(s[i] != '\0'){
    if(s[i] == '\t')
      tab_num++;
    i++;
  }

  s = (char*)realloc(s, (len + (TAB_SIZE * tab_num)) * sizeof(char));
  
  for(i = 0; s[i] != '\0'; i++){

    if(s[i] == '\t'){

      for(int j = len; j > i; j--){
	s[j + TAB_SIZE] = s[j];
      }

      for(int j = i; j <= TAB_SIZE + i; j++){
	s[j] = ' ';
      }

      len = len + TAB_SIZE;
      
    }

  }


}
