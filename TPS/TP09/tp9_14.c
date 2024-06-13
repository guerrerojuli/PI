#include <stdio.h>
#include <assert.h>

int apareados(const char *texto) {
  if (!*texto)
    return 0;
  int res = apareados(texto + 1);
  if (res > 0) // Si en algun momento quedó positivo es porque encontro un ( que no fue cerrado antes
    return res;
  return (*texto == '(') - (*texto == ')') + res;
}

int main(void) {

  assert(apareados("")==0);
  assert(apareados("()")==0);
  assert(apareados("(())()(()())")==0);
  assert(apareados("((((()))))")==0);

  assert(apareados("(")!=0);
  assert(apareados(")")!=0);
  assert(apareados("(")!=0);
  assert(apareados("())")!=0);
  assert(apareados("()(")!=0);
  assert(apareados("((()))())(")!=0);
  
  int dim=100000;
  char s[dim+1];
  for(int i=0; i<dim/2; i++) {
	  s[i] = '(';
	  s[dim-1-i] = ')';
  }
  s[dim]=0;
  assert(apareados(s)==0);
  for(int i=1; i < dim/100; i++) {
	assert(apareados(s+i)!=0);
  }
  
  puts("OK!");
  return 0;
}
