#include <stdio.h>
#define isdigit(c) ('0' <= (c) && (c) <= '9')

int main(void) {
  int letra;
  letra = getchar();
  if (isdigit(letra))
    printf("Es un dígito\n");
  return 0;
}
