#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOLILLAS 90
#define LONG_LINEA 5
#define LINEAS 3

typedef int TipoLinea[LONG_LINEA];
typedef TipoLinea TipoCarton[LINEAS];

void generarCarton(TipoCarton carton);
int sacarBolilla(int bolillero[], int *cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
void imprimirCarton(TipoCarton carton);
int buscarBolilla(TipoCarton carton, int bolilla);
int controlarLineas(TipoLinea linea);
int jugar(int bolillero[], TipoCarton carton1, TipoCarton jugador2);

int main(void) {
  TipoCarton carton1, carton2;
  int bolillero[BOLILLAS];
  srand(time(NULL));

  for (int i = 0; i < BOLILLAS; i++)
    bolillero[i] = i + 1;

  generarCarton(carton1);
  generarCarton(carton2);

  int bingo = jugar(bolillero, carton1, carton2);

  printf("El jugador %d hizo bingo\n", bingo);

  return 0;
}

int jugar(int bolillero[], TipoCarton carton1, TipoCarton carton2) {
  int huboLinea = 0;
  int bolilla;
  int cantBolillas = BOLILLAS;
  int lineas1, lineas2;
  int bingo = 0;

  do {
    printf("Jugador 1\n");
    imprimirCarton(carton1);
    putchar('\n');
    printf("Jugador 2\n");
    imprimirCarton(carton2);
    putchar('\n');

    bolilla = sacarBolilla(bolillero, &cantBolillas);
    printf("Bolilla extraida: %d\n", bolilla);

    lineas1 = controlarCarton(carton1, bolilla);
    lineas2 = controlarCarton(carton2, bolilla);

    if (!huboLinea) {
      if (lineas1 > 0)
        printf("El jugador 1 hizo linea\n");
      if (lineas2 > 0)
        printf("El jugador 2 hizo linea\n");
      huboLinea += lineas1 + lineas2;
    }

    bingo = (lineas1 == 3) | 2 * (lineas2 == 3);
  } while (bingo == 0);

  return bingo;
}

void generarCarton(TipoCarton carton) {
  int arregloAux[BOLILLAS];

  for (int i = 0; i < BOLILLAS; i++)
    arregloAux[i] = i + 1;

  for (int i = 0; i < LINEAS * LONG_LINEA; i++) {
    int r = rand() % (BOLILLAS - 1);
    int aux = arregloAux[r];
    arregloAux[r] = arregloAux[i];
    arregloAux[i] = aux;
  }

  for (int i = 0; i < LINEAS * LONG_LINEA; i++) {
    (*carton)[i] = arregloAux[i];
  }
}

int sacarBolilla(int bolillero[], int *cantBolillas) {
  int r = rand() % (*cantBolillas - 1);
  int bolilla = bolillero[r];
  (*cantBolillas)--;
  bolillero[r] = bolillero[*cantBolillas];

  return bolilla;
}

int controlarCarton(TipoCarton carton, int bolilla) {
  int lineasCompletas = 0;
  if (buscarBolilla(carton, bolilla))
    for (int i = 0; i < LINEAS; i++)
      lineasCompletas += controlarLineas(carton[i]);
  return lineasCompletas;
}

void imprimirCarton(TipoCarton carton) {
  for (int i = 0; i < LINEAS; i++) {
    for (int j = 0; j < LONG_LINEA; j++)
      if (carton[i][j])
        printf("%d\t", carton[i][j]);
      else
        printf("%c\t", 'X');
    printf("\n");
  }
}

int buscarBolilla(TipoCarton carton, int bolilla) {
  int esta = 0;
  for (int i = 0; i < LINEAS && !esta; i++)
    for (int j = 0; j < LONG_LINEA && !esta; j++)
      if (carton[i][j] == bolilla) {
        esta = 1;
        carton[i][j] = 0;
      }
  return esta;
}

int controlarLineas(TipoLinea linea) {
  int i, aciertos;
  for (i = 0, aciertos = 0; i < LONG_LINEA; i++)
    aciertos += (linea[i] == 0);
  return (aciertos == LONG_LINEA);
}
