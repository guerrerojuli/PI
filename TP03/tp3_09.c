#include <stdio.h>

int main(void){

  //1-8
  /*
  int c1, count;
  while ((c1=getchar()) != EOF){
    if (c1 == ' ' || c1 == '\n' || c1 == '\t')
      count++;
  } 
  printf("%d\n", count);
  */

  //1-11
  //el enter da error 

  //1-12
  int c2;
  while ((c2=getchar()) != EOF){
    (c2 == ' ' || c2 == '\n' || c2 == '\t') ? putchar('\n') : putchar(c2);
  }
  return 0;
}
