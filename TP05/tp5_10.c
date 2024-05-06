#include "getnum.h"
#include <stdio.h>

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

void solicitarFraccion(int *numerador, int *denominador) {
  *numerador = getint("Inserte el numerador: ");
  do
    *denominador = getint("Inserte el denominador: ");
  while (*denominador == 0);
}

void simplificarFraccion(int *numerador, int *denominador) {
  int simplificacion;
  simplificacion = mcd(*numerador, *denominador);
  *numerador = *numerador / simplificacion;
  *denominador = *denominador / simplificacion;
}

void sumarFracciones(int *numerador1, int *denominador1, int *numerador2,
                     int *denominador2) {
  *numerador1 = *numerador1 * *denominador2 + *numerador2 * *denominador1;
  *denominador1 *= *denominador2;
  simplificarFraccion(numerador1, denominador1);
}

int main(void) {
  tipoAccion accion = 0;
  while ((accion = solicitarAccion()) != TERMINAR) {
    switch (accion) {
    case SIMPLIFICAR: {
      int numerador, denominador;
      solicitarFraccion(&numerador, &denominador);
      simplificarFraccion(&numerador, &denominador);
      printf("La fraccion simplificada es %d/%d\n", numerador, denominador);
      break;
    }
    case SUMAR: {
      int numerador1, denominador1, numerador2, denominador2;
      solicitarFraccion(&numerador1, &denominador1);
      solicitarFraccion(&numerador2, &denominador2);
      sumarFracciones(&numerador1, &denominador1, &numerador2, &denominador2);
      printf("La suma es %d/%d\n", numerador1, denominador1);
      break;
    }
    default:
      printf("Ingrese un numero valido\n");
    }
  }
  return 0;
}
