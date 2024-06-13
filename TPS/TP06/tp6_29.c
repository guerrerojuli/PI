#include <assert.h>
#include <stdio.h>
#include <string.h>

void deleteChars(char *s1, char *s2) {
  int j1 = 0, j2 = 0;
  for (int i1 = 0, i2 = 0; s1[i1] || s2[i2];) {
    if (s1[i1] != s2[i2]) {
      if (s1[i1])
        s1[j1++] = s1[i1++];
      if (s2[i2])
        s2[j2++] = s2[i2++];
    } else {
      i1++;
      i2++;
    }
  }
  s1[j1] = 0;
  s2[j2] = 0;

}

int main(void) {

  char s3[] = "abc";
  char s4[] = "axc123456789012345678901234567890";
  deleteChars(s3, s4);
  assert(strcmp(s3, "b") == 0);
  assert(strcmp(s4, "x123456789012345678901234567890") == 0);

  char s1[] = "Hola, soy un string";
  char s2[] = "Yo soy otro string";

  deleteChars(s1, s2);
  assert(strcmp(s1, "Hla, sy un string") == 0);
  assert(strcmp(s2, "Y soy tro string") == 0);

  char empty[] = "";
  deleteChars(s1, empty);
  assert(strcmp(s1, "Hla, sy un string") == 0);
  assert(strcmp(empty, "") == 0);

  strcpy(s1, "ABCDE");
  strcpy(s2, "abcde");
  deleteChars(s1, s2);
  assert(strcmp(s1, "ABCDE") == 0);
  assert(strcmp(s2, "abcde") == 0);

  deleteChars(s1, s1);
  assert(strcmp(s1, "") == 0);

  puts("OK!");
  return 0;
}
