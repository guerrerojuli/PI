#include <assert.h>
#include <string.h>
#include <ctype.h>

int comprime(char *s, char c, int reps[]){
  char enLetra = 0;
  int i, j, cantRepetidos, dim = 0;
  c = toupper(c);
  for(i = 0, j = 0; s[i] != '\0'; i++){
    char esIgual = toupper(s[i]) == c;
    if (!esIgual || !enLetra){
      if (enLetra)
        reps[dim-1] = cantRepetidos;
      cantRepetidos = 0;
      enLetra = esIgual;
      dim += esIgual;
      s[j++] = s[i];
    } else {
      cantRepetidos++;
    }
  }
  s[j] = '\0';
  return dim;
}

int 
main(void) {
   int reps[100];
   char s[] = "AAA aaaabbaa a b aaaa capital federal";
   int dim;
   dim = comprime(s, 'a', reps);
   assert(strcmp(s, "A abba a b a capital federal")==0);
   assert(dim == 8);
   assert(reps[0] == 2); // se eliminan 2 de "AAA"
   assert(reps[1] == 3); // se eliminan 3 de "aaaa"
   assert(reps[2] == 1); 
   assert(reps[3] == 0); 
   assert(reps[4] == 3); 
   assert(reps[5] == 0); 
   assert(reps[6] == 0); 
   assert(reps[7] == 0); 

   dim = comprime(s, 'x', reps);
   assert(strcmp(s, "A abba a b a capital federal")==0);
   assert(dim == 0);

   char t[] = "AAAaaaa aAaA";
   dim = comprime(t, 'a', reps);
   assert(strcmp(t, "A a")==0);    // Se deja la primer aparición
   assert(dim == 2);
   assert(reps[0] == 6); 
   assert(reps[1] == 3); 

   return 0;
}
