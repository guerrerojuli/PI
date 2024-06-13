#include <stdio.h>
#define VOLUMEN_ESFERA(radio) (4.0/3 * 3.1415 * (radio) * (radio) * (radio))

int main(void){
  printf("%10s | %10s\n", "RADIO", "VOLUMEN");
  for(int i = 1; i <= 10; i++)
    printf("%10d | %10g\n", i, VOLUMEN_ESFERA(i));

  return 0;
}
