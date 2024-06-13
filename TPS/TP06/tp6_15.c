//#include <assert.h>
#include <stdio.h>
#undef assert
#undef __assert

#ifdef __FILE_NAME__
#define __ASSERT_FILE_NAME __FILE_NAME__
#else /* __FILE_NAME__ */
#define __ASSERT_FILE_NAME __FILE__
#endif /* __FILE_NAME__ */
#define assert(e)  \
    ((void) ((e) ? ((void)0) : __assert (#e, __ASSERT_FILE_NAME, __LINE__)))
#define __assert(e, file, line) \
    ((void)printf ("%s:%d: failed assertion `%s'\n", file, line, e))

#define ALTO 6
#define ANCHO 5

// algunos dan con ua diferencia de 1 :(
int mediaCasillero(unsigned char imagen[ALTO][ANCHO], int r,
                   int fila, int columna) {
  int cantidadSumados = 0;
  int promedio = 0;
  for (int i = fila - r; i <= fila + r; i++)
    if (i >= 0 && i < ALTO)
      for (int j = columna - r; j <= columna + r; j++)
        if (j >= 0 && j < ANCHO) {
          cantidadSumados++;
          promedio += imagen[i][j];
        }
  return promedio / cantidadSumados;
}

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w) {
  if (w < 3 || w % 2 == 0)
    return;

  for (int i = 0; i < ALTO; i++) {
    for (int j = 0; j < ANCHO; j++) {
      imagen[i][j] = mediaCasillero(imagen, w / 2, i, j);
    }
  }
  return;
}

int equals(unsigned int cols, unsigned char m1[][cols],
           unsigned char m2[][cols], unsigned int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (m1[i][j] != m2[i][j]) {
        printf("%d %d\n", m1[i][j], m2[i][j]);
        return 0;
      }
    }
  }
  return 1;
}

int main(void) {
  unsigned char bmp[ALTO][ANCHO] = {{10, 10, 20, 23, 24}, {10, 12, 18, 25, 23},
                                    {12, 14, 18, 26, 22}, {12, 14, 19, 20, 22},
                                    {13, 16, 19, 20, 22}, {14, 14, 19, 21, 23}};

  suavizar(bmp, 3);
  unsigned char suave[ALTO][ANCHO] = {
      {10, 13, 18, 22, 23}, {11, 13, 18, 22, 23}, {12, 14, 18, 21, 23},
      {13, 15, 18, 20, 22}, {13, 15, 18, 20, 21}, {14, 15, 18, 20, 21}};

  assert(equals(ANCHO, bmp, suave, ALTO));

  // Ahora una con w=5
  unsigned char suave5[ALTO][ANCHO] = {
      {14, 16, 17, 19, 20}, {14, 16, 17, 18, 20}, {14, 16, 17, 18, 20},
      {15, 16, 17, 18, 20}, {15, 16, 17, 18, 20}, {15, 16, 17, 18, 19}};

  suavizar(bmp, 5);
  assert(equals(ANCHO, bmp, suave5, ALTO));

  puts("OK!");
  return 0;
}
