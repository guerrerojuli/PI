#include <stdio.h>
#include <assert.h>

int balance(const char *texto) {
  if (!*texto)
    return 0;
  int valor = 0;
  if (*texto == '(')
    valor = 1;
  if (*texto == ')')
    valor = -1;
  return valor + balance(texto + 1);
}


int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}
