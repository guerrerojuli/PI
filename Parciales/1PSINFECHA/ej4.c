#include <assert.h>
#define DIM 4

typedef enum { black = 0, white, blue, red, purple, orange } colors;

int checkBoard(colors m[][DIM]) {
  colors colorPar = m[0][0], colorImpar = m[0][1];
  char esValido = (colorPar != colorImpar);
  for (int i = 0; i < DIM && esValido; i++)
    for (int j = 0; j < DIM && esValido; j++)
      if ((i + j) % 2)
        esValido = (m[i][j] == colorImpar);
      else
        esValido = (m[i][j] == colorPar);
  return esValido;
}

int main(void) {
  unsigned char t[DIM][DIM] = {{black, white, black, white},
                               {white, black, white, black},
                               {black, white, black, white},
                               {white, black, white, black}};
  // Es un tablero válido
  assert(checkBoard(t) == 1);

  unsigned char t2[DIM][DIM] = {{black, white, black, white},
                                {white, black, white, black},
                                {black, white, black, white},
                                {white, black, white, blue}};
  // No es válido pues se usaron más de dos colores
  assert(checkBoard(t2) == 0);

  unsigned char t3[DIM][DIM] = {{black, white, black, white},
                                {white, black, white, black},
                                {white, black, white, black},
                                {black, white, black, white}};
  // No es válido pues hay dos posiciones adyacentes del mismo color
  assert(checkBoard(t3) == 0);

  return 0;
}
