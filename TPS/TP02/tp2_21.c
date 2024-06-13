#include <stdio.h>
#include <limits.h>

int
main(void) {
   int c = INT_MAX;
   int d;
   d = c + c;
   int e = c + 1;

   printf("c=%d   d=%d   e=%d\n", c, d, e); //c=MAX d=-2 e=MIN
   return 0;
}

//Con el flag -fsanitize=signed-integer-overflow el resultado es el mismo pero marca como error los overflows
