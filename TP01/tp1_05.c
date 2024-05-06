// #include <stdio.h>
// 
// int
// main(void)
// {
//  		int i, j, max;
//  		i = j = 2;
//  		max = (i>j? I : j ) ;
// 
// 
// 		end
// 	}
// 
// tp1_05.c: In function 'main':
// tp1_05.c:8:29: error: 'I' undeclared (first use in this function)
//     8 |                 max = (i>j? I : j ) ;
//       |                             ^
// tp1_05.c:8:29: note: each undeclared identifier is reported only once for each function it appears in
// tp1_05.c:11:17: error: 'end' undeclared (first use in this function)
//    11 |                 end
//       |                 ^~~
// tp1_05.c:11:20: error: expected ';' before '}' token
//    11 |                 end
//       |                    ^
//       |                    ;
//    12 |         }
//       |         ~
// tp1_05.c:6:27: warning: variable 'max' set but not used [-Wunused-but-set-variable]
//     6 |                 int i, j, max;
//       |                           ^~~

int
main(void)
{
 		int i, j, max;
 		i = j = 2;
 		max = (i > j ? i : j );

		return 0;
}
