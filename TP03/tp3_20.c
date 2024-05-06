#include <stdio.h>

int main(void){
  int factorial = 1;
  double e = 1;
  printf("%-15s%-15s\n", "N", "e");
  for(int i = 1; factorial > 0; i++){
    printf("%-15d%-1.14g\n", i, e);
    factorial *= i;
    e += 1.0/factorial;
  }
  return 0;
}

