#include <stdio.h>

int main (void){
  char c1 = getchar();
  char c2 = getchar();
  printf("%c\n", c1 > c2 ? c1 : c2);
  return 0;
}



