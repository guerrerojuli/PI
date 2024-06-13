#include <stdio.h>
/* imprime la tabla Fahrenheit-Celsius para fahr = 0, 20, ..., 300 */
int main(void){
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  // 1-3
  fahr = lower;
  printf("%s\t%s\n", "Fahrenheit", "Celsius");
  while (fahr <= upper){
    celsius = 5 * (fahr-32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }

  //1-4
  celsius = lower;
  printf("%s\t%s\n", "Celsius", "Fahrenheit");
  while (celsius <= upper){
    fahr = 9 * celsius / 5 + 32;
    printf("%d\t%d\n", celsius, fahr);
    celsius = celsius + step;
  }

  //1-5
  fahr = upper;
  printf("%s\t%s\n", "Fahrenheit", "Celsius");
  while (fahr >= lower){
    celsius = 5 * (fahr-32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr - step;
  }

  //2-1
  char c;
  for (c=1; c>0; c++);
  printf("Char:\tmin:%5d\tmax:%5d\n", c, (char)(c-1));

  short sh;
  for (sh=1; sh>0; sh++);
  printf("Short:\tmin:%5d\tmax:%5d\n", sh, (short)(sh-1));

  int i;
  for (i=1; i>0; i++);
  printf("Int:\tmin:%5d\tmax:%5d\n", i, (int)(i-1));

  //2-2

  return 0;
}
