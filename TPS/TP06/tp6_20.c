#include <assert.h>
#include <stdio.h>

#define DIM 9

int checkFila(char m[][DIM], int fila) {
  char correcto = 1;
  int vectorAparicion[9] = {0};
  for (int j = 0; j < DIM && correcto; j++)
    if (vectorAparicion[m[fila][j] - 1])
      correcto = 0;
    else
      vectorAparicion[m[fila][j] - 1] = 1;
  return correcto;
}

int checkColumna(char m[][DIM], int columna) {
  char correcto = 1;
  int vectorAparicion[9] = {0};
  for (int i = 0; i < DIM && correcto; i++)
    if (vectorAparicion[m[i][columna] - 1])
      correcto = 0;
    else
      vectorAparicion[m[i][columna] - 1] = 1;
  return correcto;
}

int checkCuadrado(char m[][DIM], int fila, int columna) {
  char correcto = 1;
  int vectorAparicion[9] = {0};
  for (int i = 0; i < DIM && correcto; i++)
    if (vectorAparicion[m[fila + i % 3][columna + i / 3] - 1])
      correcto = 0;
    else
      vectorAparicion[m[fila + i % 3][columna + i / 3] - 1] = 1;
  return correcto;
}
/*
	i/3 representa la fila de cuadrados de 3x3 en la que estoy
	i % 3 representa la fila dentro del cuadrado de 3x3 en la que estoy
	analizo los siguientes puntos
	-------------------------------------
	| * |   |   |   |   |   |   |   |   |
	-------------------------------------
	|   |   |   | * |   |   |   |   |   |
	-------------------------------------
	|   |   |   |   |   |   | * |   |   |
	-------------------------------------
	|   | * |   |   |   |   |   |   |   |
	-------------------------------------
	|   |   |   |   | * |   |   |   |   |
	-------------------------------------
	|   |   |   |   |   |   |   | * |   |
	-------------------------------------
	|   |   | * |   |   |   |   |   |   |
	-------------------------------------
	|   |   |   |   |   | * |   |   |   |
	-------------------------------------
	|   |   |   |   |   |   |   |   | * |
	-------------------------------------
*/
int sudokuSolver(char m[][DIM]) {
  char correcto = 1;
  for (int i = 0; i < DIM && correcto; i++)
    if (!(checkCuadrado(m, i - i % 3, (i % 3) * 3) && checkFila(m, i) &&
          checkColumna(m, i / 3 + (i % 3) * 3)))
      correcto = 0;
  return correcto;
}

int main(void) {
  // Una matriz vacía no es solución
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku) == 0);

  char sudoku2[DIM][DIM] = {
      {3, 8, 1, 9, 7, 6, 5, 4, 2}, {2, 4, 7, 5, 3, 8, 1, 9, 6},
      {5, 6, 9, 2, 1, 4, 8, 7, 3}, {6, 7, 4, 8, 5, 2, 3, 1, 9},
      {1, 3, 5, 7, 4, 9, 6, 2, 8}, {9, 2, 8, 1, 6, 3, 7, 5, 4},
      {4, 1, 2, 6, 8, 5, 9, 3, 7}, {7, 9, 6, 3, 2, 1, 4, 8, 5},
      {8, 5, 3, 4, 9, 7, 2, 6, 1}};

  assert(sudokuSolver(sudoku2) == 1);

  char sudoku3[DIM][DIM] = {
      {2, 8, 1, 9, 7, 6, 5, 4, 2}, {3, 4, 7, 5, 3, 8, 1, 9, 6},
      {5, 6, 9, 2, 1, 4, 8, 7, 3}, {6, 7, 4, 8, 5, 2, 3, 1, 9},
      {1, 3, 5, 7, 4, 9, 6, 2, 8}, {9, 2, 8, 1, 6, 3, 7, 5, 4},
      {4, 1, 2, 6, 8, 5, 9, 3, 7}, {7, 9, 6, 3, 2, 1, 4, 8, 5},
      {8, 5, 3, 4, 9, 7, 2, 6, 1}};

  assert(sudokuSolver(sudoku3) == 0);

  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  char sudoku4[DIM][DIM] = {
      {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5},
      {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5},
      {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5},
      {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5},
      {5, 5, 5, 5, 5, 5, 5, 5, 5}};

  assert(sudokuSolver(sudoku4) == 0);

  char sudoku5[DIM][DIM] = {
      {3, 8, 1, 9, 7, 6, 5, 4, 12}, {2, 4, 7, 5, 3, 8, 1, 9, 6},
      {5, 6, 9, 2, 1, 4, 8, 7, 3},  {6, 7, 4, 8, 5, 2, 3, 1, 9},
      {1, 3, 5, 7, 4, 9, 6, 2, 8},  {9, 2, 8, 1, 6, 3, 7, 5, 4},
      {4, 1, 2, 6, 8, 5, 9, 3, 7},  {7, 9, 6, 3, 2, 1, 4, 8, 5},
      {8, 5, 3, 4, 9, 7, 2, 6, 1}};

  assert(sudokuSolver(sudoku5) == 0);

  return 0;
}
