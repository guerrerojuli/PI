#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <time.h>

int aleatorio(int izq, int der){
  int delta = der - izq;
  srand(time(NULL));
  return (delta == 0) ? der : (rand() % delta) + izq;
}

int main(void){

    int rand=aleatorio(1, 10);
    assert(rand<=10 && rand>=1);
    rand=aleatorio(-10, -2);
    assert(rand<=-2 && rand >=-10);
    assert(aleatorio(0,0)==0);
    assert(aleatorio(10,10)==10);
    
    // Solo estamos testeando que caiga dentro del rango, habria que realizar un test
    // mas sofisticado que analizara la desviacion estandar
    for(int i=0; i < 1000; i++) {
        rand = aleatorio(-10, 10);
        assert(rand<=10 && rand >=-10);    
    }

    puts("OK!");
    return 0;
}
