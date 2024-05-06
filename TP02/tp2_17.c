#include <stdio.h>

int main(void) {
  //printf("3" + "4"); error suma de punteros, unicamente es valida la resta
  printf("%c\n",'3' + '4'); //'g'
  printf("%d\n", 3 + 4);  //7
  printf("%c\n", '3' + 4);  //'7'
  printf("%c\n", 3 + '4');  //'7'
  printf("%s\n", "3" + '4');  //mugre de la memoria (aumento de puntero)
  printf("%s\n", "3" + 4);  //mugre de la memoria (aumento de puntero)
  return 0;
}
