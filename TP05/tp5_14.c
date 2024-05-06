#include <stdio.h>

typedef unsigned long typeIp;

typeIp generateNetMask(unsigned char bitsNet){
  typeIp mask = 0xFFFFFFFF; 
  for(int i = 0; i < 32 - bitsNet; i++)
    mask <<= 1;
  return mask;
}

void printFormatedIp(typeIp ip){
  int b1, b2, b3, b4;
  b1 = (ip >> 24) & 0xFF;
  b2 = (ip >> 16) & 0xFF;
  b3 = (ip >> 8) & 0xFF;
  b4 = (ip >> 0) & 0xFF;
  printf("%d.%d.%d.%d", b1, b2, b3, b4);
}

void printIp(typeIp ip, unsigned char bitsNet){
  typeIp netMask = generateNetMask(bitsNet);
  typeIp red = ip & netMask;
  typeIp host = ip & (~netMask);
  
  printf("%lX ", ip); 
  printFormatedIp(ip);
  printf(" | %d | ", bitsNet);
  printFormatedIp(red);
  printf(" | ");
  printFormatedIp(host);
  putchar('\n');
}

int main(void){
  printf("IP | bitsNet | Red | Host\n");
  printIp(0xC0A80064, 16);
  printIp(0x10FF1112, 24);
  printIp(0x10FF1112, 23);
  printIp(0x10FF1112, 16);

  return 0;
}
