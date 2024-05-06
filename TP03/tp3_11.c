#include <stdio.h>

int main(void){
  printf("%-8s%-8s%-8s%-8s\n", "N", "10*N", "100*N", "1000*N");
  for(int n = 1; n <= 20; n++)
    printf("%-8d%-8d%-8d%-8d\n", n, n*10, n*100, n*1000);
  return 0;
}
