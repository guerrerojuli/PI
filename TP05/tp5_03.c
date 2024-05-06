// #include "getnum.h"
// #include <math.h>
// #include <stdio.h>
//
// int lugar(int num, int pos);
//
// int main(void) {
//   int boleto, esCapicua = 1;
//   int j;
//
//   do {
//     boleto = getint("Ingrese un número de 5 dígitos:");
//
//     if (10000 > boleto || 99999 < boleto) {
//       puts("Ingreso incorrecto de datos");
//     }
//   } while (10000 > boleto || 99999 < boleto);
//
//   for (j = 1; j <= 2; j++)
//     if (lugar(boleto, j) != lugar(boleto, 5 - j + 1)) {
//       esCapicua = 0;
//       break;
//     }
//   printf("El boleto %ses capicúa", (esCapicua) ? "" : "no ");
//   return 0;
// }
//
// int lugar(int num, int pos) { return (num / (int)pow(10, pos - 1)) % 10; }

#include "getnum.h"
#include <math.h>
#include <stdio.h>

int lugar(int num, int pos);

int main(void) {
  int boleto, esCapicua = 1;
  int nDigitos;
  int j;

  boleto = getint("Ingrese un número:");

  // Contar digitos
  for (int copy = boleto; copy != 0; copy /= 10, nDigitos++)
    ;

  for (j = 1; j <= nDigitos / 2; j++)
    if (lugar(boleto, j) != lugar(boleto, nDigitos - j + 1)) {
      esCapicua = 0;
      break;
    }
  printf("El boleto %ses capicúa\n", (esCapicua) ? "" : "no ");
  if (esCapicua)
    return 1;
  else
    return 0;
}

int lugar(int num, int pos) { return (num / (int)pow(10, pos - 1)) % 10; }
