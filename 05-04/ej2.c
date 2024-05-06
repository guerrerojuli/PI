#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randNormalize(void) { return rand() / ((double)RAND_MAX + 1); }

int randInt(int izq, int der) {
  return (int)(randNormalize() * (der - izq + 1)) + izq;
}

double randReal(double izq, double der) {
  return randNormalize() * (der - izq) + izq;
}

void randomize(void) { srand((int)time(NULL)); }

void mezclar1(unsigned v[], int cant){
    for(int i = 0; i < cant; i++)
      printf("%d ", v[i]);
    putchar('\n');

    for(int i = 0; i < cant; i++){
      int random = randInt(0, cant-1);
      int aux = v[random];
      v[random] = v[i];
      v[i] = aux;
    }

    for(int i = 0; i < cant; i++)
      printf("%d ", v[i]);
    putchar('\n');
}

void mezclar2(int v[]){
    int cant = 0;
    for(int i = 0; v[i] != -1; i++)
      cant++;

    for(int i = 0; i < cant; i++)
      printf("%d ", v[i]);
    putchar('\n');

    for(int i = 0; i < cant; i++){
      int random = randInt(0, cant-1);
      int aux = v[random];
      v[random] = v[i];
      v[i] = aux;
    }

    for(int i = 0; i < cant; i++)
      printf("%d ", v[i]);
    putchar('\n');
}

int main(void){
  randomize();
  unsigned arr1[6] = {3, 5, 7, 9, 15};
  mezclar1(arr1, 6);
  int arr2[6] = {3, 5, 7, 9, 15, -1};
  mezclar2(arr2);
  return 0;
}
