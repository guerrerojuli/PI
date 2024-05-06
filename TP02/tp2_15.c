#include <stdio.h>

int main(void){
  char c = getchar();
  'a' < c && c < 'z' ? printf("Mayuscula: %c\n", c + 'A' - 'a') : printf("%c no es una letra\n", c);
  return 0;
}
