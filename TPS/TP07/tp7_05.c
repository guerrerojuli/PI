#include <assert.h>
#include <stdio.h>
#include <string.h>

// Cambiar de acuerdo al tipo elegido 
// Si usan "matriz" de chars debe quedar
// typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];   

// Si usan vector de punteros a char debe quedar
// typedef char * TAlumnos[MAX_ALUMNOS];

#define MAX_ALUMNOS 4
#define MAX_LARGO 20

typedef char * TAlumnos[MAX_ALUMNOS];
typedef char TCurso[MAX_ALUMNOS];

void separaCursos(TAlumnos alumnos, TCurso curso, TAlumnos cursoG, TAlumnos cursoH) {
  int cntG = 0, cntH = 0;
  for (int i = 0; alumnos[i][0]; i++) {
    if (curso[i] == 'G')
      cursoG[cntG++] = alumnos[i];
    else
      cursoH[cntH++] = alumnos[i];
  }
  cursoG[cntG] = "";
  cursoH[cntH] = "";
}


int main(void){
    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso={'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

    alumnos[0]=""; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}
