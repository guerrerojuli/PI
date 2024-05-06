#define COLS 6

int esPalindromo(int v[], int dim) {
  char espalindromo = 1;
  for (int i = 0, j = dim; i < j && espalindromo; i++, j--)
    if (v[i] != v[j])
      espalindromo = 0;
  return espalindromo;
}

void copiarFila(int v1[], int v2[], int dim) {
  for (int i = 0; i < dim; i++)
    v1[i] = v2[i];
}

int elimina(int m[][COLS], int filas) {
  int j;
  for (int i = 0, j = 0; i < filas; i++) {
    if (!esPalindromo(m[i], COLS)) {
      copiarFila(m[j++], m[i], COLS);
    }
  }
  return j;
}
