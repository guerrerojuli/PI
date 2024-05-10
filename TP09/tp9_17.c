#include <assert.h>
#include <ctype.h>
#include <stdio.h>

/*
int bienformado(const char *s) {
  if (!*s)
    return 0;
  int count;
  for (count = 0; isalpha(s[count]); count++);
  if (!isdigit(s[count]))
    return 1;
  return (count != s[count] - '0') || bienformado(s + count + 1);
}
*/

/*
 * Validaciones:
 * no hay letras de más (o encendí mi "flag") ||
 * que sea del tipo de caracter correspoondiente ||
 * cuando se resta un numero es porque ya se "neutralizo" el anterior
 */
int bienformado(const char *s) {
  if (!*s)
    return 0;
  if (!isdigit(*s) && !isalpha(*s))
    return 1;
  int anterior = bienformado(s + 1);
  if (anterior > 0 || (isdigit(*s) && anterior))
    return 1; // uso los positivos como flag
  return anterior + (isdigit(*s) ? -(*s - '0') : 1);
}

int main(void) {
  char *zero[] = {"abcd4a10bb2", "", "0000", "a1", "abc3", "0a1"};

  char *not_zero[] = {"a",    "1",   "a2", "abc2", "abc4",   "abc33",
                      "0123", "2aa", "$1", "@@2",  "abcd22", "@@"};

  for (int i = 0; i < sizeof(zero) / sizeof(zero[0]); i++) {
    printf("%s\n", zero[i]);
    assert(bienformado(zero[i]) == 0);
  }

  for (int i = 0; i < sizeof(not_zero) / sizeof(not_zero[0]); i++) {
    printf("%s\n", not_zero[i]);
    assert(bienformado(not_zero[i]) != 0);
  }

  puts("OK!");
  return 0;
}
