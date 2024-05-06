#include <stdio.h>

int main(void){
  unsigned char var, var1, var2, var3, var4;
  var = 0xD8;
  var1 = var & 3; //0000 0011
  var2 = (var>>2) & 3;  //0000 1100
  var3 = (var>>4) & 3;  //0011 0000
  var4 = (var>>6) & 3; //1100 0000
  printf("%x %x %x %x\n", var1, var2, var3, var4);
  return 0;
}
