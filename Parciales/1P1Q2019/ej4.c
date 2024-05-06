#include <stdio.h>

void formatString(char s[]) {
  for (int i = 1, j = 1; s[i] != '\0'; i++) {
    if (s[i-1] != '#' || (s[i] != ')' && s[i] != '('))
      s[j++] = s[i];
    if (s[i-1] == '#' && s[i] == '(')
      s[j-1] = '[';
    else if (s[i-1] == '#' && s[i] == ')')
      s[j-1] = ']';
  }
}

void imprimirTexto(char *text) {
  for (int i = 0; text[i] != '\0'; i++)
    putchar(text[i]);
  putchar('\n');
  return;
}

int main(void) {
  char t1[] = "123 #[ abc ##( (#( #) #]"; //
  formatString(t1);
  imprimirTexto(t1);

  char t2[] = "123 abc # ( # )";
  formatString(t2);
  imprimirTexto(t2);

  return 0;
}
