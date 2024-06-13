#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uInt;

/* Recibe un string con el formato dd/mm/yyyy y retorna por parámetro el día,
 *mes
 ** y año de la misma. En caso de que el formato sea inválido
 ** o la fecha incorrecta, retorna FALSE y no altera los parámetros
 */

int esBisiesto(uInt anio) {
  return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}

int esDiaValido(uInt dia, uInt mes, uInt anio) {
  static int diasMes[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                              {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
  return (0 < dia && dia <= diasMes[esBisiesto(anio)][mes - 1]);
}

int esMesValido(uInt mes) { return (0 < mes && mes <= 12); }

int esAnioValido(uInt anio) { return (0 < anio); }

int esFormatoValido(const char *fecha) {
  char formatoOK = (strlen(fecha) == 10);
  for (int i = 0; fecha[i] && formatoOK; i++)
    formatoOK = (i == 2 || i == 5) ? (fecha[i] == '/') : isdigit(fecha[i]);
  return formatoOK;
}

void extraerFecha(const char *fecha, uInt *dia, uInt *mes, uInt *anio) {
  *dia = atoi(fecha);
  *mes = atoi(fecha + 3);
  *anio = atoi(fecha + 6);
}

int valorFecha(const char *fecha, uInt *dia, uInt *mes, uInt *anio) {
  if (!esFormatoValido(fecha))
    return 0;
  uInt diaAux, mesAux, anioAux;
  extraerFecha(fecha, &diaAux, &mesAux, &anioAux);
  if (!esDiaValido(diaAux, mesAux, anioAux) || !esMesValido(mesAux) || !esAnioValido(anioAux))
    return 0;
  *dia = diaAux;
  *mes = mesAux;
  *anio = anioAux;
  return 1;

}
  

int main(void) {
  unsigned int d = 100, m = 200, a = 300;
  int res;
  res = valorFecha("", &d, &m, &a);
  assert(res == 0);
  assert(d == 100);
  assert(m == 200);
  assert(a == 300);

  res = valorFecha("29/02/1999", &d, &m, &a);
  assert(res == 0);
  assert(d == 100);
  assert(m == 200);
  assert(a == 300);

  res = valorFecha("30/14/2020", &d, &m, &a);
  assert(res == 0);
  assert(d == 100);
  assert(m == 200);
  assert(a == 300);

  res = valorFecha("12/12/", &d, &m, &a);
  assert(res == 0);
  assert(d == 100);
  assert(m == 200);
  assert(a == 300);

  res = valorFecha("1/1/2000", &d, &m, &a);
  assert(res == 0);
  assert(d == 100);
  assert(m == 200);
  assert(a == 300);

  res = valorFecha("12/01/2000", &d, &m, &a);
  assert(res == 1);
  assert(d == 12);
  assert(m == 1);
  assert(a == 2000);

  res = valorFecha("29/02/1900", &d, &m, &a);
  assert(res == 0);
  assert(d == 12);
  assert(m == 1);
  assert(a == 2000);

  res = valorFecha("29/02/2000", &d, &m, &a);
  assert(res == 1);
  assert(d == 29);
  assert(m == 2);
  assert(a == 2000);

  printf("OK");
  return 0;
}
