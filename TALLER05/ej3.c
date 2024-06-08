#include <assert.h>
#include <stdio.h>

#define FILAS 7
#define COLS 6

#define ERROR (-1)

typedef enum { E = 0, NE, N, NO, O, SO, S, SE } angulos;

int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y);

int main(void) {
  char tablero[][COLS] = {
      {'0', '0', '0', '0', '1', '0'}, {'X', 'X', '0', '0', '0', '0'},
      {'0', '0', '0', '0', 'X', 'X'}, {'0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0'}, {'0', '0', '0', 'X', '0', '0'},
      {'1', '0', '0', 'X', 'X', 'X'}};
  int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
  assert(res == 0 || res == 45);

  assert(calculaDireccion(tablero, FILAS, COLS, 0, 0) == 0);
  assert(calculaDireccion(tablero, FILAS, COLS, 6, 2) == 90);
  assert(calculaDireccion(tablero, FILAS, COLS, 5, 4) == 135);
  assert(calculaDireccion(tablero, FILAS, COLS, 3, 5) == 180);
  assert(calculaDireccion(tablero, FILAS, COLS, 0, 5) == 225);

  res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
  assert(res == 0 || res == 45 || res == 90 || res == 270);

  // Jugador fuera del tablero
  assert(calculaDireccion(tablero, FILAS, COLS, FILAS, COLS) == ERROR);

  printf("OK!\n");
  return 0;
}

int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y) {
  int angulo = -1;
  int dirs[][8] = {{0, -1, -1, -1, 0, 1, 1, 1}, {1, 1, 0, -1, -1, -1, 0, 1}};
  for (int i = 1; angulo == -1; i++) {
    for (int j = E; j <= SE && angulo == -1; j++) {
      int dirX = x + i * dirs[0][j], dirY = y + i * dirs[1][j];
      if (dirX > alto || dirX < 0 || dirY > ancho || dirY < 0 ||
          mat[dirX][dirY] == 'X' || mat[dirX][dirY] == '1')
        angulo = j;
    }
  }
  return angulo * 45;
}
