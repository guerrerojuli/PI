#include <stdio.h>

int main(void){
  char c = getchar();
  printf("%s\n", ('a' < c && c < 'z') || ('A' < c && c < 'Z') ? "Es una letra" : "No es una letra");
  return 0;
}
