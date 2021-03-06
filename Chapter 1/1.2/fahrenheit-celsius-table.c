#include <stdio.h>
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
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  printf("Fahr| Cel | \n");
  
  celsius = lower;
  
  while(celsius <= upper) {
    fahr = 1.8 * celsius + 32;
    printf("%3.0f %6.1f\n", fahr, celsius);
    celsius = celsius + step;
    
  }
}
