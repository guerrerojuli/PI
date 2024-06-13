#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5

int indiceVocal(char c) {
  switch (toupper(c)) {
  case 'A':
    return 0;
  case 'E':
    return 1;
  case 'I':
    return 2;
  case 'O':
    return 3;
  case 'U':
    return 4;
  default:
    return -1;
  }
}

// no funca
int elimVocales(char *s, int m[][CANT_VOCAL], unsigned int n) {
  char apariciones[CANT_VOCAL] = {0};
  for (int z = 0; z < CANT_VOCAL; z++)
    m[0][z] = -1;
  int i, j;
  for (i = 0, j = 0; s[i]; i++) {
    int vocal = indiceVocal(s[i]);
    if (vocal == -1)
      s[j++] = s[i];
    else {
      if (apariciones[vocal] == (int) n - 1)
        return ERROR;
      m[apariciones[vocal]++][vocal] = i;
    }
  }
  for (int z = 0; z < CANT_VOCAL; z++)
    m[apariciones[z]][z] = -1;
  s[j] = 0;
  return EXITO;
}

int main(void) {
  int m[6][CANT_VOCAL];
  char s[] = "las buenas ideas escasean, si";

  assert(elimVocales(s, m, 6) == EXITO);
  assert(strcmp(s, "ls bns ds scsn, s") == 0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == 23);
  assert(m[5][0] == -1);

  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  strcpy(s, "las buenas ideas escasean, si");
  assert(elimVocales(s, m, 1) == ERROR);
  assert(strcmp(s, "las buenas ideas escasean, si") == 0);
  assert(m[0][0] == -1);
  assert(m[0][1] == -1);
  assert(m[0][2] == -1);
  assert(m[0][3] == -1);
  assert(m[0][4] == -1);

  assert(elimVocales(s, m, 5) == ERROR);
  printf("%s\n", s);
  assert(strcmp(s, "ls bns ds scsan, s") == 0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == -1);

  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  printf("OK!\n");
  return 0;
}
