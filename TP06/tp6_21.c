#include "getnum.h"
#include <stdio.h>

typedef struct{
  int numerador;
  int denominador;
} fraccion; 

typedef enum acciones { SIMPLIFICAR = 1, SUMAR, TERMINAR } tipoAccion;

tipoAccion solicitarAccion(void) {
  tipoAccion accion = getint("Elige una accion:\n"
                             "1. Simplificar fracción\n"
                             "2. Sumar fracciones\n"
                             "3. Terminar la ejecución\n");
  return accion;
}

int mcd(int a, int b) {
  int auxi;

  do {
    auxi = a % b;
    a = b;
    b = auxi;
  } while (auxi > 0);

  return a;
}

fraccion solicitarFraccion() {
  fraccion fraccionRta;
  fraccionRta.numerador = getint("Inserte el numerador: ");
  do
    fraccionRta.denominador = getint("Inserte el denominador distinto de 0: ");
  while (fraccionRta.denominador == 0);
  return fraccionRta;
}

fraccion simplificarFraccion(fraccion f) {
  int simplificacion = mcd(f.numerador, f.denominador);
  fraccion fraccionRta = { f.numerador / simplificacion, f.denominador /= simplificacion };
  return fraccionRta;
}

fraccion sumarFracciones(fraccion f1, fraccion f2) {
  fraccion fraccionAux = { f1.numerador * f2.denominador + f2.numerador * f1.denominador, f1.denominador * f2.denominador };
  return simplificarFraccion(fraccionAux);
}

int main(void) {
  tipoAccion accion = 0;
  while ((accion = solicitarAccion()) != TERMINAR) {
    switch (accion) {
    case SIMPLIFICAR: {
      fraccion f = solicitarFraccion();
      f = simplificarFraccion(f);
      printf("La fraccion simplificada es %d/%d\n", f.numerador, f.denominador);
      break;
    }
    case SUMAR: {
      fraccion f1 = solicitarFraccion(), f2 = solicitarFraccion();
      fraccion f = sumarFracciones(f1, f2);
      printf("La suma es %d/%d\n", f.numerador, f.denominador);
      break;
    }
    default:
      printf("Ingrese un numero valido\n");
    }
  }
  return 0;
}
