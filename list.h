#ifndef TEORICAS_C_LIST_H
#define TEORICAS_C_LIST_H

// Lista de ENTEROS
// ordenada ascendente
// sin repetidos
typedef struct node {
    int head;
    struct node * tail;
} tNode;

typedef tNode * tList;

tList newList(void);

// Agrega si no estaba y retorna el comienzo de la lista
// (el comienzo puede haber cambiado)
tList add(tList l, int elem);

// Borra un elemento si está y retorna el comienzo de la lista
// (el comienzo puede haber cambiado)
tList removeElem(tList l, int elem);

// Retorna 1 si el elemento está y 0 sino
int belongs(const tList l, int elem);

// Retorna el elemento en la posición idx
// Falla si idx está fuera de las dimensiones de la lista
int getElementAtIndex(const tList l, int idx);

// Retorna la cantidad de elementos de la lista
int size(const tList l);

// Retorna 1 si la lista es vacía, 0 sino
int isEmpty(const tList l);

// Crea un arreglo con todos los elementos de la lista respetando la posición
int * toArray(const tList l);

// Libera todos los recursos utilizados por la lista
void freeList(tList l);
void freeListIt(tList l);

int head(const tList l);

tList tail(const tList l);

#endif //TEORICAS_C_LIST_H
