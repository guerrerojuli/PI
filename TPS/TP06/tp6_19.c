#include <assert.h>
#include <stdio.h>

#define COLS 4

int incluido(const int v1[], const int v2[], unsigned int dim1,
             unsigned int dim2) {
  char incluido = 1;
  for (int i = 0; i < dim1 && incluido; i++) {
    if (!(i != 0 && v1[i] == v1[i - 1])) {
      char encontrado = 0;
      for (int j = 0; j < dim2 && !encontrado; j++) {
        if (v1[i] == v2[j])
          encontrado = 1;
      }
      if(!encontrado)
        incluido = 0;
    }
  }
  return incluido;
}

int esAmiga(const int m1[][COLS], unsigned int fils1, const int m2[][COLS],
            unsigned int fils2) {
  int esAmiga = 1;
  for (int i = 0; i < fils1 && esAmiga; i++) {
    char amigaEncontrada = 0;
    for (int j = 0; j < fils2 && !amigaEncontrada; j++)
      if (incluido(m1[i], m2[j], COLS, COLS))
        amigaEncontrada = 1;
    if (!amigaEncontrada)
      esAmiga = 0;
  }
  return esAmiga;
}

int sonAmigas(const int(m1[])[COLS], unsigned int fils1, const int(m2[])[COLS],
              unsigned int fils2) {
  if (esAmiga(m1, fils1, m2, fils2))
    return 1;
  else if (esAmiga(m2, fils2, m1, fils1))
    return 2;
  else
    return 0;
}
int main(void) {
  int m1[][COLS] = {{0, 1, 3, 2}, {4, 6, 5, 6}, {9, 8, 7, 9}};
  int m2[][COLS] = {{0, 1, 2, 3}, {-3, 9, 8, 7}, {-1, 3, 4, 7}, {4, 5, 6, 8}};
  int m3[][COLS] = {{2, 3, 3, 7}};
  assert(sonAmigas(m1, 3, m2, 4) == 1);
  assert(sonAmigas(m2, 4, m1, 3) == 2);
  assert(sonAmigas(m1, 3, m3, 1) == 0);
  assert(sonAmigas(m3, 1, m1, 3) == 0);
  int res = sonAmigas(m1, 3, m1, 3);
  assert(res == 1 || res == 2);

  printf("OK !\n");

  return 0;
}
