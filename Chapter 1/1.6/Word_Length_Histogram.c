#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(){
  int array_size = 100;
  int c;
  int word_size[array_size];
  int current_word_size = 0;

  int upper_limit = 0;
  int lower_limit = 10000000;
  int steps = 10;
  char graph_continue = TRUE;
  
  for(int i = 0; i < array_size; ++i){

    word_size[i] = 0;

  }

  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t' || c == '\n')
      {
	
	++word_size[current_word_size];
	current_word_size = 0;
	while((c == ' ' || c == '\t' || c == '\n') && c != EOF){

	  c = getchar();

	}
	current_word_size++;
	
      }
    current_word_size++;
    
    
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

  steps = upper_limit/steps;

  int current_position = upper_limit;
  
  do{

    
    if(current_position <= lower_limit)
      {
	current_position = lower_limit;
	graph_continue = FALSE;
	
      }

    if(current_position >=100)
      {
	
	printf("%d ", current_position);
	
      }
    else if(current_position >=10 && current_position <100)
      {
	
	printf("%d  ", current_position);
	
      }
    else{
      
      printf("%d   ", current_position);
      
    }
    for(int i = 1; i < array_size; i++)
      {
	if(word_size[i] > 0 && word_size[i] >= current_position){

	  
	  printf("| ** |");
	  
	}
	else if(word_size[i] > 0){

	  printf("|    |");
	  
	}

      }

    printf("\n");
    current_position = current_position - steps;

  }while(graph_continue);

  printf("----");
  
  for(int i = 1; i < array_size; i++){

    if(word_size[i] > 0)
      {

	printf("+----+");
	
      }
    

  }

  printf("\n    ");
  
  for(int i = 1; i < array_size; i++){
    if(word_size[i] > 0)
      {

	if(i < 10){
	printf("| %d  |", i);
	}
	else{
	  printf("| %d |", i);
	}
      }

  }
  return 0;
}
