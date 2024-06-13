// #include <stdio.h>
// 
// 
// int
// Main(void)
// {
//  		printf ("Estamos escribiendo un mensaje \n")
//  		Return = 0
// }
// 
// tp1_03.c: In function 'Main':
// tp1_03.c:7:61: error: expected ';' before 'Return'
//     7 |                 printf ("Estamos escribiendo un mensaje \n")
//       |                                                             ^
//       |                                                             ;
//     8 |                 Return = 0
//       |                 ~~~~~~
// tp1_03.c:9:1: warning: control reaches end of non-void function [-Wreturn-type]
//     9 | }
//       | ^


#include <stdio.h>


int
main(void)
{
 		printf ("Estamos escribiendo un mensaje \n");
 		return 0;
}
