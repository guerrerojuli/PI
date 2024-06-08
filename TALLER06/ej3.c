#include <stdio.h>
#include <stdlib.h>

char *cargarChars(int *dim) {
  int c, dimAux = 10;
  char *chars = malloc(dimAux * sizeof(*chars));
  *dim = 0;
  while ((c = getchar()) != EOF) {
    chars[(*dim)++] = c; 
    if (*dim == dimAux) {
      dimAux *= 2;
      chars = realloc(chars, dimAux * sizeof(*chars));
    }
  }
  return realloc(chars, *dim * sizeof(*chars));
}

int main(void) {
  int dim;
  char *arr;
  arr = cargarChars(&dim);

  for (int i = 0; i < dim; i++)
    printf("%c ", arr[i]);
  putchar('\n');
  free(arr);
  return 0;
}
