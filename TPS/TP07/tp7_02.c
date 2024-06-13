#include "../getnum.h"
#include <stdio.h>
#define BORRAR_BUFFER while(getchar() != '\n')

int main(void) {
  int base1, base2;
  do {
    scanf("< %d >%d", &base1, &base2);
    BORRAR_BUFFER;
  } while (base1 < 1 || base2 < 1 || base1 > 10 || base2 > 10);

  return 0;
}
