#include <stdio.h>
#include <assert.h>
#include <string.h>

void
eliminaBlancos (char cadena[]);

int main(void) {
  char s[60] = "   "; // cant impar de blancos
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  strcpy(s,"  ");
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);
  
  strcpy(s," . . .  ");
  eliminaBlancos(s);
  assert(strcmp(s, " . . . ")==0);

  strcpy(s,"");
  eliminaBlancos(s);
  assert(strcmp(s, "")==0);

  strcpy(s,"sinblancos");
  eliminaBlancos(s);
  assert(strcmp(s, "sinblancos")==0);



  printf("OK!\n");
  return 0;
}

void eliminaBlancos(char cadena[]) {
  char enEspacios = 0;
  int j = 0;
  for (int i = 0; cadena[i] != '\0'; i++){
    if (cadena[i] != ' ' || !enEspacios){
      enEspacios = (cadena[i] == ' ');
      cadena[j++] = cadena[i];
    }
  }
  cadena[j] = 0;
  
}
