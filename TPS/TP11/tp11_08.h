typedef struct setCDT * setADT;
typedef char * elemType;
typedef int (*cmpFunc)(elemType elem1, elemType elem2);

setADT newSet(int (*cmp)(elemType elem1, elemType elem2));
int addElement(setADT set, elemType elem);
int deleteElement(setADT set, elemType elem);
setADT unionSet(setADT set1, setADT set2);
setADT intersectionSet(setADT set1, setADT set2);
setADT diffSet(setADT set1, setADT set2);
int setContains(setADT set, elemType elem);
int isEmptySet(setADT set);
int sizeSet(setADT set);
void freeSet(setADT set);
