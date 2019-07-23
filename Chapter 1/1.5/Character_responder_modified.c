#include <stdio.h>

/* responds characters to the user replacing backspacs with \b, tabs with \t, and backslashes with \\ */

int main(){

  int c;

  while((c = getchar()) != EOF)
    {
      if(c == '\b'){

	putchar('\\');
	putchar('b');
      }

      if(c == '\t'){
	putchar('\\');
	putchar('t');
      }

      if(c == '\\'){

	putchar('\\');
	putchar('\\');

      }
      else{
	putchar(c);
      }
    }
  
  
  return 0;
}

	   
