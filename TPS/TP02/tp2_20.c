#include <stdio.h>

int main(void){
  printf("hello, world\n");
  printf("caracter especial: \c\n");  //al no ser ningun caracter especial imprime 'c', tira warning
  printf("%d\n", getchar() != EOF);
  printf("%d\n", EOF);

  return 0;
}
