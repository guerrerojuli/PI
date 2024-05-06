#include <ctype.h>
#include <stdio.h>

int esVocal(char c) {
  c = toupper(c);
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int esSuelta(char *text, int i) {
  return (
      (!i || esVocal(text[i - 1]) || !isalpha(text[i - 1])) &&
      (text[i + 1] == '\0' || esVocal(text[i + 1]) || !isalpha(text[i + 1])));
}

void formatString(char *text) {
  int i, j;
  for (i = 0, j = 0; text[i] != '\0'; i++) {
    if (!esVocal(text[i]) || esSuelta(text, i))
      text[j++] = text[i];
  }
  text[j] = '\0';
  return;
}

void imprimirTexto(char *text) {
  for (int i = 0; text[i] != '\0'; i++)
    putchar(text[i]);
  putchar('\n');
  return;
}

int main(void) {
  char t1[] = "hola mundo"; //hl mnd
  formatString(t1);
  imprimirTexto(t1);

  char t2[] = "aholoaaa";
  formatString(t2);
  imprimirTexto(t2);

  char t3[] = "pa pe pi po pu";
  formatString(t3);
  imprimirTexto(t3);

  char t4[] = "a,e,i,o,u";
  formatString(t4);
  imprimirTexto(t4);

  return 0;
}
