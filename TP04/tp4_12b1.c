#include <stdio.h>

int
main(void)
{
	double i = 5.42;
	
	i = neg(i);
	printf("%f\n",i);
	return 0;
}
// No imprime el resultado esperado porque al no estar el prototio de neg, el compilador hace que la funcion neg reciba y retorne enteros
