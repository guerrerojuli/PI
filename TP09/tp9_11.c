#include <stdio.h>
#include <assert.h>

#define MAX 10
#define VALID_POSITION(fil, col, dim) (0 <= (fil) && 0 <= (col) && (fil) < (dim) && (col) < (dim))

typedef struct direc {
  int x;
  int y;
} tDirec;

void reemplazoDiagonal (int matriz[][MAX], int dim, int fil, int col, tDirec direc) {
  if (!VALID_POSITION(fil, col, dim))
    return;
  matriz[fil][col] = !matriz[fil][col];
  reemplazoDiagonal(matriz, dim, fil + direc.y, col + direc.x, direc);
}

void reemplazo(int matriz[][MAX], int dim, int fil, int col) {
  int direc[][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
}

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}
