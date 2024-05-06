#include <ctype.h>
#include <stdio.h>

#define DIM ('Z' - 'A' + 1)

int main(void) {
  int c, mayus, minus, nChars;
  int cantLetras[DIM] = {0};

  while ((c = getchar()) != EOF) {
    if (isalpha(c)) {
      (c == toupper(c)) ? mayus++ : minus++;
    }
    nChars++;
    cantLetras[toupper(c) - 'A']++;
  }

  printf("Cantidad de letras: %d,\nCantidad de mayusculas: %d,\nCantidad de "
         "minusculas: %d,\nCantidad de NO letras: %d,\n",
         mayus + minus, mayus, minus, nChars - mayus - minus);
  for(int i = 0; i < DIM; i++){
    if (cantLetras[i])
      printf("La %c aparece %d veces,\n", i+'A', cantLetras[i]);
  }
}
