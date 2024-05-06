#include <assert.h>
#include <stdio.h>

#define OK 1
#define CANT_MESES 12
#define ERROR !OK

int unDiaMas(int *, int *, int *);
void sumDia(int *, int *, int *, int);

static int bisiesto(int);
static int invalidoMes(int);
static int invalidoAnio(int);
static int invalidoDia(int, int, int);

int main(void) {
  int dia, mes, anio;

  dia = 9, mes = 4, anio = 2021;
  printf("Fecha actual: %d/%d/%d\n", dia, mes, anio);
  if (unDiaMas(&dia, &mes, &anio))
    printf("Fecha con un dia mas: %d/%d/%d\n", dia, mes, anio);
  else
    printf("Error en los datos\n");

  dia = 1, mes = 1, anio = 2021;
  assert(unDiaMas(&dia, &mes, &anio) == OK);
  assert(dia == 2 && mes == 1 && anio == 2021);

  dia = 31, mes = 3, anio = 2021;
  assert(unDiaMas(&dia, &mes, &anio) == OK);
  assert(dia == 1 && mes == 4 && anio == 2021);

  dia = 31, mes = 12, anio = 2020;
  assert(unDiaMas(&dia, &mes, &anio) == OK);
  assert(dia == 1 && mes == 1 && anio == 2021);

  printf("OK!\n");
  return 0;
}

static int bisiesto(int anio) {
  int esb = 0;
  if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
    esb = 1;
  return esb;
}

int daytab[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

static int invalidoDia(int dia, int mes, int esBisiesto){
  return (dia > daytab[esBisiesto][mes-1] || dia < 1);
}

static int invalidoMes(int mes){
  return (mes < 1 || mes > CANT_MESES);
}

static int invalidoAnio(int anio){
  return (anio < 1);
}

int unDiaMas(int *dia, int *mes, int *anio){
  int esBisiesto = bisiesto(*anio);
  if(!invalidoDia(*dia, *mes, esBisiesto) && !invalidoMes(*mes) && !invalidoAnio(*anio)){
    sumDia(dia, mes, anio, esBisiesto);
    return 1;
  } else 
    return 0;
  
}

void sumDia(int *dia, int *mes, int *anio, int esBisiesto){
  if (*dia < daytab[esBisiesto][*mes-1]){
    (*dia)++;
  } else if (*mes < CANT_MESES){
    (*mes)++;
    (*dia) = 1;
  } else {
    (*anio)++;
    (*mes) = 1;
    (*dia) = 1;
  }
}
