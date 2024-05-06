#include <assert.h>
#include <stdio.h>

#define MAXCOL 10

void intercambiarFilas(int matriz[][MAXCOL], int fil1, int fil2, int col){
  int filaAux[col];
  for(int i = 0; i < col; i++){
    filaAux[i] = matriz[fil1][i];
    matriz[fil1][i] = matriz[fil2][i];
    matriz[fil2][i] = filaAux[i];
  }
}

void imprimirMatriz(int matriz[][MAXCOL], int fil, int col){
  for(int i = 0; i < fil; i++){
    for(int j = 0; j < col; j++)
      printf("%d ", matriz[i][j]);
    putchar('\n');
  }
}
/* Ordena por el método de burbujeo */
void ordenaMatriz (int matriz[][MAXCOL], int fil, int col, int colOrd){
  char intercambiado;
  for(int i = 0; i < fil-1; i++){
    intercambiado = 0;
    for(int j = 0; j < fil-i-1; j++){
      if(matriz[j][colOrd-1] > matriz[j+1][colOrd-1]){
        intercambiarFilas(matriz, j, j+1, col);
        intercambiado = 1;
      }
    }

    if(intercambiado == 0)
      break;
  } 
}

int checkVector(const int v1[], const int v2[], int dim) {
  for(int i=0; i < dim; i++)
    if ( v1[i] != v2[i])
      return 0;
  return 1;
}

int main(void) {
  int m[][MAXCOL] = { {1, 2, 3, 4, 5},
            {6, 2, 8, 9, 10},
            {3, 5, 8, 2, 1},
            {8, 7, 3, 6, 7}};

  int m2[][MAXCOL] = { {1, 2, 3, 4, 5},
            {6, 2, 8, 9, 10},
            {3, 5, 8, 2, 1},
            {8, 7, 3, 6, 7}};
  
  // La matriz no cambia 
  ordenaMatriz(m, 4, 5, 2);

  for(int i=0; i < 4; i++)
    assert(checkVector(m[i], m2[i], 5));

  ordenaMatriz(m, 4, 5, 1);
  assert(checkVector(m[0], m2[0], 5));
  assert(checkVector(m[1], m2[2], 5));
  assert(checkVector(m[2], m2[1], 5));
  assert(checkVector(m[3], m2[3], 5));
  
  ordenaMatriz(m, 4, 5, 3);
  assert(checkVector(m[0], m2[0], 5) || checkVector(m[0], m2[3], 5));
  assert(checkVector(m[1], m2[0], 5) || checkVector(m[1], m2[3], 5));
  assert(checkVector(m[2], m2[1], 5) || checkVector(m[2], m2[2], 5));
  assert(checkVector(m[3], m2[1], 5) || checkVector(m[3], m2[2], 5));

  printf("OK!\n");
  return 0;
}
