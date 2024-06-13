#include <stdio.h>

int
main(void)
{
	int c = 2;
	
	c = neg(c);
	printf("%c\n",c);
	return 0;
}
// imprime lo que se espera pero el caracter con ASCII -2 no está definido
