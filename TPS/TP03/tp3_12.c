#include <stdio.h>

int main(void){
  for(int i = 0; i <= 4; i++)
    printf("%d%c", 3 + 5*i, (i == 4) ? '\n' : ',');

  for(int i = 0; i <= 5; i++)
    printf("%d%c", 20 - 6*i, (i == 5) ? '\n' : ',');

  for(int i = 0; i <= 4; i++)
    printf("%d%c", 19 + 8*i, (i == 4) ? '\n' : ',');

  return 0;
}
