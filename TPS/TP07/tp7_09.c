#include <stdio.h>
#include <stdlib.h>
#include "../getnum.h"
#include <time.h>

#define BOLILLAS 90
#define LONG_LINEA 5
#define LINEAS 3

typedef int TipoLinea[LONG_LINEA];
typedef TipoLinea TipoCarton[LINEAS];

int solicitarJugadores();
void generarCarton(TipoCarton carton);
int sacarBolilla(int bolillero[], int *cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
void imprimirCarton(TipoCarton carton);
int buscarBolilla(TipoCarton carton, int bolilla);
int controlarLineas(TipoLinea linea);
int jugar(int bolillero[], TipoCarton *cartones, int nJugadores);

int main(void) {
  int bolillero[BOLILLAS];
  int nJugadores = solicitarJugadores();
  TipoCarton *cartones = malloc(nJugadores * sizeof(*cartones));
  srand(time(NULL));

  for (int i = 0; i < BOLILLAS; i++)
    bolillero[i] = i + 1;

  for (int i = 0; i < nJugadores; i++)
    generarCarton(cartones[i]);

  int bingo = jugar(bolillero, cartones, nJugadores);

  printf("El jugador %d hizo bingo\n", bingo);

  free(cartones);
  return 0;
}

int jugar(int bolillero[], TipoCarton *cartones, int nJugadores) {
  int cantBolillas = BOLILLAS;
  int *lineas = malloc(nJugadores * sizeof(*lineas));
  int bingo = 0;

  do {
    int bolilla = sacarBolilla(bolillero, &cantBolillas);
    for (int i = 0; i < nJugadores; i++) {
      printf("Jugador %d\n", i+1);
      imprimirCarton(cartones[i]);
      putchar('\n');
      if (controlarCarton(cartones[i], bolilla) == 3)
        bingo = i+1;
    }
    printf("Bolilla extraida: %d\n", bolilla);

  } while (bingo == 0);

  free(lineas);
  return bingo;
}

int solicitarJugadores() {
  int n;
  do
    n = getint("Ingrese la cantidad de jugadores: ");
  while (n < 1);
  return n;
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
