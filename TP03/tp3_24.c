#include <stdio.h>

int main(void) {
  float a = 0.1;

  if (a == 0.1)
    printf("SON iguales\n");
  else
    printf("NO SON iguales: a vale %g que no es igual a 0.1\n", a);

  return 0;
}

// El programa realiza una comparacion entre 0.1 y lo que esta almacenado en la variable a, que no es exactamente 0.1 porque no es representable en IEEE entonces la comparacion simepre dara falsa
