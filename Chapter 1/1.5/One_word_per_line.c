#include <stdio.h>

/* Prints the input one word per line  */

int main(){

  int c;

  while((c = getchar()) != EOF){

    if(c == ' '){

      while(c == ' ' && c != EOF){
	c = getchar();
      }
      putchar('\n');
      putchar(c);
    }

    putchar(c);
    

  }

}
