#include <stdio.h>
#define palabra "ultima prueba"

int main(void) {
  int num1 = 53, num2 = 4;
  float num3 = 6.874;

  printf("num1= %10d\n", num1); //imprime el numero 53 ocupando 10 caracteres
  printf("num2= %010d\n", num2);  //imprime el numero 53 ocupando 10 caracteres y rellenando con 0
  printf("num1= %-10d\n", num1);  //imprime el numero 53 ocupando 10 caracteres y alineado a la izquierda
  printf("num1+num2= %5i\n", num1 + num2);  //imprime el numeor 57 ocupando 5 caracteres
  printf("num1+num2= %5f\n", num1 + num2);  //imprime cualquier cosa ya que no es float
  printf("num3= %-3.2f\n", num3); //imprime el numero 6.874 pero unicamente con 2 numeros detras de la coma
  printf("num1= %-4d\nnum2= %-4d\nnum3= %3.1f\n", num1, num2, num3);  //imprime el numero 53 y 4 ocupando 4 caracteres e identando a la izquierda, imprime el valor 6.874 pero redondeado a 1 decimal
  printf("num3(como entero)= %d\n", num3);  //imprime cualquier cosa ya que no es entero
  printf("num1 / num2 = %d\n", num1 / num2); //imrprime la parte entera de la división
  printf("num2 / num1 = %d\n", num2 / num1);  //imprime la parte entera de la división
  printf("esta es la %s\n", palabra); //imrpime el string

  return 0;
}
