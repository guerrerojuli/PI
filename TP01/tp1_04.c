// #include <stdioh>
// 
// int
// main[void]
// {
//  		int a, b = c = 5
//  		a = b + c
//  		
//  		return: 0
// }
// 
// tp1_04.c:1:10: fatal error: stdioh: No such file or directory
//     1 | #include <stdioh>
//       |          ^~~~~~~~

int
main(void)
{
  int a, b, c;
  b = c = 5;
  a = b + c;

  return 0;
}
