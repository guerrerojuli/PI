#include <stdio.h>
#define DIM 12
#define NUM 5

int dondeEsta(const int arr[], int dim, int num, int respuesta[]) {
  int cant = 0;
  for (int i = 0; cant == 0 || arr[i] == num; i++) {
    if (arr[i] == num)
      respuesta[cant++] = i;
  }
  return cant;
}

int main(void) {
  int v[DIM] = {3, 5, 5, 5, 5, 6, 7, 7, 8, 9, 12, 15};
  int rspIndices[DIM];
  int rspCant = dondeEsta(v, DIM, NUM, rspIndices);

  printf("Vector: ");
  for (int i = 0; i < DIM; i++)
    printf("%d ", v[i]);
  putchar('\n');
  printf("Elemento a buscar: %d\n", NUM);

  if (rspCant) {
    printf("Esta en posiciones: ");
    for (int i = 0; i < rspCant; i++)
      printf("%d ", rspIndices[i]);
    putchar('\n');
  } else {
    puts("El numero no esta");
  }
}
