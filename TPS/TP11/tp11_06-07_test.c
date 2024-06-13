#include "tp11_06-07.h"
#include <assert.h>
#include <stdio.h>

int intcmp(int n, int m) {
  return n - m;
}

int duplicate(int n) {
  return 2*n;
}

int
main(void) {
    // Ejemplo lista de palabras
    // sin repetidos, orden alfabetico
    listADT intList = newList((int (*)(int, int))intcmp);

    assert(isEmpty(intList) == 1);
    assert(size(intList) == 0);

    assert(add(intList, 3) == 1);
    assert(add(intList, 2) == 1);
    assert(add(intList, 2) == 0);
    assert(add(intList, 4) == 1);

    assert(isEmpty(intList) == 0);
    assert(size(intList) == 3);

    //assert(belongs(wordList, "hola") == 1);

    //assert(removeElem(wordList, "hola") == 1);
    //assert(removeElem(wordList, "hola") == 0);

    //assert(belongs(wordList, "hola") == 0);

    //assert(size(wordList) == 2);

    assert(intcmp(getElementAtIndex(intList, 1), 3) == 0);
    //assert(strcmp(getElementAtIndex(wordList, 10), "hello") == 0);
    
    map(intList, duplicate); 
    assert(intcmp(getElementAtIndex(intList, 1), 6) == 0);

    freeList(intList);

    puts("OK!");
    return 0;
}
