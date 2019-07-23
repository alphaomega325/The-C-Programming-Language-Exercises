#include <stdio.h>
/* copy input to output; 2nd version */
int main()
{
  int c;
  
  if(((getchar() != EOF) == 1) || ((getchar() !=EOF) == 0)){
  
    while ((c = getchar()) != EOF)
      putchar(c);
  }

  putchar(EOF);
  
}
