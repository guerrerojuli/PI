#include <stdio.h>
#include <ctype.h>
#include <string.h>


int mcd(int a, int b) {
  if (!b)
    return a;
  return mcd(b, a % b);
}

int isNull(int *v, int dim) {
  if (!dim)
    return 1;
  if (v[dim - 1])
    return 0;
  return isNull(v, dim-1);
}

int isVowel(char c) {
  c = toupper(c);
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int nVowel(const char *s) {
  if (!*s)
    return 0;
  return isVowel(*s) + nVowel(s + 1);
}

int esCapicua(const char *s, int dim){ 
  if (dim <= 1)  
    return 1;
  return (s[0] == s[dim-1] && esCapicua(s+1, dim-2));
}

void imprimirRegla(int n) {
  if(!n)
    return;
  imprimirRegla(n/2);
  printf("%d ", n);
  imprimirRegla(n/2);
}

int branches(float h, float min) {
  if (h < min)
    return 0;
  return 1 + 2*branches(h/2, min);
}

void factorial(int n, int *fact) {
  if (!n) {
    *fact = 1;
    return;
  }
  factorial(n-1, fact);
  *fact *= n;
}

int main(void) {
  int fact;
  factorial(5, &fact);
  printf("%d\n", fact);
  return 0;
}

