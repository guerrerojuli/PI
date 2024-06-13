#include <assert.h>
#include <stdio.h>

#define MAX 10
#define N_DIRECS 4
#define VALID_POSITION(fil, col, dim)                                          \
  (0 <= (fil) && 0 <= (col) && (fil) < (dim) && (col) < (dim))

typedef struct direc {
  int x;
  int y;
} tDirec;

void reemplazoDiagonal(int matriz[][MAX], int dim, int fil, int col, tDirec direc) {
  fil += direc.y, col += direc.x;
  if (!VALID_POSITION(fil, col, dim))
    return;
  matriz[fil][col] = !matriz[fil][col];
  reemplazoDiagonal(matriz, dim, fil, col, direc);
}

void reemplazo(int matriz[][MAX], int dim, int fil, int col) {
  tDirec direc[] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  matriz[fil][col] = !matriz[fil][col];
  for (int i = 0; i < N_DIRECS; i++)
    reemplazoDiagonal(matriz, dim, fil, col, direc[i]);
  return;
}

int main(void) {

  int m[5][MAX] = {{1, 0, 1, 0, 1},
                   {0, 1, 1, 1, 1},
                   {1, 0, 0, 1, 0},
                   {1, 1, 1, 0, 1},
                   {0, 0, 0, 0, 0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = {{1, 1, 1, 1, 1},
                    {0, 1, 0, 1, 1},
                    {1, 1, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0}};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      assert(m[i][j] == m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      assert(m[i][j] == m2[i][j]);

  printf("OK!\n");
  return 0;
}
