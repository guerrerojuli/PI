#include <stdlib.h>

int *interseccion(int *v1, int *v2, int dim1, int dim2, int *dimRes) {
  int i, j, z, dimAux = 10;
  int *resultado = malloc(dimAux * sizeof(*resultado));
  for (i = 0, j = 0, z = 0; i < dim1 && j < dim2;) {
    if (v1[i] > v2[j])
      j++;
    else if (v1[i] < v2[j])
      i++;
    else {
      if (z == dimAux) {
        dimAux *= 2;
        resultado = realloc(resultado, dimAux * sizeof(*resultado));
      }
      resultado[z++] = v1[i++];
      j++;
    }
  }
  *dimRes = z;
  return realloc(resultado, z * sizeof(*resultado));
}

int *concatenaVec(const int *v1, int dim1, const int *v2, int dim2) {
  int i, *resultado = malloc((dim1 + dim2) * sizeof(*resultado));
  for (i = 0; i < dim1; i++)
    resultado[i] = v1[i];
  for (int j = i; j < dim2; j++)
    resultado[j] = v2[j];
  return resultado;
}
