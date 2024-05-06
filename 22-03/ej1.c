#include <stdio.h>

int esPrimo(int num) {
  if (num == 0 || num == 1)
    return 0;
  for (int i = 2; i * i <= num; i++)
    if (num % i == 0)
      return 0;
  return 1;
}

void contarPrimos(int tope) {
  for (int i = 2; tope > 0; i++) {
    if (esPrimo(i)) {
      printf("%d\n", i);
      tope--;
    }
  }
  return;
}

int numerosAmigos(int a, int b) {
  int sumaA = 1, sumaB = 1;
  for (int i = 2; i*i < a && i*i < b; i++) {
    if (b % i == 0) {
      sumaB += i;
    }
    if (a % i == 0) {
      sumaA += i;
    }
  }
  if (sumaA == b && sumaB == a)
    return 1;
  else
    return 0;
}

int main(void){
  printf("%d\n", numerosAmigos(10, 12));
  return 0;
}
