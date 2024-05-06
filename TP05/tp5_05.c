#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.00001

// ¿Qué caso faltaría agregar?

double potencia(double base, int exponente){
  int exponenteNegativo = 0; 
  long resultado = 1;

  if (exponente < 0){
    exponenteNegativo = 1;
    exponente *= -1;
  }

  if (base == 0 && exponente <=0){
    return -1;
  }
  
  for(int i = 0; i < exponente; i++)
    resultado *= base;

  return (exponenteNegativo) ? 1.0/resultado : resultado;
}

int main(void){

    assert(potencia(0,0)==-1);
    
    for(int i=-10, j=1; i<10; i++, (i%2==0? j++ : 0)){
        assert(fabs(potencia(i, j)-pow(i, j))<=EPSILON);
    }
    assert(fabs(potencia(-2, -4)-pow(-2, -4))<=EPSILON);

    puts("OK!");
    return 0;
}
