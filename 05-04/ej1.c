#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

double randNormalize(void) { return rand() / ((double)RAND_MAX + 1); }

int randInt(int izq, int der) {
  return (int)(randNormalize() * (der - izq + 1)) + izq;
}

double randReal(double izq, double der) {
  return randNormalize() * (der - izq) + izq;
}

void randomize(void) { srand((int)time(NULL)); }

int cantidadLetra(int n, char letra){
  int c, i, cantidad = 0;
  while((c = getchar()) != EOF && i < n){
    if(c == letra || c == tolower(letra))
      cantidad++;
    i++;
  }
  return cantidad;
}

int main(void){
  randomize();
  char randMayus = randInt('A', 'Z');
  int randNum = randInt(1, 256);
  int repeticiones = cantidadLetra(randNum, randMayus);
  printf("letra = %c, N = %d, repeticiones = %d\n", randMayus, randNum, repeticiones);
  return 0;

}
