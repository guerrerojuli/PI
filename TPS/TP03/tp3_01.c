#include <stdio.h>

int main(void) {
  int c = getchar();
  if ('a'<c && c<'z') puts("Es minuscula");
  else if ('A'<c && c<'Z') puts("Es mayuscula");
  else puts("No es letra");
  return 0;
}
