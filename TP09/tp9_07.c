#include <stdio.h>
#include <assert.h>

int busquedaBinaria(const int v[], int dim, int num) {
  if (!dim || num > v[dim - 1] || num < v[0])
    return 0;
  int i = dim / 2;
  if (num < v[i])
    return busquedaBinaria(v, i, num);
  if (v[i] < num)
    return busquedaBinaria(v + i + 1, dim - i - 1, num);
  return 1;
}

int main(void) {

  int v[] = {-10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45};

  assert(busquedaBinaria(v, 0, -10)==0);
  assert(busquedaBinaria(v, 1, -10)==1);
  assert(busquedaBinaria(v, 2, -10)==1);
  assert(busquedaBinaria(v, 2, -5)==1);
  assert(busquedaBinaria(v, 2, 0)==0);

  assert(busquedaBinaria(v+1, 2, -10)==0);
  assert(busquedaBinaria(v+1, 2, -5)==1);
  assert(busquedaBinaria(v+1, 2, 0)==1);
  
  for(int i=0; i < 12; i++)
    assert(busquedaBinaria(v, 12, v[i])==1);
    
  for(int i=0; i < 11; i++)
    assert(busquedaBinaria(v, 11, v[i])==1);


  printf ("OK!\n");
  return 0;
}
