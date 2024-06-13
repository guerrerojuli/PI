int main(void) {
  /* Esto es un primer comentario
   */
  \*Que buen comentario !*\ 
 	/* Es valido /* o no */ este comentario
  ? * / / *Esto es un ultimo comentario * /

  return 0
}

// tp1_01.c: In function 'main':
// tp1_01.c:6:17: error: stray '\' in program
//     6 |                 \* Que buen comentario! *\
//       |                 ^
// tp1_01.c:6:20: error: 'Que' undeclared (first use in this function)
//     6 |                 \* Que buen comentario! *\
//       |                    ^~~
// tp1_01.c:6:20: note: each undeclared identifier is reported only once for each function it appears in
// tp1_01.c:6:23: error: expected ';' before 'buen'
//     6 |                 \* Que buen comentario! *\
//       |                       ^~~~~
//       |                       ;
// tp1_01.c:6:42: warning: backslash and newline separated by space
//     6 |                 \* Que buen comentario! *\
//       |
// tp1_01.c:7:22: warning: "/*" within comment [-Wcomment]
//     7 |         /* Es valido /* o no */  este comentario?  */
//       |
