#include <assert.h>
#include <stdio.h>

#define DIM 9

int sudokuSolver(char sudoku[9][9]) {
  char fila[9][9] = {0}, columna[9][9] = {0}, subcuadro[9][9] = {0};

  for (int i = 0; i < 9; i++) {   // Recorre filas
    for (int j = 0; j < 9; j++) { // Recorre columnas
      // Verifica que el valor esté en el rango 1-9
      if (sudoku[i][j] < 1 || sudoku[i][j] > 9)
        return 0;

      // Índice del número en la casilla actual (restamos 1 porque los índices
      // van de 0 a 8)
      int num = sudoku[i][j] - 1;

      // Índice para el subcuadro actual
      int k = (i / 3) * 3 + (j / 3);

      // Verifica si el número ya ha sido marcado en la fila, columna o
      // subcuadro
      if (fila[i][num] || columna[j][num] || subcuadro[k][num])
        return 0;

      // Marca el número como visto en la fila, columna y subcuadro
      fila[i][num] = columna[j][num] = subcuadro[k][num] = 1;
    }
  }

  return 1; // Si todas las comprobaciones son correctas, el sudoku es válido
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

  puts("OK!! ");

  return 0;
}
