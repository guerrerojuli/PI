#include "tp11_17.h"

typedef struct fil {
  size_t coord;
  size_t count;
  struct fil *next;
} tFil;

typedef tFil *tArea;

typedef struct col {
  size_t coord;
  struct col *next;
  tArea fils;
} tCol;

typedef tCol *tPark;

struct squirrelCensusCDT {
  size_t blockSizeMetres;
  tPark park;
};


tArea searchArea(tPark park, size_t nCol, size_t nFil);


/**
 * Reserva los recursos para el conteo de ardillas en un parque agrupando las cantidades
 * por bloques (manzanas) de tamaño blockSizeMetres metros x blockSizeMetres metros
 * desde el extremo superior izquierdo del parque
 * Si blockSizeMetres es igual a 0 aborta
 */
squirrelCensusADT newSquirrelCensus(size_t blockSizeMetres) {
  if (!blockSizeMetres)
    abort();
  squirrelCensusADT newPark = malloc(sizeof(*newPark));
  newPark->blockSizeMetres = blockSizeMetres;
  newPark->park = NULL;
  return newPark;
}

/**
 * Registra una ardilla en el bloque (manzana) correspondiente al punto (yDistance, xDistance) donde
 * - yDistance es la distancia vertical en metros del extremo superior izquierdo del parque
 * - xDistance es la distancia horizontal en metros del extremo superior izquierdo del parque
 * Retorna cuántas ardillas fueron registradas en ese mismo bloque
 */
size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance) {
  size_t nCol = yDistance / squirrelAdt->blockSizeMetres, nFil = xDistance / squirrelAdt->blockSizeMetres;
  tArea area = searchArea(squirrelAdt->park, nCol, nFil);
  return area->count += 1;
}

/**
 * Retorna cuántas ardillas fueron registradas en el bloque correspondiente al punto (yDistance, xDistance)
 */
size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance) {
  size_t nCol = yDistance / squirrelAdt->blockSizeMetres, nFil = xDistance / squirrelAdt->blockSizeMetres;
  tArea area = searchArea(squirrelAdt->park, nCol, nFil);
  return area->count;
}

/**
 * Libera los recursos utilizados para el conteo de ardillas en un parque
 */
void freeSquirrelCensus(squirrelCensusADT squirrelAdt);


tCol *searchCol(tPark park, size_t nCol) {
  if (park == NULL || park->coord < nCol) {
    tCol *newCol = malloc(sizeof(*newCol));
    newCol->coord = nCol;
    newCol->fils = NULL;
    newCol->next = park; 
    return newCol;
  }
  if (park->coord == nCol)
    return park;
  return searchCol(park->next, nCol);
} 

tFil *searchFil(tFil *fils, size_t nFil) {
  if (fils == NULL || fils->coord < nFil) {
    tFil *newFil = malloc(sizeof(*newFil));
    newFil->coord = nFil;
    newFil->count = 0;
    newFil->next = fils;
    return newFil;
  }
  if (fils->coord == nFil)
    return fils;
  return searchFil(fils->next, nFil);
}

tArea searchArea(tPark park, size_t nCol, size_t nFil) {
  tCol *col = searchCol(park, nCol);
  tFil *fil = searchFil(col->fils, nFil);
  return fil;
}
