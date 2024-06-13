// Lista genérica ordenada sin repetidos
typedef struct listCDT * listADT;

// Se eligió lista de enteros
typedef int elemType;

listADT newList(int (*cmp) (elemType, elemType));

int add(listADT l, elemType elem);

int removeElem(listADT l, elemType elem);

int belongs(const listADT l, elemType elem);

elemType getElementAtIndex(const listADT l, int idx);

int size(const listADT l);

int isEmpty(const listADT l);

elemType * toArray(const listADT l);

void freeList(listADT l);

void map(listADT l, elemType(*func) (elemType));
