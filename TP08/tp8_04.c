#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LONG_BARAJA 52
#define LONG_MANO 5
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
typedef enum { PICA = 0, CORAZON, TREBOL, ROMBO, N_PALOS } palo;

typedef struct {
  int valor;
  palo palo;
} naipe;

naipe *generarBaraja() {
  naipe *baraja = malloc(LONG_BARAJA * sizeof(*baraja));
  for (int i = 0; i < LONG_BARAJA; i++) {
    baraja[i].valor = (i % (LONG_BARAJA / N_PALOS)) + 1;
    baraja[i].palo = (i + 1) / (LONG_BARAJA / N_PALOS);
  }
  return baraja;
}

naipe tomarNaipe(naipe *baraja, int *longBaraja) {
  int r = rand() % *longBaraja;
  naipe retorno = baraja[r];
  baraja[r] = baraja[--(*longBaraja)];
  return retorno;
}

naipe *generarMano(naipe *baraja, int *longBaraja) {
  naipe *mano = malloc(LONG_MANO * sizeof(*mano));
  for (int i = 0; i < LONG_MANO; i++)
    mano[i] = tomarNaipe(baraja, longBaraja);
  return mano;
}

int maxRepetidos(naipe *mano) {
  char repeticiones[LONG_BARAJA / N_PALOS] = {0};
  int maxRep = 0;
  for (int i = 0; i < LONG_MANO; i++)
    repeticiones[mano[i].valor - 1]++;
  for (int i = 0; i < (LONG_BARAJA / N_PALOS); i++)
    maxRep = MAX(maxRep, repeticiones[i]);
  return maxRep;
}

void imprimirMano(naipe *mano) {
  for (int i = 0; i < LONG_MANO; i++)
    printf("Carta %d: %d\n", i + 1, mano[i].valor);
}

int main(void) {
  srand(time(NULL));
  int longBaraja = LONG_BARAJA;
  naipe *baraja = generarBaraja();
  naipe *mano = generarMano(baraja, &longBaraja);
  imprimirMano(mano);
  int maxRep = maxRepetidos(mano);
  switch (maxRep) {
  case 2:
    puts("PAR");
    break;
  case 3:
    puts("PIERNA");
    break;
  case 4:
    puts("POKER");
    break;
  default:
    puts("NADA");
  }
  free(baraja);
  free(mano);
  return 0;
}
