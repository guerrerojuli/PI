#include <stdio.h>
#define DIM 5

void imprimirArreglo(const int v[], int dim) {
  for (int i = 0; i < dim; i++)
    printf("%d ", v[i]);
  putchar('\n');
}

int interseccionOrdenada(const int arr1[], int dim1, const int arr2[], int dim2,
                         int interseccion[]) {
  int i = 0, j = 0;
  int dimInter = 0;
  while (i < dim1 && j < dim2) {
    if (arr1[i] == arr2[j]) {
      interseccion[dimInter++] = arr1[i++];
      j++;
    } else if (arr1[i] < arr2[j])
      i++;
    else
      j++;
  }

  return dimInter;
}

// bubble sort
void ordenar(int v[], int dim) {
  char intercambiado;
  for (int i = 0; i < dim - 1; i++) {
    intercambiado = 0;
    for (int j = 0; j < dim - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        int temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
        intercambiado = 1;
      }
    }

    // If no two elements were swapped by inner loop,
    // then break
    if (intercambiado == 0)
      break;
  }
}

int main(void) {
  int vA[DIM] = {7, 9, 3, 5, 15};
  int vB[DIM] = {5, 6, 7, 9, 8};
  int respuesta[DIM];
  ordenar(vA, DIM);
  ordenar(vB, DIM);
  imprimirArreglo(vA, DIM);
  imprimirArreglo(vB, DIM);
  int dimRespuesta = interseccionOrdenada(vA, DIM, vB, DIM, respuesta);
  imprimirArreglo(respuesta, dimRespuesta);
  return 0;
}
