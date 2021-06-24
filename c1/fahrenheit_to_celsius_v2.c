#include <stdio.h>

/*
Print celsius values for some fahrenheit temperatures
*/

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; // lower limit of temperature table
  upper = 300; // upper limit
  step = 20; // step size

  fahr = lower;

  printf("Fahrenheit to Celsius Table\n");

  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

/*
The decimals in the output string state how many decimal places should be
written. E.g;
%.1f -> 3.0
%.2f -> 3.00

Some interpolation characters;
%o for octal
%x for hex
%c for character
%% for '%' itself
*/
