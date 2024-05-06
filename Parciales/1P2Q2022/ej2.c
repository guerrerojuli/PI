#define N 6
#define CANT_DIR 8
#define CHECK_RANGO(x, y, ancho, alto)                                         \
  ((x) >= 0 && (x) < (ancho) && (y) >= 0 && (y) < (alto))

int palEnMat(char m[][N], int fila, int columna, char s[]) {
  int dir[][CANT_DIR] = {{1, 1, 0, -1 - 1, -1, 0, 1},
                         {0, -1, -1, -1, 0, 1, 1, 1}};
  char encontrado = 0;
  for (int i = 0; i < CANT_DIR || !encontrado; i++) {
    int dirX = dir[0][i];
    int dirY = dir[1][i];
    int j;
    for (j = 0; CHECK_RANGO(fila + dirY * j, columna + dirX * j, N, N) &&
                s[j] == m[fila + dirY * j][columna + dirX * j];
         j++)
      ;
    if (s[j] == '\0')
      encontrado = 1;
  }
  return encontrado;
}
