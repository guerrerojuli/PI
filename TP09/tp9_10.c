#include <stdio.h>
#include <assert.h>
#include <string.h>

void invierte(const char *s1, char *s2) {
  if (!*s1)
    return;
  invierte(s1 + 1, s2);
  while (*s2)
    s2++;
  *s2 = *s1;
} 

int main(void) {

  char s[20] = {0};

  invierte("1234567890", s);
  assert(strcmp(s, "0987654321")==0);

  memset(s, 0, 20);
  invierte("", s);
  assert(strcmp(s, "")==0);

  memset(s, 0, 20);
  invierte("a", s);
  assert(strcmp(s, "a")==0);

  memset(s, 0, 20);
  invierte("ab", s);
  assert(strcmp(s, "ba")==0);
  
  memset(s, 0, 20);
  invierte("abc", s);
  assert(strcmp(s, "cba")==0);

  printf ("OK!\n");
  return 0;
}
