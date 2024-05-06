#include <stdio.h>
#include <math.h>
#include "getnum.h"

int main(void){
  double a = getdouble("Coeficiente cuadratico: "), 
        b = getdouble("Coeficiente lineal: "), 
        c = getdouble("Termino independiente: "),
        x1, x2, discriminante, aux1, aux2;


  if (a == 0){
    puts("La ecuacion no es cuadratica ya que su coeficiente cuadratico es 0");
    return 1;
  }

  discriminante = b*b - 4*a*c;

  if (discriminante < 0){
    puts("La ecuacion cuadratica tiene raices imaginarias");
    return 0;
  }

  aux1 = sqrt(discriminante)/(2*a);
  aux2 = -b / (2*a);
  x1 = aux2 + aux1;
  x2 = aux2 - aux1;
  
  printf("Las soluciones son: %g y %g\n", x1, x2);
  return 0;
}
