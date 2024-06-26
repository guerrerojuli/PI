#include <stdio.h>
#include <assert.h>
#include <string.h>

int searchMatch(char c, const char * chars) {
  if (!*chars)
    return 0;
  return (c == *chars) || searchMatch(c, chars + 1);
}

// La primera aparicion de alguno de los caracteres de la cadena chars
char * strpbrkRec(const char * target, const char * chars) {
  if (!*target)
    return NULL;
  int match = searchMatch(*target, chars);
  if (match)
    return (char *) target;
  return strpbrkRec(target + 1, chars);
}

int main(void) {
  char * s = "abcde";
  char * t = "abcdeab";

  assert( strpbrk(s, "") == strpbrkRec(s, ""));
  assert( strpbrk(s, "a") == strpbrkRec(s, "a"));
  assert( strpbrk(s, "xa") == strpbrkRec(s, "xa"));
  assert( strpbrk(s, "xye") == strpbrkRec(s, "xye"));
  assert( strpbrk(s, "r") == strpbrkRec(s, "r"));
  assert( strpbrk(t, "ba") == t);
  assert( strpbrkRec(t, "ba") == t);
  return 0;
}
