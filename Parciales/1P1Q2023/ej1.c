#include <stdio.h>
#include <string.h>
#include <assert.h>

void elimina(char *s1, char *s2, char *s3){
  char terminado2 = 0, terminado3 = 0;  // flags que indican si se termino de recorrer s2 o s3
  int i, j;
  for (i = 0, j = 0; s1[i] != '\0'; i++){
    if (!terminado2 && s2[i] == '\0')
      terminado2 = 1;
    if (!terminado3 && s3[i] == '\0')
      terminado3 = 1;

    if ((terminado2 || s1[i] != s2[i]) && (terminado3 || s1[i] != s3[i]))
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
}

int main(void) {
   char s[] = "abc";
   elimina(s, "123", "cab");
   assert(strcmp(s, "abc") == 0); // No se eliminan caracteres

   elimina(s, "axc", "xbc");
   // Se elimina la a porque está en s2 en la misma posición
   // se elimina la b porque está en s3 en la misma posición
   // Se elimina la c porque está en s2 o en s3 en la misma posición
   assert(strcmp(s, "") == 0);

   char t[] = "abc 123";
   elimina(t, "b", "1");
   assert(strcmp(t, "abc 123") == 0);  // No se eliminan caracteres

   elimina(t, "aaaaaaaaaaaaaaaaaaaaaa", "2222222222222222222");
   assert(strcmp(t, "bc 13") == 0);

   elimina(t, "", "");  // No se eliminan caracteres
   assert(strcmp(t, "bc 13") == 0);

   puts("OK!");
   return 0;
}
