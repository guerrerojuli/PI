#define N 4

int checkMatriz(int m[][N]) {
  char valida = 1;
  for (int i = 0; i < N && valida; i++) {
    int apariciones[N] = {0};
    for (int j = 0; j < N && valida; i++) {
      int valor = m[i][j];
      if (valor <= N * i || valor > N * i + N || apariciones[(valor % N) - 1])
        valida = 0;
      else
        apariciones[(valor % N) - 1] = 1;
    }
  }
  return valida;
}
