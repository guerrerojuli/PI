#include <assert.h>
#include <stdio.h>

int esPotenciaDe3(int n) {
  if (!n)
    return 0;
  if (n == 1)
    return 1;
  return (n % 3 == 0) && esPotenciaDe3(n / 3);
}

int main(void) {
  assert(esPotenciaDe3(0) == 0);
  assert(esPotenciaDe3(1) == 1);
  assert(esPotenciaDe3(3) == 1);
  assert(esPotenciaDe3(9) == 1);
  assert(esPotenciaDe3(27) == 1);
  assert(esPotenciaDe3(30) == 0);
  assert(esPotenciaDe3(100) == 0);
  assert(esPotenciaDe3(28) == 0);
  assert(esPotenciaDe3(5) == 0);
  assert(esPotenciaDe3(82) == 0);
  assert(esPotenciaDe3(81) == 1);
  assert(esPotenciaDe3(10) == 0);
  printf("OK!\n");
  return 0;
}
