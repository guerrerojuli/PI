#include <stdio.h>

int main(void) {
  char c;
  while ((c = getchar()) != EOF)
    putchar(c);

  return 0;
}

/*
 * El problema con este programa reside en el tipo de dato utilizado para la
 * variable c. En C, la función getchar() devuelve un int, no un char. Esto es
 * así porque getchar() necesita poder devolver todos los posibles caracteres
 * más un valor adicional, EOF (End Of File), para indicar el fin de la entrada.
 * EOF es típicamente definido como -1, y un char no puede representar todos los
 * valores de unsigned char más el EOF si char es firmado, lo cual es común en
 * muchos entornos. Si char es sin signo, no puede representar un valor negativo
 * como EOF. 
 * El programa puede funcionar "correctamente" en algunas computadoras
 * donde el valor de EOF no se confunde con un valor legítimo de un char. Sin
 * embargo, en sistemas donde el tipo char es firmado por defecto (lo cual es
 * común), la conversión implícita de EOF a char puede no funcionar como se
 * espera porque el valor de EOF (típicamente -1) se interpretaría como un char
 * válido, y el ciclo nunca terminaría.
 */
