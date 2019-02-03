#include <stdio.h>

/*
Program for converting some fahrenheit values into their celsius equivalent.
*/

int main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%3d\t%6d\n", fahr, celsius);
    fahr = fahr + step;
  }
}

/*
Side notes
char - character, a single byte
short - short integer
long - long integer
double - double-precision floating point

Like in many other languages, '/' division truncates integer values from decimals.
Hence, 5 * (fahr - 32) / 9; as opposed to 5/9 * (fahr - 32). As that would result
in 0 * (fahr - 32)

%d - integer

printf is not part of C itself. printf is a useful function from the standard
library.
*/
