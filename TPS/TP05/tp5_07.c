#include <stdio.h>
#include <math.h>

#define EPSILON 0.0000001

double ex(double x){
  long factorial = 1;
  double num = 0, anterior = 0;
  for(int exponente = 0; fabs(num - anterior) > EPSILON || exponente == 0; exponente++){
    if (exponente != 0)
      factorial *= exponente;
    anterior = num;
    num += (double) pow(x, exponente) / factorial;
  }

  return num;
}

int main(void){
  printf("%15g, %10g\n", ex(2), exp(2));
  return 0;
}
