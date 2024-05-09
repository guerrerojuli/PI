#include <assert.h>
#include <stdio.h>
#include <string.h>

char *strrchrRecHelper(const char *s, char c, char *p) {
  if (!*s)
    return p;
  return strrchrRecHelper(s + 1, c, (*s == c ? (char *)s : p));
}

char *strrchrRec(const char *s, char c) { return strrchrRecHelper(s, c, NULL); }

int main(void) {
  char *s = "vamos a buscar";

  for (int i = 0; s[i]; i++) {
    assert(strrchr(s, s[i]) == strrchrRec(s, s[i]));
  }

  puts("OK!");
}
