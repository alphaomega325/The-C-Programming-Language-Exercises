#include <stdio.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0

int main(){
  int c;
  int character_size[CHAR_MAX] = {0};
  
  int upper_limit = INT_MIN;
  int lower_limit = INT_MAX;
  int steps = 10;
  char graph_continue = TRUE;
  
  while((c = getchar()) != EOF){
    character_size[c]++;
  }

  for(int i = 1; i < CHAR_MAX; ++i)
    {
      if(i == '\t' || i == '\n' || i == ' '){
	character_size[i] = 0;
      }
      if(character_size[i] < lower_limit && character_size[i] > 0)
	{
	  lower_limit = character_size[i];
	}
      else if(character_size[i] > upper_limit){
	upper_limit = character_size[i];
      }

    }

  steps = upper_limit/steps;
  if(steps == 0){
    steps = 1;
  }

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
    for(int i = 1; i < CHAR_MAX; i++)
      {
	if(character_size[i] > 0 && character_size[i] >= current_position){

	  
	  printf("| ** |");
	  
	}
	else if(character_size[i] > 0){

	  printf("|    |");
	  
	}

      }

    printf("\n");
    current_position = current_position - steps;

  }while(graph_continue);

  printf("----");
  
  for(int i = 1; i < CHAR_MAX; i++){

    if(character_size[i] > 0)
      {

	printf("+----+");
	
      }
    

  }

  printf("\n    ");
  
  for(int i = 1; i < CHAR_MAX; i++){
    if(character_size[i] > 0)
      {

	printf("| %c  |", i);

      }

  }
  return 0;
}
