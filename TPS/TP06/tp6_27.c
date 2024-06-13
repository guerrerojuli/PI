#include <stdio.h>
#include <assert.h>
#include <string.h>

#define CHARS_DIM 256

int analize(const char * text, char * chars) {
  unsigned char apariciones[CHARS_DIM] = {0};
  int i, j;
  for (i = 0; text[i]; i++)
    apariciones[text[i]] = 1;
  for (i = 0, j = 0; i < CHARS_DIM; i++)
    if (apariciones[i])
      chars[j++] = i;
  chars[j] = 0;
  return 1;
}

int main(void) {
  char chars[CHARS_DIM];
  char chars2[CHARS_DIM];
  analize("El zorro mete la cola, pero no la pata!", chars);
  assert(strcmp(" !,Eacelmnoprtz", chars)==0);
  analize("ababababab", chars2);
  assert(strcmp("ab", chars2)==0);
  
  analize("", chars);
  assert(strcmp("", chars)==0);
  analize(".............................", chars);
  assert(strcmp(".", chars)==0);
  
  puts("OK");
  return 0;
}
