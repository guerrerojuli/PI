#include <assert.h>
#include <stdio.h>

#define COLS 4

int incluido(const int v1[], const int v2[], unsigned int dim1, unsigned int dim2){
  int i, j;
  char incluido = 1;
  for (i = 0, j = 0; i < dim1 && j < dim2 && incluido;) {
      if (v1[i] == v2[j])
        i++;
      else if (v1[i] < v2[j])
        incluido = 0;
      else {
        j++;
      }
  }

  if(i != dim1) //significa que no termino de encontrar todos (recorrio antes el segundo array)
    incluido = 0;
  return incluido;
}

int esAmiga(const int m1[][COLS], unsigned int fils1, const int m2[][COLS], unsigned int fils2){
  int esAmiga = 1;
  for(int i = 0; i < fils1 && esAmiga; i++){
    char amigaEncontrada = 0;
    for(int j = 0; j < fils2 && !amigaEncontrada; j++)
      if(incluido(m1[i], m2[j], COLS, COLS))
        amigaEncontrada = 1;
    if(!amigaEncontrada)
      esAmiga = 0;
  }
  return esAmiga;
}

int sonAmigas(const int(m1[])[COLS], unsigned int fils1, const int(m2[])[COLS],
              unsigned int fils2) {
  if(esAmiga(m1, fils1, m2, fils2))
    return 1;
  else if(esAmiga(m2, fils2, m1, fils1))
    return 2;
  else
    return 0;

}

int main(void) {
  int m1[][COLS] = {{0, 1, 2, 3}, {4, 4, 5, 6}, {7, 8, 8, 9}};
  int m2[][COLS] = {{0, 1, 2, 3}, {-3, 7, 8, 9}, {-1, 3, 4, 7}, {4, 5, 6, 8}};
  int m3[][COLS] = {{2, 3, 3, 7}};
  assert(sonAmigas(m1, 3, m2, 4) == 1);
  assert(sonAmigas(m1, 1, m2, 4) == 1);
  assert(sonAmigas(m1, 2, m2, 4) == 1);
  assert(sonAmigas(m1, 2, m2, 2) == 0);
  assert(sonAmigas(m2, 4, m1, 3) == 2);
  assert(sonAmigas(m1, 3, m3, 1) == 0);
  assert(sonAmigas(m3, 1, m1, 3) == 0);
  int res = sonAmigas(m1, 3, m1, 3);
  assert(res == 1 || res == 2);

  printf("OK !\n");

  return 0;
}
