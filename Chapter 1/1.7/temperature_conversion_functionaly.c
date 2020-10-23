#include <stdio.h>

/*
Now improved for the use of functions
 */

float fahr_to_cel(float fahr);
float cel_to_fahr(float cel);

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */
int main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  /* lower limit of temperature scale */
  /* upper limit */
  /* step size */
  fahr = lower;

  printf("Fahr| Cel | \n");

  
  while (fahr <= upper) {
    celsius = fahr_to_cel(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  printf("Fahr| Cel | \n");
  
  celsius = lower;
  
  while(celsius <= upper) {
    fahr = cel_to_fahr(celsius);
    printf("%3.0f %6.1f\n", fahr, celsius);
    celsius = celsius + step;
    
  }
}

/* converts fahrenheit to celsius */
float fahr_to_cel(float fahr){

  return (5.0/9.0) * (fahr-32.0);

}

/* converts celsius to fahrenheit */
float cel_to_fahr(float cel){
  return 1.8 * cel + 32;

}
