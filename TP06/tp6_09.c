#include <stdio.h>
#include <assert.h>
#include <math.h>

typedef unsigned char byte;

/* Calcula la desviacion estandar */
double desv(const unsigned char vector[], int cantnum ){
	if(!cantnum) return 0;
	byte nuevoVector[cantnum];
	double promedio = 0;
	double auxdesviacion = 0;
	
	// Calcula promedio y crea un array con los numeros "descompactados"
	for(int i = 0; i < cantnum; i++){
		byte corrimiento = (i % 2 == 0) ? 4 : 0;
		byte num = (vector[i/2] >> corrimiento) & 0x0F;
		promedio += num;
		nuevoVector[i] = num;	
	}
	promedio /= cantnum;

	// Calcula la desvacion
	for(int i = 0; i < cantnum; i++)
		auxdesviacion += pow(nuevoVector[i] - promedio, 2);

	auxdesviacion /= cantnum;
	return sqrt(auxdesviacion);
}


int main(void) {
  double d;
  unsigned char arreglo2[] = { 0x33, 0x33, 0x33, 0x33, 0x33 };
  for(int i=0; i <= 10; i++)
    assert(desv(arreglo2, i)==0);
  

  unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
  assert(desv(arreglo, 1)==0);
  assert(desv(arreglo, 2)==2.0);

  assert(desv(arreglo, 3) > 4.98 && desv(arreglo, 3) < 4.99);

  assert(desv(arreglo, 10) > 5.6071 && desv(arreglo, 3) < 5.6072);

  puts("OK!");
}
