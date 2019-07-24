#include <stdio.h>

int main(){
  int array_size = 100;
  int c;
  int word_size[array_size];
  int current_word_size = 0;

  int upper_limit;
  int lower_limit;
  
  for(int i = 0; i < array_size; ++i){

    word_size[i] = 0;

  }

  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t')
      {
	++word_size[current_word_size];
	current_word_size = 0;
	while((c == ' ' || c == '\t') && c != EOF){

	  c = getchar();

	}
	current_word_size++;
	
      }
    
    
  }

  for(int i = 1; i < array_size; ++i)
    {
      if(word_size[i] < lower_limit && word_size[i] > 0)
	{
	  lower_limit = word_size[i];
	}
      else if(word_size[i] > upper_limit){
	upper_limit = word_size[i];
      }

    }

  return 0;
}
