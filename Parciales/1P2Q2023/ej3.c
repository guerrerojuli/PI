#include <ctype.h>
#define DIM 'z' - 'a' + 1
#define INDEXOF(x) ((x) - 'a')

int anagrama(char *s1, char *s2) {
  char apariciones[DIM] = {0};
  char esAnagrama = 1;
  int letras1 = 0, letras2 = 0; // contador de cantidad de letras
  for (int i = 0; s1[i] != '\0'; i++) {
    char c = s1[i];
    if (!isspace(c)) {
      apariciones[INDEXOF(c)]++;
      letras1++;
    }
  }

  for (int i = 0; s2[i] != '\0' && esAnagrama; i++) {
    char c = s2[i];
    if (!isspace(c)) {
      if (!apariciones[INDEXOF(c)])
        esAnagrama = 0;
      else {
        apariciones[INDEXOF(c)]--;
        letras2++;
      }
    }
  }

  return (esAnagrama && (letras1 == letras2));
}
