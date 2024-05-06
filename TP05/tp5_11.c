#include <stdio.h>
#include <ctype.h>

int esVocal(char c){
  if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' ||
      c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
    return 1;
  return 0;

}

int main(void) {
  int a, b, c;
  a = getchar();
  b = getchar();
  c = getchar();

  if (!esVocal(a) && isupper(a))
    printf("El caracter %c es una consonante mayúscula \n", a);
  else if (!esVocal(a) && islower(a)) 
    printf("El caracter %c es una consonante minúscula \n", a);
  else if (esVocal(a))
    printf("El caracter %c es una vocal \n", a);
  else
    printf("El caracter %c no es una letra \n", a);

  if (b%2 == 0)
    printf("El valor ASCII de %c es par \n", b);

  if (isdigit(b) && (b-'0')%2 == 0)
    printf("El caracter %c representa un dígito par \n", b);

  if (esVocal(c) || isupper(c))
    printf("El caracter %c es una vocal o es mayúscula \n", c);

  if (!esVocal(c) && isalpha(c))
    printf("El caracter %c no es una vocal pero es letra \n", c);
  return 0;
}
