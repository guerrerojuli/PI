#include <stdio.h>

int solicitarAccion(){
  int accion;
  do {
    printf("%s\n%s\n%s\n%s\n%s\n",
           "Seleciona la acción ingresando el numero correspondiente:",
           "1. Convertir de mayuscula a minuscula",
           "2. Convertir de minuscula a mayuscula",
           "3. Imprimir el caracter siguiente",
           "4. Imprimir la siguiente letra en forma circular");
    accion = getchar();
  } while (!('1' <= accion && accion <= '4'));
  return accion;
}

void realizarAccion(int accion, int c){
  switch (accion) {
  case 1:
    printf("%c\n", tolower(c));
    break;
  case 2:
    printf("%c\n", toUpper(c));
    break;
  case 3:
    printf("%c\n", c + 1);
    break;
  case 4:
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
      int siguiente;
      if (c == 'Z' || c == 'z')
        siguiente = c - ('z' - 'a');
      else
        siguiente = c + 1;
    } else {
      puts("El caracter no es una letra");
    }
    break;
  }
}

int main(void) {
  int c, accion;
  printf("Inserte un caracter: ");
  c = getchar();
  accion = solicitarAccion();
  realizarAccion(accion, c);
}
