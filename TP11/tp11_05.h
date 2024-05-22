typedef struct complejoCDT * complejoADT;

complejoADT nuevoComp(double real, double imag);
double parteRealComp(complejoADT);
double parteImagComp(complejoADT);
complejoADT conjugadoComp(complejoADT);
complejoADT sumaComp(complejoADT, complejoADT);
complejoADT restaComp(complejoADT, complejoADT);
complejoADT multiplicaComp(complejoADT, complejoADT);
complejoADT divideComp(complejoADT, complejoADT);
void liberaComp(complejoADT);
