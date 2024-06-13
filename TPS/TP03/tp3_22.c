#include <stdio.h>

int main(void){
  int c, anteriorEspacio = 0;
  while((c=getchar()) != '\n'){
    if(anteriorEspacio && c != ' ')
      anteriorEspacio = 0;
    if(!anteriorEspacio)
      putchar(c);
    if(c == ' ')
      anteriorEspacio = 1;
  }
  putchar('\n');

  while((c=getchar()) != '\n'){
    switch(c){
      case '\t': 
        printf("\\t"); 
        break;
      case '\b':
        printf("\\b");
        break;
      case '\\':
        printf("\\");
        break;
      default:
        putchar(c);
    }
  }
  putchar('\n');
  return 0;
}
      
